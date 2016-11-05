#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  std::vector<uint64_t> v;
  uint64_t x;
  uint64_t sum = 0;
  uint64_t cnt = 0;
  cin>>x;
  v.push_back(x);
  cnt += x;
  for(int i = 1; i < n; i++){
    cin>>x;
    v.push_back(x);
    cnt += x;
    sum += v[i-1] * v[i];
  }

  sum += v[n-1] * v[0];
  int p,q, prev = -1;
  bool zero = false;
  uint64_t tmp = 0;
  for(int i = 0; i < k; i++){
    cin>>x;
    x -= 1;
    p = (x + 1) % n;
    q = (x - 1 + n) % n ;
    tmp = cnt - v[x]; 
    if(prev != q)
      tmp -= v[q];
    if(!(p == 0 && zero))
      tmp -= v[p];
    sum += v[x] * tmp;
    cnt -= v[x];
    prev = x;
    if( x == 0)zero = true;
  }

  cout<<sum<<endl;
}
