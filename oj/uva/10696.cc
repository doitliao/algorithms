#include <bits/stdc++.h>

using namespace std;

unsigned f91(unsigned N) {
  if(N <= 100) return f91(f91(N+11));
  return N - 10;
}

int main(){
  unsigned n;
  while(true) {
    cin>>n;
    if(n == 0)break;

    printf("f91(%u) = %u\n", n, f91(n));
  }
}
