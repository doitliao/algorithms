#include <bits/stdc++.h>

using namespace std;

int main(){
  const unsigned mod = 1e9 + 1;

  vector<unsigned> powOfTwo(1e6);
  powOfTwo.push_back(1);
  for(int i = 1; i <= 1e6; i++) {
    powOfTwo[i] = powOfTwo[i-1] * 2 % mod;
  }

  unsigned N = 1e6 + 31;
  vector<vector<unsigned> > cbn(N, vector<unsigned>(31, 0));

  for(int i = 1; i < cbn.size(); i++) {
    cbn[i][1] = i;
  }

  for(int i = 1; i < cbn.size(); i++) {
    for(int j = 2; j <= cbn[i].size() && j <= i; j++) {
      if(i == j) {
	cbn[i][j] = 1;
      }else {
	cbn[i][j] = (cbn[i-1][j] + cbn[i-1][i-1]) % mod;
      }

      //printf("(%d, %d) = %u\n", i, j, cbn[i][j]);
    }
  }

  cout<<cbn[6][1]<<endl;
  
  cout<<cbn[6][2]<<endl;
  
  cout<<cbn[1e6][5]<<endl;
  
  cout<<mod<<endl;
  
}
