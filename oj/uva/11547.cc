#include <bits/stdc++.h>

using namespace std;

int main(){
  int t,i;
  cin>>t;
  while(t--) {
    cin>>i;
    auto fuck = [](int n) {
      n *= 567;
      n /= 9;
      n += 7492;
      n *= 235;
      n /= 47;
      n -= 498;
      n = abs(n);
      n /= 10;
      n %= 10;
      
      return n;
    };

  cout<<fuck(i)<<endl;
  }
}
