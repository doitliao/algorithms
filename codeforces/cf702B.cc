#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int n;
  std::vector<uint64_t> array;
  std::map<uint64_t, uint32_t> m;
  cin>>n;
  uint64_t x;
  uint64_t sum = 0;
  uint64_t cnt = 0;
  for(int i = 0; i < n; i++){
    cin>>x;
    array.push_back(x);
    m[x] ++;
  }
  for(auto it = array.begin(); it != array.end(); it++){
    for(int i = 1; i < 32; i++){
      uint64_t cur = (1<<i)  - *it;
      cnt += m[cur];
      if(cur == *it)cnt -= 1;
    }
  }

  cout<<cnt/2<<endl;
}
