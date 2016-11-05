#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  int m,c;
  int cm = 0, cc = 0;
  while(n--){
    cin>>m>>c;
    if(m > c)cm++;
    if(m < c)cc++;
  }
  if(cm > cc)
    cout<<"Mishka";
  if(cm < cc)
    cout<<"Chris";
  if(cm == cc)
    cout<<"Friendship is magic!^^";
}
