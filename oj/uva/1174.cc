#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
      T weight = 0;
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          weight += top.first;
          sets.unionSet(top.second.first, top.second.second);
        }
        G.pop();
      }
      return weight;
    }

    int N;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int t, m, n;
  int x,y,w;
  string from,to;
  bool blank = false;
  cin>>t;
  while(t--){
    cin>>m;
    cin>>n;
    Kruskal G(m);
    int koff = 0;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
      cin>>from>>to>>w;
      if(mp.end() == mp.find(from)){
        mp[from] = koff++;
      }
      if(mp.end() == mp.find(to)){
        mp[to] = koff++;
      }
      x = mp[from];
      y = mp[to];
      G.addEdge(x, y, w);
    }
    if(blank)cout<<endl;
    cout<<G.do_kruskal()<<endl;
    blank = true;
  }
}
