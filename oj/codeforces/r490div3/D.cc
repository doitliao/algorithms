#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m,k,x;
  unsigned long long cnt = 0;
  cin>>n>>m;

  vector<int> a(n);
  vector<vector<int>> m_idx(m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    a[i] = x;
    m_idx[x%m].push_back(i);
  }

  k = n / m;

  stack<int> s;
  for(int j = 0; j < 2*m; j++){
    int i = j % m;
    while(m_idx[i].size() > k) {
      s.push(m_idx[i].back());
      m_idx[i].pop_back();
    }

    while(m_idx[i].size() < k && !s.empty()) {
      int idx = s.top();
      s.pop();
      m_idx[i].push_back(idx);
      cnt += j - a[idx] % m ;
      a[idx] +=  j - a[idx] % m ;
    }
  }
  cout<<cnt<<endl;
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
