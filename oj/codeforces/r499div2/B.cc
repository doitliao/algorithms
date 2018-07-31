#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned n, m;
  cin>>n>>m;
  map<unsigned, unsigned> v;
  unsigned x;
  for(unsigned i = 0; i < m; i++) {
    cin>>x;
    v[x]++;
  }
  
  vector<unsigned> F(n + 1, 0);

  for(auto i : v) {
    unsigned value = i.second;
    for(unsigned k = n; k >= 1; k--) {
      F[k] = max(value / k, F[k]);
      for(unsigned j = 1; j < k; j++) {
	unsigned tmp = min(value / j, F[k-j]);
	F[k] = max(F[k], tmp);
      }
    }
  }

  cout<<F[n]<<endl;
  return 0;
}
