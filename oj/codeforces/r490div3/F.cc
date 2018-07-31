#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned n, k, x;
  cin>>n>>k;

  map<unsigned, unsigned> cards;
  for(unsigned i = 0; i < n*k; i ++) {
    cin>>x;
    cards[x]++;
  }

  map<unsigned, unsigned> players;
  for(unsigned i = 0; i < n; i++) {
    cin>>x;
    players[x]++;
  }
  
  vector<unsigned> h(k+1, 0);
  for(int i = 1; i <= k; i++) {
    cin>>h[i];
  }

  vector<vector<unsigned> > F(n+1, vector<unsigned>(k*n+1, 0));

  for(unsigned i = 1; i <= n; i++) {
    for(unsigned j = 1; j <= k*n; j++) {
      for(unsigned l = 0; l <= min(j, k); l++) {
	F[i][j] = max(F[i][j], h[l] + F[i-1][j-l]);
      }
    }
  }
  
  unsigned sum = 0;
  for(auto i : cards) {
    unsigned num = i.second;
    unsigned play_num = players[i.first];

    sum += F[play_num][min(num, play_num*k)];
  }

  cout<<sum<<endl;
  
}
