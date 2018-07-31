#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull f(ull n) {
  ull x = 0;
  while(n > 0) {
    x += n % 10;
    n = n / 10;
  }

  return x;
}

ull g(ull n){
  while(n > 9) {
    n = f(n);
  }

  return n;
}

int main(){
  ull n;
  while(true) {
    cin>>n;
    if(n == 0) {
      break;
    }
    cout<<g(n)<<endl;
  }
}
