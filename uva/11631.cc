#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef int T;
typedef pair<int, int> ii;
typedef pair<T, ii> tii;

vector<int> pset;
int disjoint_nums;
inline void initSet(int N){disjoint_nums = N; pset.resize(N); for(int i = 0 ; i < N; i++)pset[i] = i;}
inline int findSet(int i){ return pset[i] == i ? i : (pset[i] = findSet(pset[i]));}
inline bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
inline void unionSet(int i, int j){if(!isSameSet(i, j))disjoint_nums-- ; pset[findSet(i)] = findSet(j);}
inline int numOfSets(){return disjoint_nums;}

class cmp{
  public:
    bool operator() (tii a, tii b) { return a.first > b.first; }
};

int main(){
  int n,m;
  int x,y,w;
  while(true){
    cin>>n>>m;
    if(n == 0 && m == 0)break;
    priority_queue<tii , vector<tii>, cmp> G; // Edge list repl of graph
    vector<ii> V;
    initSet(n);
    T total = 0;
    for(int k = 0; k < m; k++){
      cin>>x>>y>>w;
      G.push(make_pair(w, make_pair(x, y)));
      total += w;
    }
    initSet(n);
    //MST
    T min_cost = 0;
    while(!G.empty()){
      tii top = G.top();
      //cout<<"Queue:"<<top.first<<" "<<top.second.first<<" "<<top.second.second<<endl;
      if(!isSameSet(top.second.first, top.second.second)){
        min_cost += top.first;
        unionSet(top.second.first, top.second.second);
        //cout<<"Judge:"<<top.first<<" "<<l<<" "<<road<<" "<<railway<<" "<<numOfSets()<<endl;
      }
      G.pop();
    }
    cout<<total - min_cost<<endl;
  }
}
