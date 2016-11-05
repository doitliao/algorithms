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

  MinCostMaxFlow(int N):
    N(N), cap(N, VL(N)), cost(N, VL(N)), flow(N, VL(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

  void AddEdge(int from, int to, L cap, L cost){
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, L cost, int dir){
    int val = dist[s] + pi[s] - pi[k] + cost;
    if(cap && val < dist[k]){
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
};

L distance_of(PII a, PII b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
  int N, M;
  while(true){
    cin>>N>>M;
    if(N == 0 && M == 0)break;
    vector<pair<int,int> > man;
    vector<pair<int, int> > house;
    for(int i = 0; i < N; i++){
      getchar();
      for(int j = 0; j < M; j++){
        switch(getchar()){
          case 'm':
            man.push_back(make_pair(i, j));
            break;
          case 'H':
            house.push_back(make_pair(i, j));
            break;
        }
      }
    }
    int man_num = man.size();
    int house_num = house.size();
    int N = man_num + house_num + 2;
    MinCostMaxFlow network(N);

    int s = 0, t = N - 1;
    for(size_t i = 0; i < man.size(); i++)
      network.AddEdge(s, i + 1, 1, 0);
    for(size_t i = 0; i < house.size(); i++)
      network.AddEdge(man_num + i + 1, t, 1, 0);
    for(size_t i = 0; i < man.size(); i++){
      for(size_t j = 0; j < house.size(); j++){
        network.AddEdge(i+1, man_num + j + 1, 1, distance_of(man[i], house[j]));
      }
    }

    PII res = network.GetMaxFlow(s,t, man_num);
    //cout<<res.first<<" "<<res.second<<endl;
    cout<<res.second<<endl;

  }
  return 0;
}
