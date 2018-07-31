#include <bits/stdc++.h>

using namespace std;

bool query(int x) {
  cout<<x<<endl;
  fflush(stdout);
  cin>>x;
  if(x == 0 || x == -2) {
    exit(0);
  }
  return x == 1;
}

int main(){
  int m, n, s, x;
  cin>>m>>n;
  vector<int> p(n, false);
  for(int i = 0; i < n; i++){
    cout<<m<<endl;
    fflush(stdout);
    scanf("%d", &x);
    if(x == 0) {
      exit(0);
    }
    if(x == -2) {
      exit(0);
    }
    
    if(x < 0) {
      p[i] = true;
    }
  }
  // binary search.
  
  int l = 1, r = m;
  int i = 0;
  while(l <= r) {
    int mid = (l + r) / 2;
    cout<<mid<<endl;
    fflush(stdout);
    scanf("%d", &x);
    if(x == 0) {
      exit(0);
    }

    if(x == -2) {
      exit(0);
    }
    
    if(p[i] == false) { //  answered correctly
      if( x > 0) {
	r = mid - 1;
      }else {
	l = mid + 1;
      }
    } else { // answered incorrectly
      if( x < 0) {
	r = mid - 1;
      }else {
	l = mid + 1;
      }
    }

    i = (i+1) % n;
  }
}
