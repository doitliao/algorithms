#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef int T;
typedef pair<int, int> ii;
typedef pair<T, ii> tii;

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
      T min_cost = 0;
      bool is_forest = true;
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          min_cost += top.first;
          sets.unionSet(top.second.first, top.second.second);
        }else{
          if(!is_forest)cout<<" ";
          cout<<top.first;
          is_forest = false;
        }
        G.pop();
      }
      if(is_forest)cout<<"forest";
      cout<<endl;
    }
    int N;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int n,m;
  int x,y,w;
  while(true){
    cin>>n>>m;
    if(n == 0 && m == 0)break;
    Kruskal G(n);
    for(int k = 0; k < m; k++){
      cin>>x>>y>>w;
      G.addEdge(x, y, w);
    }
    G.do_kruskal();
  }
}
