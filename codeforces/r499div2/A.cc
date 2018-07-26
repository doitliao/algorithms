#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  string x;
  cin>>x;

  sort(x.begin(), x.end());
  unsigned sum = x[0] - 'a' + 1;
  map<char,bool> v;
  for(char c = 'a'; c <= 'z' ; c++) {
    v[c] = false;
  }
  v[x[0]] = true;
  k--;
  for(int i = 1; i < x.length(); i++){
    if(k == 0)break;
    if( (x[i] - x[i-1]) < 2 && v[x[i-1]] == true) {
        continue;
    }
    v[x[i]] = true;
    sum += x[i] - 'a' + 1;
    k--;
  }
  
  if (k == 0) cout<<sum<<endl;
  else cout<<"-1"<<endl;
}
