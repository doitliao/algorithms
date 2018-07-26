#include <vector>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

class Factor{
  public:
    Factor(unsigned n):N(n), p(n), d(n){
      for(int i = 2; i < n; i++){
          if (!p[i]) {
            for (int x = i; x < n; x += i) {
              d[x].push_back(i);
              p[x] = true;
            }
          }
      }
    }

    vector<unsigned> get(int x){
      return d[x];
    }
    const unsigned N;
    vector<bool> p; // is not prime number.
    vector<vector<unsigned> > d;
};

class Coprime {
public:
  Coprime(unsigned n):N(n), factor(n) {
    for(int i = 2; i < n; i++){
      cp.insert(i);
    }
  }

  void add(unsigned a){
    for(auto x : factor.get(a)) {
      for (int i = x; i < N; i += x) {
        cp.erase(i);
      }
    }
  }

  unsigned get(unsigned low){
    return * cp.lower_bound(low);
  }
  const unsigned N;
  Factor factor;
  std::set<unsigned> cp;
};

int main() {
  int n;
  cin>>n;
	Coprime c(2000005);
	
	bool sat = false;
	unsigned a;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		if(i != 0)cout<<" ";
		if(sat){
			a = c.get(0);
			cout<<a;

		}else{
			unsigned cur = c.get(a);
			if(a != cur)sat = true;
			a = cur;
			cout<<cur;
		}
		c.add(a);
	}

	cout<<endl;
}
