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
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          sets.unionSet(top.second.first, top.second.second);
          mst[top.second.first].push_back(make_pair(top.second.second, top.first));
          mst[top.second.second].push_back(make_pair(top.second.first, top.first));
        }
        G.pop();
      }
    }

    int N;
  private:
    vector<vector<ii> > mst;
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int n,m,q;
  int x,y,w;
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
  }
}
