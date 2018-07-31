#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <limits>
#include <assert.h>
using namespace std;

struct Node{
  int type;
  int left,right;
  char op;
  Node():type(-1),left(-1),right(-1){}
  Node(int type, int left, int right):type(type), left(left), right(right){}
};

const int N = 20009;
vector<Node> p(N);
vector<bool> d(N);
char result[N / 2];
int idx;
void bfs(int s){
  queue<int> q;
  fill(d.begin(), d.end(), false);
  q.push(s);
  idx = N / 2 - 1;
  result[idx--] = '\0';
  while(!q.empty()){
    int i = q.front(); q.pop();
    d[i] = true;
    result[idx--]=p[i].op;
    if(p[i].type == 1){
      continue;
    }
    q.push(p[i].left);
    q.push(p[i].right);
  }
}

void dfs(int s){
  if(p[s].type == 1){
    cout<<p[s].op;
    return ;
  }
  int l = p[s].left;
  int r = p[s].right;

  dfs(r);
  if(p[r].type == 2 && p[l].type == 1)
    cout<<p[r].op;
  dfs(l);
  if(p[r].type == 2 && p[l].type != 1)cout<<p[r].op;
  if(p[l].type == 2)cout<<p[l].op;
}

int main(){
  int t;
  cin>>t;
  string s;

  while(t--){
    cin>>s;
    stack<int> st;
    int j = 0;
    for(size_t i = 0; i < s.length(); i++){
      p[j].op = s[i];
      if(s[i]>= 'a'){
        p[j].type = 1;
      }else{
        int a = st.top();st.pop();
        int b = st.top();st.pop();
        p[j].type = 2;p[j].left = b; p[j].right = a;
      }
      st.push(j++);
    }

    assert(st.size() == 1);
    bfs(st.top());
    cout<<&result[idx + 1]<<endl;
  }
  return 0;
}
