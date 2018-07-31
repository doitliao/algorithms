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

struct Vertex{
  int level;
  int min,max;
  LLD price;
  Vertex():level(0), min(0), max(0), price(0){}
  Vertex(int level, LLD price, int limits):
    level(level), min(level - limits),max(level+limits), price(price){}
};

struct Graph{
  int N;
  vector<Edge> G;
  vector<Vertex> V; // vic.level
  vector<LLD> dist;
  int level_limits;
  Graph(int N):N(N), dist(N){
    fill(dist.begin(), dist.end(), 0);
  }

  void AddEdge(int from, int to, LLD w){
    G.push_back(Edge(from, to, w));
  }

  LLD dfs(int s, LLD cur, LLD length){
    LLD ans = V[s].price;
    int l_min, l_max;
    dist[s] = 1;
    for(size_t j = 0; j < G.size(); j++){
      Edge &e = G[j];
      if(s != e.from || dist[e.to] == 1)continue;
      if(V[e.from].max < V[e.to].level ||
          V[e.from].min > V[e.to].level)continue;
      if(e.weight + length > cur)continue;
      l_min = V[e.to].min;
      l_max = V[e.to].max;
      V[e.to].min = max(V[e.from].min, V[e.to].min);
      V[e.to].max = min(V[e.from].max, V[e.to].max);
      ans = min(dfs(e.to,
            min(V[s].price + length,cur),
            e.weight + length) + e.weight, ans);
      V[e.to].min = l_min;
      V[e.to].max = l_max;
    }
    dist[s] = 0;
    return ans;
  }

  LLD bellman_ford(int s = 0){
    fill(dist.begin(), dist.end(), INF);

    dist[s] = 0;
    for(int i = 0; i < N; i++){
      bool flag = false;
      for(size_t j = 0; j < G.size(); j++){
        Edge &e = G[j];
        if(dist[e.from] == INF)continue;
        if(V[e.from].max < V[e.to].level ||
            V[e.from].min > V[e.to].level)continue;
        LLD val = dist[e.from] + e.weight;
        if(dist[e.to] > val){
          dist[e.to] = val;
          cout<<"WTF:"<<e.from<<" "<<e.to<<" "<<val<<endl;

          V[e.to].min = max(V[e.from].min, V[e.to].min);
          V[e.to].max = min(V[e.from].max, V[e.to].max);
          flag = true;
        }
      }

      if(!flag){
        LLD ans = dist[0] + V[0].price;
        cout<<"GRE:"<<ans<<endl;
        for(int k = 1 ; k < N; k++){
          if(dist[k] == INF)continue;
          cout<<"GRE:"<<ans<<" "<<dist[k]<<" "<<V[k].price<<endl;
          ans = min(ans, dist[k] + V[k].price);
        }
        return ans;
      }
    }
    return 0;
  }
};

int main(){
  int M, N, p, l, x, to, sale;
  cin>>M>>N;
  Graph net(N);
  net.level_limits = M;
  for(int i = 0; i < N; ++i){
    cin>>p>>l>>x;
    net.V.push_back(Vertex(l,p,M));
    while(x--){
      cin>>to>>sale;
      to--;
      net.AddEdge(i, to, sale);
    }
  }

  //cout<<net.bellman_ford(0)<<endl;
  cout<<net.dfs(0, net.V[0].price, 0)<<endl;
  return 0;
}
