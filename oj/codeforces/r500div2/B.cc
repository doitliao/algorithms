#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned n, x;
  cin>>n>>x;
  set<unsigned> s;
  set<unsigned> p;

  unsigned t;
  for(unsigned i = 0; i < n; i++) {
    scanf("%u", &t);
    s.insert(t);
    p.insert(t & x);
  }

  if(s.size() != n){
    printf("0\n");
    return 0;
  }
  
  for(auto i : s) {
    if(((i&x) != i ) && s.find(i&x) != s.end()) {
      printf("1\n");
      return 0;
    }
  }

  if(p.size() != n) {
    printf("2\n");
    return 0;
  }
  
  printf("-1\n");
  
}
