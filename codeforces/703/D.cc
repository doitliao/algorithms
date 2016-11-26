//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef int T;
class Fenwick{
public:
  Fenwick(int N):MaxVal(N), tree(N + 1, 0){
    int idx = N >> 1;
    bitMax = 1;
    while(idx > 0){
      bitMax <<= 1;
      idx >>= 1;
    }
  }
  void update(int idx, int val){
    while(idx <= MaxVal){
      tree[idx] ^= val;
      idx += (idx & -idx);
    }
  }

  T sum(int idx){
    T s = 0;
    while(idx > 0){
      s ^= tree[idx];
      idx -= (-idx & idx);
    }
    return s;
  }
  
  T query(int l, int r){
    return sum(r) ^ sum(l - 1);  
  }

  T get(int idx){
    int s = tree[idx];
    if(idx > 0){
      int z = idx - (idx & -idx);
      idx--;
      while(idx != z){
        s -= tree[idx];
        idx -= (idx & -idx);
      }
    }
    return s;
  }

  void scale(int c){
    for(int i = 1; i <= MaxVal; i++)
      tree[i] = tree[i]/c;
  }

  // if in tree exist more than one index with a same cumulative
  // frequency, this procedure will return some of them (we do not
  // know which one)

  // bitMask - initialy, it is the greatest bit of MaxVal
  // bitMask store interval which should be searched
  int bitMax;
  int find(int cumFre){
    int idx = 0; //this var is result of function
    int bitMask = bitMax;
    
    while((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
      int tIdx = idx + bitMask; //we make midpoint of interval.
      if(tIdx > MaxVal){
        bitMask >>= 1;
        continue;
      }
      if(cumFre == tree[tIdx]) // if it is equal, we just return idx
        return tIdx;
      else if(cumFre > tree[tIdx]){
        // if tree frequency "can fit" into cumFre.
        // then include it
        idx = tIdx; //update idx
        cumFre -= tree[tIdx]; // set frequency for next loop
      }
      bitMask >>= 1; //half current interval.
    }
    if(cumFre != 0) return -1;
    else return idx;
  }
  
  // if in tree exists more than one index with a same 
  // cumulative frequency, this procedure will return 
  // the greatest one.
  int findG(int cumFre){
    int idx = 0;
    int bitMask = bitMax;

    while((bitMask != 0) && (idx < MaxVal)){
      int tIdx = idx + bitMask;
      if(tIdx > MaxVal){
        bitMask >>= 1;
        continue;
      }

      if(cumFre >= tree[tIdx]){
        // if current cumulative frequency is equal to cumFre,
        // we are still looking for higher index (if exists)
        // (if higher frequency is equal zero)
        idx = tIdx;
        cumFre -= tree[tIdx];
      }
      bitMask >>= 1;
    }
    if(cumFre != 0)return -1;
    else return idx;
  }
  private:
    int MaxVal;
    vector<T> tree;
};

int main(){
  int n,m;
  cin>>n;
  vector<int> a(n + 1);
  Fenwick f(n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }
  cin>>m;
  vector<vector<pair<int, int> > > q(n + 1);
  int l,r;
  for(int i = 0; i < m; i++){
    scanf("%d%d", &l, &r);
    q[r].push_back(make_pair(l, i));
  }
  
  vector<int> ans(m);
  unordered_map<int, int> last;
  for(int i = 1; i <= n; i++){
    if(last.find(a[i]) != last.end())
      f.update(last[a[i]], a[i]);

    last[a[i]] = i;
    f.update(i, a[i]);
    a[i] ^= a[i-1];
    for(int j = 0; j < q[i].size(); j++){
      ans[q[i][j].second] = a[i] ^ a[q[i][j].first -1] ^ f.sum(i) ^ f.sum(q[i][j].first -1);
    }
  }
  for(int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}
