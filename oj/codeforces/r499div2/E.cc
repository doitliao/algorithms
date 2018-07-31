#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned n, k,g, x;
  cin>>n>>k;
  g = 0;
  for(unsigned i = 0; i < n; i++) {
    cin>>x;
    g = std::gcd(g, x);
  }
  g %= k;
  set<unsigned> ans;
  x = 0;
  for(unsigned i = 0, s = 0; i < k; i++, s  = (s + g) % k) {
    ans.insert(s);
  }

  cout<<ans.size()<<endl;
  for(auto i : ans) {
    cout<<i<<" ";
  }
  cout<<endl;
}
