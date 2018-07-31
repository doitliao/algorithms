#include <bits/stdc++.h>

using namespace std;

int main(){
  size_t N;
  while(true){
  cin>>N;
  if(cin.eof())break;
  vector<vector<int>> inp(N, vector<int>(N));
  vector<vector<int>> sum(N, vector<int>(N));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin>>inp[i][j];
      sum[i][j] = 0;
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      // i,j = i-1,j + i,j-1 - i-1, j-1
      sum[i][j] = inp[i][j];
      if(i > 0) {
	sum[i][j] += sum[i-1][j];
      }

      if(j >0) {
	sum[i][j] += sum[i][j-1];
      }

      if(i > 0 && j > 0) {
	sum[i][j] -= sum[i-1][j-1];
      }
    }
  }

  int max_sum = sum[0][0];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      max_sum = max(sum[i][j], max_sum);
      for(int k = 0; k < i; k++) {
	max_sum = max(max_sum, sum[i][j] - sum[k][j]);
      }
      for(int l = 0; l < j; l ++){
	max_sum = max(max_sum, sum[i][j] - sum[i][l]);
      }
      
      for(int k = 0; k < i; k++) {
	for(int l = 0; l < j; l++) {
	  max_sum = max(sum[i][j] - sum[i][l] - sum[k][j] + sum[k][l], max_sum);
	}
      }
    }
  }

  cout<<max_sum<<endl;
  }
}
