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
    T do_kruskal(){
      Disjoint sets(N);
//#define MST 0
#ifdef MST
      mst.resize(N);
#endif
      T weight = 0;
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          weight += top.first;
          sets.unionSet(top.second.first, top.second.second);
#ifdef MST
          mst[top.second.first].push_back(make_pair(top.second.second, top.first));
          mst[top.second.second].push_back(make_pair(top.second.first, top.first));
#endif
        }
        G.pop();
      }
      return weight;
    }

    int N;
  private:
#ifdef MST
    vector<vector<ii> > mst;
#endif
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int n, t, k, m;
  int x,y,w;
  bool blank = false;
  while(true){
    cin>>n;
    if(cin.eof())break;
    Kruskal G(n);
    T org_w = 0;
    t = n -1;
    for(int i = 0; i < t; i++){
      cin>>x>>y>>w;
      org_w += w;
    }
    cin>>k;
    for(int i = 0; i < k; i++){
      cin>>x>>y>>w;
      x--;y--;
      G.addEdge(x, y, w);
    }
    cin>>m;
    for(int i = 0; i < m; i++){
      cin>>x>>y>>w;
      x--;y--;
      G.addEdge(x, y, w);
    }
    if(blank)cout<<endl;
    cout<<org_w<<endl<<G.do_kruskal()<<endl;
    blank = true;
  }
}
