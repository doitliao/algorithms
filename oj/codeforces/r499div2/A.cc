#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  string x;
  cin>>x;

  sort(x.begin(), x.end());
  unsigned sum = 0;
  char prev = 0;
  for(int i = 0; k > 0 && i < x.length(); i++){
    if((x[i] - prev) < 2 ) {
      continue;
    }
    prev = x[i];
    sum += x[i] - 'a' + 1;
    k--;
  }
    
  if (k == 0) cout<<sum<<endl;
  else cout<<"-1"<<endl;
}
