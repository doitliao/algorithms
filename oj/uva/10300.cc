#include <bits/stdc++.h>

using namespace std;

int main(){
  using ull = unsigned long long;
  int t,n;
  ull x,y,z;
  ull sum = 0;
  cin>>t;
  while(t--){
    cin>>n;
    sum = 0;
    while(n--) {
      cin>>x>>y>>z;
      if(y == 0)continue;
      sum +=  x*z;
    }
    cout<<sum<<endl;
  }
}
