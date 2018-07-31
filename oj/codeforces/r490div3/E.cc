#include <bits/stdc++.h>

using namespace std;

class UnionSet {
public:
  UnionSet(int n):pset(n), data(n, 0), num(n) {
    for(int i = 0; i < n; i++) pset[i] = i;
  }
  vector<int> pset;
  vector<int> data;
  int num;
  int numberOfSets() { return num;}
  int findSet(int i) {
    if(pset[i] == i){
      return i;
    } else {
      int root = findSet(pset[i]);
      data[root] = data[i] = max(data[root], data[i]);
      pset[i] = root;
      return root;
    }
  }
  void unionSet(int i, int j) {
    if(!isSameSet(i, j))num--;
    data[findSet(i)] = data[findSet(j)] = max(data[findSet(i)], data[findSet(j)]);
    pset[findSet(i)] = findSet(j);
  }

  void setData(int i, int d) {
    data[i] = d;
    data[findSet(i)] = d;
  }

  int getData(int i) {
    return data[findSet(i)];
  }
  
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  
};

class AdjGraph {
public:
  AdjGraph(int n) : index(0), ufs(n), adj (n), aux(adj.size(), std::make_tuple(0, 0, false)){}

  void addEdge(int v, int u) {
    adj[v].push_back(u);
  }

  unsigned index;
  stack<int> S;
  void SCCTarjan() {
    // tuple< index, low_link, on_stack>
    for(int i = 0; i < aux.size(); i++) {
      if(get<0>(aux[i]) == 0) {
	strongconnect(i);
      }
    }
  }

  
  void strongconnect(int v) {
    index++;
    aux[v] = std::make_tuple(index, index, true);

    S.push(v);

    for(auto w : adj[v]) {
      if(get<0>(aux[w]) == 0) {
	// Successor w has not yet been visited; recurse on it
	strongconnect(w);
	get<1>(aux[v]) = min(get<1>(aux[v]), get<1>(aux[w]));
      } else if (get<2>(aux[w]) == true) {
	// Successor w is in stack S and hence in the current SCC
        // If w is not on stack, then (v, w) is a cross-edge in the DFS tree and must be ignored
        // Note: The next line may look odd - but is correct.
        // It says w.index not w.lowlink; that is deliberate and from the original paper
	get<1>(aux[v]) = min(get<1>(aux[v]), get<0>(aux[w]));
      }
    }

    if(get<0>(aux[v]) == get<1>(aux[v])) {
      int w;
      do {
	w = S.top(); S.pop();
	get<2>(aux[w]) = false;
	ufs.unionSet(v, w);
      } while(w != v);
    }
  }

  int NumberOf0InDegreeCondensation(int s) {
    int x = 0;
    for(int v = 0; v < adj.size(); v++) {
      for(auto w: adj[v]) {
	if(ufs.isSameSet(v, w))continue;
	ufs.setData(w, 1);
      }
    }

    for(int v = 0; v < adj.size(); v++) {
      if(ufs.getData(v) == 0 && !ufs.isSameSet(s, v)) {
	x++;
	ufs.unionSet(s, v);
      }
    }
    return x;
  }
  
  UnionSet ufs;
  vector<list<int>> adj;
  vector<tuple<int, int, bool>> aux;
};

int main(){
  int n,m,s,v,u;
  cin>>n>>m>>s;
  AdjGraph g(n);

  for(int i = 0; i < m; i++) {
    cin>>v>>u;
    v--;u--;
    g.addEdge(v, u);
  }

  g.SCCTarjan();

  cout<<g.NumberOf0InDegreeCondensation(s-1)<<endl;
}
