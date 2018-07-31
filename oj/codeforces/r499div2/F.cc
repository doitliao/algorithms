 #include <bits/stdc++.h>

using namespace std;

class Node {
public:
  Node():left(0), right(0), p(0), change(false){}
  bool value;
  int left, right, p;
  string op;
  bool change;
};

vector<Node> T;
set<int> leaf;

bool dfs(int i) {
  bool ans;
  if(T[i].op == "IN") ans = T[i].value;
  else{  
    bool a = dfs(T[i].left);
    bool b = false;
    if(T[i].op != "NOT")
      b = dfs(T[i].right);
    
    if(T[i].op == "AND") ans = a && b;
  
    if(T[i].op == "OR") ans = a || b;

    if(T[i].op == "XOR") ans = a != b;
  
    if(T[i].op == "NOT") ans = !a;
  }
  
  T[i].value = ans;
  return T[i].value;
}

void dfs2(int i) {
  if(T[i].op == "IN" ) return;

  if(T[i].change == false) {
    T[T[i].left].change = false;
    if(T[i].op != "NOT") T[T[i].right].change = false;
  }else {
    if(T[i].op == "AND") {
      T[T[i].left].change =  T[T[i].right].value;
      T[T[i].right].change = T[T[i].left].value;
    }
    if(T[i].op == "OR") {
      T[T[i].right].change = !T[T[i].left].value;
      T[T[i].left].change =  !T[T[i].right].value;
    }
    
    if(T[i].op == "XOR") {
      T[T[i].left].change =  true;
      T[T[i].right].change = true;
    }
    if(T[i].op == "NOT") {
      T[T[i].left].change =  true;
    }
  }
  dfs2(T[i].left);
  if(T[i].op != "NOT")
    dfs2(T[i].right);
}

int main(){
  int n;
  cin>>n;
  T.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    cin>>T[i].op;
    if(T[i].op == "IN") {
      int t;
      cin>>t;
      T[i].value = (t == 1);
      leaf.insert(i);
    } else if(T[i].op == "NOT") {
      cin>>T[i].left;
      T[T[i].left].p = i;
    }else {
      cin>>T[i].left>>T[i].right;
      T[T[i].left].p = i;
      T[T[i].right].p = i;
    }
  }

  dfs(1);
  T[1].change = true;
  dfs2(1);
  
  for(auto i : leaf) {
    printf("%d",T[1].value != T[i].change);
  }
}
