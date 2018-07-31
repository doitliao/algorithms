#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

vector<ull> primes;

ull get_max_factor(ull x) {
  ull ele = 1;
  for(auto i : primes) {
    if(i > x) break;
    if((x % i) == 0) {
      ele = i;
      while(0 == (x%i)){
	x /= i;
      }
    }
  }
  return ele;
}

ull f(ull i) {
  return max(get_max_factor(i+1), get_max_factor(i*i - i + 1)) - 1;
}

int main(){
  vector<ull> all(2000000, 0);
  for(int i = 2; i < 2000000; i++) {
    if(all[i] == 0) {
      primes.push_back(i);
      int j = i;
      while(j < 2000000) {
	all[j] = 1;
	j += i;
      }
    }
  }
  
  /*
  unsigned long long i = 2000000;
  cout<<get_max_factor(i*i*i+1)<<endl;
  unsigned long long  sum = 0;
  for(unsigned i = 1; i <= 100; i++) {
    sum += f(i);
  }
  

  cout<<sum<<endl;
  */
  ull sum = 0; 
  for(unsigned i = 2000000; i >= 1; i--) {
    cout<< f(i)<<endl;

    if(i % 10000 == 0) {
      cerr<<"running... "<<i<<endl;
    }
  }

  cout<<sum<<endl;
  
}
