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
    T do_kruskal(int k){
      Disjoint sets(N);

      int num = 0;
      T max_w;
      while(!G.empty()){
        tii top = G.top();
        int s = top.second.first;
        int t = top.second.second;
        T weight = top.first;
        if(!sets.isSameSet(s, t)){
          sets.unionSet(s, t);
          max_w = weight;
          if(++num == k)break;
        }
        G.pop();
      }
      return max_w;
    }

    int N;
    vector<vector<T> > mst;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int s,q;
  int x,y;
  int case_num = 1;
  cin>>case_num;
  while(case_num--){
    cin>>s>>q;
    Kruskal G(q);
    vector<ii> V;
    for(int k = 0; k < q; k++){
      cin>>x>>y;
      for(size_t i = 0; i < V.size(); i++){
        double w = sqrt((double)((x - V[i].first)*(x - V[i].first) + (y - V[i].second)*(y - V[i].second)));
        G.addEdge(i, k, w);
      }
      V.push_back(make_pair(x, y));
    }

    printf("%.2lf\n", G.do_kruskal(q - s));
  }
}
