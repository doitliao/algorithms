#include <bits/stdc++.h>

using namespace std;

bool query(int x) {
  cout<<x<<endl;
  fflush(stdout);
  cin>>x;
  if(x == 0 || x == -2) {
    exit(0);
  }
  return x == -1;
}

int main(){
  int m, n, s, x;
  cin>>m>>n;
  vector<int> p(n, false);
  for(int i = 0; i < n; i++){
    p[i] = query(m);
  }
  
  // binary search.
  
  int l = 1, r = m - 1;
  for(int i = 0; ; i = (i + 1) % n) {
    int mid = (l + r) / 2;
    x = query(mid);
    if(!p[i]) x = !x;

    if(x) { // large
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
}
