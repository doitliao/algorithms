#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull area(ull x1, ull y1, ull x2, ull y2) {
  //printf("%llu %llu %llu %llu\n", x1, y1, x2, y2);
  return (x2 - x1) * (y2 - y1);
}

int main(){
  ull n;
  cin>>n;
  n*=2;
  vector<ull> p(n);

  
  for(ull i = 0 ; i < n; i++) {
    cin>>p[i];
  }

  n = p.size();
  ull x1 = 0;
  ull y1 = n / 2;
  ull x2 = n / 2 - 1;
  ull y2 = n - 1;

  //  printf("%llu %llu %llu %llu\n", x1, y1, x2, y2);
  
  
  sort(p.begin(), p.end());
  cout<<area(p[x1], p[y1], p[x2], p[y2])<<endl;
}
