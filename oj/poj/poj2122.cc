#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <limits>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow{
  int N;
  VVL cap, cost, flow;
  VI found;
  VL dist, pi, width;
  VPII dad;
  L cost_limits;

  MinCostMaxFlow(int N):
    N(N), cap(N, VL(N)), cost(N, VL(N)), flow(N, VL(N)),
    found(N), dist(N), pi(N), width(N), dad(N), cost_limits(INF) {}

  void AddEdge(int from, int to, L cap, L cost){
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, L cost, int dir){
    int val = dist[s] + pi[s] - pi[k] + cost;
    if(cap && val < dist[k] && val <= cost_limits){
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t){
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;

    while( s != -1){
      int best = -1;
      found[s] = true;
      for(int k = 0; k < N; k++){
        if(found[k])continue;
        //if(cost[s][k] > cost_limits || cost[k][s] > cost_limits)continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], - cost[k][s], -1);
        if(best == -1 || dist[k] < dist[best])best = k;
      }
      s = best;
    }
    for(int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);

    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t, L max_flow = INF){
    L totflow = 0, totcost = 0;
    while(L amt = Dijkstra(s, t)){
      totflow += amt;
      for( int x = t; x != s; x = dad[x].first){
        if(dad[x].second == 1){
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        }else{
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
      if(totflow >= max_flow)break;
    }

    return make_pair(totflow, totcost);
  }

  void clean(){
    fill(pi.begin(), pi.end(), 0);
    fill(flow.begin(),flow.end(), VL(N));
  }

  L GetMaxCostPath(){
    cout<<"GetMaxCostPath:"<<N<<endl;
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j){
        if(flow[i][j] > 0){
          cout<<i<<" "<<j<<" "<<flow[i][j]<<endl;
        }
      }
    return 0;
  }
};

int main(){
  int K, C, M;
  cin>>K>>C>>M;
  int N = K + C + 2;
  int * dat = (int*)malloc(N*N*sizeof(int));
  int d;
  for(int i = 1; i <= K + C; i++)
    for(int j = 1; j <= K + C; j++){
      cin>>d;
      dat[i*(K+C) + j] = d;
    }

  for(int i = 1; true; ++i){
    MinCostMaxFlow net(N);
    int s = 0, t = N - 1;
    for(int i = 1; i <= K; ++i)
      net.AddEdge(i, t, M, 0);
    for(int i = 1; i <= C; ++i)
      net.AddEdge(s, K + i, 1, 0);


    for(int i = 1; i <= (K+C); i++)
      for(int j = i+1; j <= (K+C); j++){
        d = dat[i*(K+C) + j];
        if(d > 0){
          net.AddEdge(i, j, INF, d);
          net.AddEdge(j, i, INF, d);
        }
      }

    net.cost_limits = i;
    PII res = net.GetMaxFlow(s, t, C);
    if(res.first >= C){
      cout<<i<<endl;
      break;
    }
    net.clean();
  }

  return 0;
}
