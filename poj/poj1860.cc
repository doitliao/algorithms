#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <limits>
#include <assert.h>
using namespace std;

typedef long double LLD;

struct Edge{
  int from,to,index;
  LLD rate;
  LLD commision;
  Edge(int from, int to, int index, LLD r, LLD c):
    from(from), to(to), index(index), rate(r), commision(c){}
};

struct ExchangeSystem{
  int N;
  vector<vector<Edge> > G;
  vector<bool> visited;
  vector<LLD> currency;
  vector<int> Q;
  ExchangeSystem(int N):N(N), G(N), visited(N), currency(N),Q(N){}
  ~ExchangeSystem(){}

  void AddEdge(int from, int to, LLD r1, LLD c1, LLD r2, LLD c2){
    assert(from < N);
    assert(to < N);
    G[from].push_back(Edge(from, to, G[to].size(), r1, c1));
    if(from == to)G[from].back().index++;
    G[to].push_back(Edge(to, from, G[from].size() - 1, r2, c2));
  }

  bool bellman_ford(int s, LLD c){
    fill(currency.begin(), currency.end(), 0);
    currency[s] = c;
    for(int i = 0; i < N; i++){
      bool flag = false;
      for(int i = 0; i < N; i++){
        for(size_t j = 0; j < G[i].size(); ++j){
          Edge & e = G[i][j];
          double val = (currency[e.from] - e.commision) * e.rate;
          if((val - currency[e.to]) > 1e-10){
            currency[e.to] = val;
            flag = true;
          }
        }
      }
      if(!flag)break;
    }
    for(int i = 0; i < N; i++){
      for(size_t j = 0; j < G[i].size(); ++j){
        Edge & e = G[i][j];
        double val = (currency[e.from] - e.commision) * e.rate;
        if((val - currency[e.to]) > 1e-10){
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(int x, LLD c){
    currency[x] = c;
    visited[x] = true;
    for(size_t i = 0; i < G[x].size(); ++i){
      Edge &e = G[x][i];
      LLD next = (currency[x] - e.commision) * e.rate;
      if(next < 1e-10)continue;
      if(visited[e.to]){
        if((next - currency[e.to]) > 1e-10){
          return true;
        }
      }else{
        bool can = dfs(e.to, next);
        if(!can)continue;
        return true;
      }
    }
    currency[x] = 0;
    visited[x] = false;
    return false;
  }

  bool CanWealther(int s, LLD c){
    fill(visited.begin(), visited.end(), false);
    fill(currency.begin(), currency.end(), 0);
    return dfs(s, c);
  }
};

int main(){
  int M, N, S;
  LLD V;
  cin>>N>>M>>S>>V;
  ExchangeSystem net(N);
  int from, to;
  LLD r1, c1, r2, c2;
  while(M--){
    cin>>from>>to>>r1>>c1>>r2>>c2;
    net.AddEdge(from - 1, to - 1, r1, c1, r2, c2);
  }
  cout<<(net.CanWealther(S - 1, V)?"YES":"NO")<<endl;
  //cout<<(net.bellman_ford(S - 1, V)?"YES":"NO")<<endl;
  return 0;
}
