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
      T total_w = 0;
      bool is_zero = false;
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          if(top.second.first == 0 || top.second.second == 0){
            if(is_zero){
              G.pop();
              continue;
            }
            else is_zero = true;
          }
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
  int a, b, c, d;
  K(int i){
    d = i % 10;i /= 10;
    c = i % 10;i /= 10;
    b = i % 10;i /= 10;
    a = i % 10;i /= 10;
  }
};

int main(){
  int t,n;
  int x;
  cin>>t;
  while(t--){
    cin>>n;
    Kruskal G(n + 1);
    vector<K> V;
    V.push_back(K(0));
    for(int k = 1; k <= n; k++){
      cin>>x;
      V.push_back(K(x));
      for(int i = 0; i < k; i++){
        int a = abs(V[i].a - V[k].a);
        int b = abs(V[i].b - V[k].b);
        int c = abs(V[i].c - V[k].c);
        int d = abs(V[i].d - V[k].d);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
        T w = min(a, 10 - a) + min(b, 10 - b) +min(c, 10 - c) + min(d, 10 - d);
        //cout<<i<<" "<<k<<" "<<w<<endl;
        G.addEdge(i, k, w);
      }
    }
    cout<<G.do_kruskal()<<endl;
  }
}
