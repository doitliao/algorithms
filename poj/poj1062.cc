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

typedef long long LLD;
const LLD INF = numeric_limits<LLD>::max();

struct Edge{
  int from,to;
  LLD weight;
  Edge(int from, int to, LLD w):
    from(from), to(to), weight(w){}
};

struct Graph{
  int N;
  vector<vector<Edge> > G;
  vector<LLD> dist;
  vector<LLD> price;
  vector<int> levels;
  vector<bool> visited;
  int level_limits;
  Graph(int N):N(N), G(N), dist(N), price(N), levels(N), visited(N) {}

  void AddEdge(int from, int to, LLD w){
    G[from].push_back(Edge(from, to, w));
  }

  LLD dfs(size_t s = 0, int l = 0, int r = 0){
    visited[s] = true;
    LLD min_pay = price[s];
    for(size_t i = 0; i < G[s].size(); ++i){
      Edge &e = G[s][i];
      if(visited[e.to])continue;
      int min_l = min(l, levels[e.to]);
      int max_l = max(r, levels[e.to]);
      if(levels[e.to] < l && (l - levels[e.to]) > level_limits){
        continue;
      }
      LLD pay = dfs(e.to, min_l, max_l);
      min_pay = min(min_pay, pay + e.weight);
      cout<<"min_pay:"<<min_pay<<" pay:"<<pay<<" weight:"<<e.weight<<endl;
    }
    visited[s] = false;
    cout<<"DFS:"<<min_pay<<endl;
    return min_pay;
  }
};

int main(){
  int M, N, p, l, x, to, sale;
  cin>>M>>N;
  Graph net(N);
  net.level_limits = M;
  for(int i = 0; i < N; ++i){
    cin>>p>>l>>x;
    net.price[i] = p;
    net.levels[i] = l;
    while(x--){
      cin>>to>>sale;
      to--;
      net.AddEdge(i, to, sale);
    }
  }

  cout<<net.dfs(0, net.levels[0], net.levels[0])<<endl;
  return 0;
}
