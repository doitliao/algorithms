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
  int from,to;
  LLD weight;
  Edge(int from, int to, LLD w):
    from(from), to(to), weight(w){}
};

struct BellmanFord{
  int N;
  vector<Edge> G;
  vector<LLD> dist;
  BellmanFord(int N):N(N), dist(N) {}

  void AddEdge(int from, int to, LLD w){
    G.push_back(Edge(from, to, w));
  }

  bool Run(int s = 0){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    for(int i = 0; i < N; i++){
      bool flag = false;
      for(size_t j = 0; j < G.size(); ++j){
        Edge & e = G[j];
        if(dist[e.from] == INF)continue; //eq.
        double val = dist[e.from]  + e.weight;
        if(dist[e.to] > val){ //gt
          dist[e.to] = val;
          flag = true;
        }
      }

      if(!flag)return true;
      if(i == (N - 1))return false;
    }
    assert(false);
    return false;// unreachable end.
  }
};

int main(){
  int t, M, N, W;
  int s,e;
  LLD w;
  cin>>t;
  while(t--){
    cin>>N>>M>>W;
    BellmanFord net(N);
    while(M--){
      cin>>s>>e>>w;
      s--;e--;
      net.AddEdge(s, e, w);
      net.AddEdge(e, s, w);
    }
    while(W--){
      cin>>s>>e>>w;
      s--;e--;
      net.AddEdge(s, e, -w);
    }
    cout<<(net.Run()?"NO":"YES")<<endl;
  }
  return 0;
}
