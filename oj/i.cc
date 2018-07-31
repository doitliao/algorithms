#include <bits/stdc++.h>

using namespace std;

template<typename ... S>
auto sum(S... s) {
  return (... + s);
}

int main(){
  cout<<sum(1.2, 3, 4)<<endl;
}
