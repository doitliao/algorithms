#include <iostream>
#include <cmath>

using namespace std;

int main(){
  unsigned n;
  int x,p,y;
  cin>>n;
  p = -1e6 - 1;
  while(n--){
    cin>>x; 
    if(x < p)continue;
    y = sqrt(x);
    if(x == (y*y))continue;
    
    p = x;
  }
  cout<<p<<endl;

}
