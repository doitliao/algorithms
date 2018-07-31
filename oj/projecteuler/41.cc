#include <bits/stdc++.h>

using namespace std;

bool is_prime(unsigned n) {
  unsigned i = 2;
  while (i * i < n) {
    if((n % i) == 0) return false;
    i++;
  }
  return true;
}

int main(){
  vector<string> all;
  ostringstream ss;
  for(int i = 1; i < 10; i++) {
    ss<<i;
    all.push_back(ss.str());
  }

  for(auto s: all){
    unsigned x = 2143;
    unsigned tmp = 0;
    do {
      tmp = atoi(s.c_str());
      if(is_prime(tmp)) {
	cout<<s<<endl;
	x = tmp;
      }
    }while(std::next_permutation(s.begin(), s.end()));
  }
}
