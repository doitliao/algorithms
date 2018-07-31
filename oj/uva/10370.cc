#include <bits/stdc++.h>

using namespace std;

int main(){
  int C,N;

  cin>>C;
  while(C--) {
    cin>>N;
    vector<int> v(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
      cin>>v[i];
      sum += v[i];
    }

    double avg = sum / (double) N;
    int cnt = 0;
    for(auto it : v) {
      if(it > avg) {
	cnt++;
      }
    }
    printf("%.3lf%%\n", cnt * 100 / (double) N);
  }
}
