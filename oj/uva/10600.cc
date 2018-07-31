#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace std;

typedef double T;
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

      T mst_w = 0;
      T smst_w = 0;
      while(!G.empty()){
        tii top = G.top();
        int s = top.second.first;
        int t = top.second.second;
        T weight = top.first;
        if(!sets.isSameSet(s, t)){
          sets.unionSet(s, t);
          mst_w += weight;
          mst.push_back(top);
        }else nomst.push_back(top);
        G.pop();
      }
      smst_w = INF;
      for(size_t i = 0; i < mst.size(); i++){
        sets.initSet(N); // recreate disjoint.
        for(size_t j =0; j < mst.size(); j++){
          if(i == j)continue;
          tii& top = mst[j];
          int s = top.second.first;
          int t = top.second.second;
          sets.unionSet(s, t);
        }
        for(size_t j =0; j < nomst.size(); j++){
          tii& top = nomst[j];
          int s = top.second.first;
          int t = top.second.second;
          if(!sets.isSameSet(s, t)){
            smst_w = min(smst_w, mst_w - mst[i].first + nomst[j].first);
            break;
          }
        }
      }
      cout<<mst_w<<" "<<smst_w<<endl;
    }

    int N;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
    vector<tii > nomst; // the edge not in MST.
    vector<tii > mst; // the edge not in MST.
};

int main(){
  int N,M;
  int x,y;
  T w;
  int case_num = 1;
  cin>>case_num;
  while(case_num--){
    cin>>N>>M;
    Kruskal G(N);
    for(int k = 0; k < M; k++){
      cin>>x>>y>>w;
      x--;y--;
      G.addEdge(x, y, w);
    }

    G.do_kruskal();
  }
}
