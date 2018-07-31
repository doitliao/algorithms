#include <iostream>
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

    T do_kruskal(){
      Disjoint sets(N);
      T total_w = 0;
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          total_w += top.first;
          sets.unionSet(top.second.first, top.second.second);
        }
        G.pop();
      }
      return total_w;
    }

    int N;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

struct K{
  T x,y;
  K(T x, T y):x(x),y(y){}
};

int main(){
  int t,n;
  T x, y;
  cin>>t;
  bool blank = false;
  while(t--){
    cin>>n;
    Kruskal G(n + 1);
    vector<K> V;
    for(int k = 0; k < n; k++){
      cin>>x>>y;
      V.push_back(K(x, y));
      for(int i = 0; i < k; i++){
        T w = sqrt((V[i].x - V[k].x)*(V[i].x - V[k].x)
            + (V[i].y - V[k].y)*(V[i].y - V[k].y));
        G.addEdge(i, k, w);
      }
    }
    if(blank)cout<<endl;
    printf("%.2lf\n", G.do_kruskal());
    blank = true;
  }
}
