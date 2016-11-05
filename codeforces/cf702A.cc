#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  uint64_t x;
  cin>>x;
  uint64_t prev = x;
  n--;
  int maxlen = 1;
  int tmplen = 1;
  while(n--){
    cin>>x;
    if(prev >= x){
      if(maxlen < tmplen){
        maxlen = tmplen;
      }
      tmplen = 0;
    }
    prev = x;
    tmplen++;
  }
  if(maxlen < tmplen)maxlen = tmplen;

  cout<<maxlen<<endl;
}
