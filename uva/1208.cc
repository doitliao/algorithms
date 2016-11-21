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
    bool operator() (tii a, tii b) { return a.first != b.first ? a.first > b.first :
      a.second.first != b.second.first? a.second.first > b.second.first : a.second.second > b.second.second; }
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
      while(!G.empty()){
        tii top = G.top();
        if(!sets.isSameSet(top.second.first, top.second.second)){
          sets.unionSet(top.second.first, top.second.second);
          cout<<(char)(top.second.first + 'A')<<"-"<<(char)('A'+top.second.second)<<" "<<top.first<<endl;
        }
        G.pop();
      }
    }

    int N;
  private:
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
};

int main(){
  int n,t;
  int x,y,w;
  cin>>t;
  for(int test = 1; test <= t; test++){
    cin>>n;
    Kruskal G(n);
    char con;
    for(x = 0; x < n; x++){
      for(y = 0; y < n ; y++){
        if(y!=0)cin>>con;
        cin>>w;
        if(x > y || w == 0)continue;
        G.addEdge(x, y, w);
      }
    }
    cout<<"Case "<<test<<":"<<endl;
    G.do_kruskal();
  }
}
