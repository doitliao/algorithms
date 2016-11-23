#include <bits/stdc++.h>

using namespace std;

typedef int T;
class Fenwick{
  void update(int idx, int val){

  }

  T sum(int idx){
    T s = 0;
    while(idx > 0){
      s += tree[idx];
      idx -= (-idx) & idx;
    }
    return sum;
  }

  T query(int l, int r){
    
    return 0;
  }
  private:
    vector<T> tree;
};

int main(){
  
  return 0;
}
