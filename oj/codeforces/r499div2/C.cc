#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin>>n>>m;
  vector<unsigned> a(2*n);

  for(int i = 0; i < n; i++) cin>>a[2*i];
  for(int i = 0; i < n; i++) cin>>a[2*i + 1];

  double total = m;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == 1){
      cout<<"-1"<<endl;
      return 0;
    }
    total += total / (a[i] - 1);
  }
  printf("%.10lf\n", total - m);

}
