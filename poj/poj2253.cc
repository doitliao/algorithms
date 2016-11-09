#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <limits>
#include <assert.h>
#include <iomanip>
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

  LLD Run(int s = 0){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    for(int i = 0; i < N; i++){
      bool flag = false;
      for(size_t j = 0; j < G.size(); ++j){
        Edge & e = G[j];
        if(dist[e.from] == INF)continue; //eq.
        double val = max(dist[e.from], e.weight);
        if(dist[e.to] > val){ //gt
          dist[e.to] = val;
          flag = true;
        }
      }

      if(!flag)return dist[1];
      if(i == (N - 1))return false;
    }
    assert(false);
    return false;// unreachable end.
  }
};

struct Coord{
  int x,y;
  Coord(){}
  Coord(int x, int y):x(x), y(y){}
};

int main(){
  int N,scenario;
  scenario = 1;
  while(true){
    cin>>N;
    if(N == 0)break;
    vector<Coord> pt(N);
    for(int i = 0; i < N; i++){
      cin>>pt[i].x>>pt[i].y;
    }
    BellmanFord net(N);
    for(int i = 0; i < N; i++){
      for(int j = i + 1; j< N; j++){
        LLD d = (pt[i].x - pt[j].x)*(pt[i].x - pt[j].x) + (pt[i].y - pt[j].y)*(pt[i].y - pt[j].y);
        net.AddEdge(i, j, d);
        net.AddEdge(j, i, d);
      }
    }
    double ans = sqrt(net.Run(0));
    printf("Scenario #%d\n",scenario++);
    printf("Frog Distance = %.3f\n\n",ans);
    //cout<<"Scenario #"<<scenario<<endl;
    //cout<<"Frog Distance = "<<setiosflags(ios::fixed)<<setprecision(3) <<ans<<endl<<endl;
  }
  return 0;
}
