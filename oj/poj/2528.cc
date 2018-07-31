//#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<stack>

using namespace std;

unsigned normalize(vector<unsigned> &a) {
  vector<unsigned> b(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  b.erase(std::unique(b.begin(), b.end()), b.end());

  for(int i = 0; i < a.size(); ++i) {
    a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }

  return b.size();
}

int main(){
  int t;
  cin>>t;
  while(t--) {
    int n;
    scanf("%d", &n);
    vector<unsigned> v(2*n);
    for(int i = 0; i < 2* n; i++){
      scanf("%d", &v[i]);
    }
    unsigned size = normalize(v);
    vector<unsigned> w(size);
    for(int i = 0; i < n; i++) {
      for(int j = v[2*i]; j <= v[2*i + 1] ; j++) {
	w[j] = i;
      }
    }

    size = normalize(w);
    cout<<size<<endl;
  }
}
