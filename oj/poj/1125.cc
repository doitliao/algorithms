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

typedef int LLD;
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

  void Run(){
    fill(dist.begin(), dist.end(), 0);
    Edge* e = &G[0];
    for(size_t j = 1; j < G.size(); ++j){
      if(G[j].weight < e->weight)e = &G[j];
    }

    dist[e->from] = dist[e->to] = 1;
    int s = e->from;

    LLD sum = e->weight;
    for(int i = 1; i < N; i++){
      bool flag = false;
      e = NULL;
      for(size_t j = 0; j < G.size(); ++j){
        if((1 == dist[G[j].from] && 0 == dist[G[j].to])|| (G[j].to == s && dist[G[j].from] == 0)){
          if(e == NULL || e->weight > G[j].weight) e = &G[j];
          flag = true;
        }
      }

      if(flag){
        cout<<"GRB:"<<s<<" "<<sum<<endl;
        if(s == e->to){
          s = e->from;
          dist[e->from] = 1;
        }else{
          dist[e->to] = 1;
        }
        sum += e->weight;
        cout<<"wtf:"<<s<<" "<<sum<<endl;
      }else{
        if(i != (N - 1)){
          cout<<"disjoint"<<endl;
          return;
        }
        cout<<s<<" "<<sum<<endl;
        return;

      }
    }

    cout<<s<<" "<<sum<<endl;
  }
};

int main(){
  int N,t,a,w;
  while(true){
    cin>>N;
    if(N == 0)break;
    BellmanFord net(N);
    for(int i = 0; i < N; i++){
      cin>>t;
      while(t--){
        cin>>a>>w;
        a--;
        net.AddEdge(i, a, w);
      }
    }
    net.Run();
  }
  return 0;
}
