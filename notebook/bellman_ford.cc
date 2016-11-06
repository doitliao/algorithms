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
const LLD INF = numeric_limits<LLD>::max();
struct Edge{
  int from,to,index;
  LLD weight;
  Edge(int from, int to, int index, LLD w):
    from(from), to(to), index(index), weight(w){}
};

struct BellmanFord{
  int N;
  vector<vector<Edge> > G;
  vector<LLD> dist;
  BellmanFord(int N):N(N), G(N), dist(N){}

  void AddEdge(int from, int to, LLD w1, LLD w2){
    assert(from < N);
    assert(to < N);
    G[from].push_back(Edge(from, to, G[to].size(), w1));
    if(from == to)G[from].back().index++;
    G[to].push_back(Edge(to, from, G[from].size() - 1, w2));
  }

  bool Run(int s){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    for(int i = 0; i < N; i++){
      bool flag = false;
      for(int i = 0; i < N; i++){
        for(size_t j = 0; j < G[i].size(); ++j){
          Edge & e = G[i][j];
          if((dist[e.from] - INF) < 1e-10)continue; //eq.
          double val = dist[e.from]  + e.weight;
          if((dist[e.to] - val) > 1e-10){ //gt
            dist[e.to] = val;
            flag = true;
          }
        }
      }
      if(!flag)break;
    }
    for(int i = 0; i < N; i++){
      for(size_t j = 0; j < G[i].size(); ++j){
        Edge & e = G[i][j];
        double val = dist[e.from]  + e.weight;
        if((dist[e.to] - val) > 1e-10){
          return false;
        }
      }
    }
    return true;
  }
};

int main(){
  int N = 10;
  BellmanFord net(N);
  net.AddEdge(0, 2, 3.0, - 5.0);
  cout<<net.Run(0)<<endl;
  return 0;
}
