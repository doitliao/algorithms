#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair<int, int> ii;
typedef pair<double, ii> dii;

vector<int> pset;
int disjoint_nums;
inline void initSet(int N){disjoint_nums = N; pset.resize(N); for(int i = 0 ; i < N; i++)pset[i] = i;}
inline int findSet(int i){ return pset[i] == i ? i : (pset[i] = findSet(pset[i]));}
inline bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
inline void unionSet(int i, int j){if(!isSameSet(i, j))disjoint_nums-- ; pset[findSet(i)] = findSet(j);}
inline int numOfSets(){return disjoint_nums;}

class cmp{
  public:
    bool operator() (dii a, dii b) { return a.first > b.first; }
};

int main(){
  int t;
  cin>>t;
  int n,l;
  int x,y;
  for(int i = 1; i <= t; i++){
    cin>>n>>l;
    priority_queue<dii , vector<dii>, cmp> G; // Edge list repl of graph
    vector<ii> V;
    initSet(n);
    for(int k = 0; k < n; k++){
      cin>>x>>y;
      for(size_t j = 0; j < V.size(); j++){
        double dist = sqrt((double)((x - V[j].first) * (x - V[j].first) + (y - V[j].second) * (y - V[j].second) ));
        if(dist <= l)unionSet(k,j);
        G.push(make_pair(dist, make_pair(k, j)));
      }
      V.push_back(make_pair(x, y));
    }
    int states = numOfSets();
    //cout<<"NumOfSate:"<<states<<endl;
    initSet(n);
    vector<bool> pi(n);
    //MST
    double road = 0, railway = 0;
    while(!G.empty()){
      dii top = G.top();
      //cout<<"Queue:"<<top.first<<" "<<top.second.first<<" "<<top.second.second<<endl;
      if(!isSameSet(top.second.first, top.second.second)){
        if(top.first <= (double)l)road += top.first;
        else railway += top.first;
        unionSet(top.second.first, top.second.second);
        //cout<<"Judge:"<<top.first<<" "<<l<<" "<<road<<" "<<railway<<" "<<numOfSets()<<endl;
      }
      G.pop();
    }
    cout<<"Case #"<<i<<": "<<states<<" "<<(int)round(road)<<" "<<(int)round(railway)<<endl;
  }
}
