#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n,d;
  cin>>n>>d;
  ll max_sum = 0,  sum = 0, prev_max = 0;
  bool prev = false;
  int cnt = 0;
  
  int t;
  for(int i = 0, s = 0; i < n; i++) {
    scanf("%d", &t);
    if(t!=0) {
      sum += t;
      max_sum = max(max_sum, sum);
      if(max_sum > d) {
	cout<<"-1"<<endl;
	return 0;
      }
    } else {
      if(sum < 0) {
	if(prev && (d - max(prev_max, max_sum)) >= abs(sum)) {
	  prev_max = max(prev_max, max_sum) + abs(sum);
	  sum = 0;
	  max_sum = 0;
	}else{
	  prev_max = 0;
	  sum = max_sum = 0;
	  prev = true;
	  cnt++;
	}
      }
    }
  }
  
  cout<<cnt<<endl;
}
