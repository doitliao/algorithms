#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace std;

typedef int T;
const T INF = numeric_limits<T>::max();
typedef pair<int, int> ii;
typedef pair<T, ii> tii;
typedef pair<ii, T> iit;

class cmp{
  public:
    bool operator() (tii a, tii b) { return a.first > b.first; }
};

class Disjoint{
  public:
    Disjoint(int n){initSet(n);}
    inline void initSet(int N){disjoint_nums = N; pset.resize(N); for(int i = 0 ; i < N; i++)pset[i] = i;}
    inline int findSet(int i){ return pset[i] == i ? i : (pset[i] = findSet(pset[i]));}
    inline bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
    inline void unionSet(int i, int j){if(!isSameSet(i, j))disjoint_nums-- ; pset[findSet(i)] = findSet(j);}
    inline int numOfSets(){return disjoint_nums;}
  private:
    vector<int> pset;
    int disjoint_nums;
};

class Kruskal{
  public:
    Kruskal(int n):N(n){}
    void addEdge(int from, int to, T weight){
      G.push(make_pair(weight, make_pair(from, to)));
    }
    void do_kruskal(){
      Disjoint sets(N);
      mst.resize(N);
      for(int i = 0; i < N; i++){
        mst[i].resize(N);
        fill(mst[i].begin(), mst[i].end(), -1);
      }

      while(!G.empty()){
        tii top = G.top();
        int s = top.second.first;
        int t = top.second.second;
        T weight = top.first;
        if(!sets.isSameSet(s, t)){
          mst[s][t]=mst[t][s] = weight;
          for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
              if(sets.isSameSet(i, s) && sets.isSameSet(j, t)){
                mst[i][j] = max(max(mst[i][s],mst[j][t]), mst[s][t]);
                mst[j][i] = mst[i][j];
              }
            }
          }
          sets.unionSet(s, t);
        }
        G.pop();
      }
    }

    int N;
    vector<vector<T> > mst;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int n,m,q;
  int x,y,w;
  int case_num = 1;
  bool blankline = false;
  while(true){
    cin>>n>>m>>q;
    if(n == 0 && m == 0 && q == 0)break;
    Kruskal G(n);
    for(int k = 0; k < m; k++){
      cin>>x>>y>>w;
      x--;y--;
      G.addEdge(x, y, w);
    }
    G.do_kruskal();
    if(blankline)
      cout<<endl;
    cout<<"Case #"<<case_num++<<endl;
    while(q--){
      cin>>x>>y;
      x--;y--;
      if(G.mst[x][y] == -1)
        cout<<"no path"<<endl;
      else
        cout<<G.mst[x][y]<<endl;
    }
    blankline = true;
  }
}
