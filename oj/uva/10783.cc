#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin>>t;
  unsigned a,b;
  for(int i = 1; i <= t; i++) {
    cin>>a>>b;
    if(a&1) a = a - 1;

    if(b&1) b = b + 1;

    a /= 2;
    b /= 2;

    
    cout<<"Case "<<i<<": "<<b*b - a*a<<endl;
    
  }
}
