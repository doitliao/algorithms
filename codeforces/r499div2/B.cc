#include <iostream>
#include <map>
#include <vector>
#include <tuple>
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
    
    vector<tuple<unsigned, unsigned> > s;
    for(auto i : v) {
        s.push_back(make_tuple(i.first, i.second));
    }

    // F[i, k] = Max(Vi / j + F(i-1, n - j))
    vector<vector<unsigned> > F(s.size(), vector<unsigned>(n+1, 0));    

    for(int i = 0;  i < s.size(); i++) {
      unsigned value = get<1>(s[i]);
      for(int k = 1; k <= n; k++) {
	F[i][k] = value / k;
      }
    }
    for(int i = 1;  i < s.size(); i++) {
      unsigned value = get<1>(s[i]);
      for(int k = 1; k <= n; k++){
	F[i][k] = max(F[i-1][k], F[i][k]);
	for(int j = 1; j < k; j++) {
	  F[i][k] = max(F[i][k], min(F[i-1][k-j], value / j));
	}
      }
    }
    cout<< F[s.size()-1][n]<<endl;
}
