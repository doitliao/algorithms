// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
// Running time:
//    O(|V|^2 |E|)
// INPUT:
//    - graph, constructed using AddEdge()
//    - source
//    - sink
//
// OUTPUT:
//    - maximum flow
//    - To obain the actual flow values, look at all edges with
//      capacity > 0 (zero capacity edges are residual edges).

#include <cmath>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 2147483647;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index){}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N):N(N), G(N), dad(N), Q(N){}

  void AddEdge(int from, int to, int cap){
    /*
    for(int i = 0; i < G[from].size(); i++){
      Edge * start = &G[from][i];
      if(start->to == to && start->cap > 0){
        cout<<"dual:"<<from<<"->"<<to<<endl;
        start->cap += cap;
        return;
      }
    }
    */
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if(from == to)G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t){
    fill(dad.begin(), dad.end(), (Edge*)NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while(head < tail){
      int x = Q[head++];
      for(size_t i = 0; i < G[x].size(); i++){
        Edge &e = G[x][i];
        if(!dad[e.to] && (e.cap - e.flow) > 0){
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }

    if(!dad[t]){
      return 0;
    }

    long long totflow = 0;
    for(size_t i = 0; i < G[t].size(); i++){
      Edge * start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]){
        if(!e){amt = 0; break;}
        amt = min(amt, e->cap - e->flow);
      }
      if(amt == 0){
        continue;
      }
      for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]){
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t){
    long long totflow = 0;
    while(long long flow = BlockingFlow(s, t)){
      totflow += flow;
    }
    return totflow;
  }
};

int main(){
  int M,N;
  while(true){
    cin>>M>>N;
    if(cin.eof())break;
    Dinic dinic(N);
    int from, to, cap;
    while(M--){
        cin>>from>>to>>cap;
        from--;
        to--;
        dinic.AddEdge(from, to, cap);
    }

    cout<<dinic.GetMaxFlow(0, N-1)<<endl;
  }

  return 0;
}
