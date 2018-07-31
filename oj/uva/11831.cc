#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <limits>
#include <assert.h>
using namespace std;

typedef long long LLD;
const LLD INF = numeric_limits<LLD>::max();

size_t move_to(vector<string>& G, int& i, int& j, int x, int y){
  int xx = i + x;
  int yy = j + y;
  if(xx < 0 || xx >= (int)G.size())return 0;
  if(yy < 0 || yy >= (int)G[0].length())return 0 ;
  if(G[xx][yy] == '#')return 0; //the pillar.
  i = xx;
  j = yy;
  if(G[xx][yy] == '.'){
    return 0;
  }
  if(G[xx][yy] == '*'){
    G[xx][yy] = '.';
    return 1;
  }
  assert(false);
  return 0;
}

int main(){
  int M, N, S;
  int sx,sy;
  int dx,dy;
  while(true){
    cin>>N>>M>>S;
    if(0 == M&& 0 == N&& 0==S)break;
    vector<string> G(N);
    dx = dy = -1;
    sx = sy = -1;
    for(int i = 0; i < N; i++){
      cin>>G[i];
      if(dy !=-1 || dx != -1)continue;
      int t = G[i].find("N");
      if(t >= 0){
        sx = i;sy=t;
        dx = -1;dy=0;
      }
      t = G[i].find("S");
      if(t >= 0){
        sx = i;sy=t;
        dx = 1;dy=0;
      }
      t = G[i].find("L");
      if(t >= 0){
        sx = i;sy=t;
        dx = 0;dy=1;
      }
      t = G[i].find("O");
      if(t >= 0){
        sx = i;sy=t;
        dx = 0;dy=-1;
      }
    }
    string op;
    cin>>op;
    size_t cnt = 0;
    G[sx][sy] = '.';
    for(size_t i = 0; i < op.length(); i++){
      switch(op[i]){
        case 'E':
          if(dx == -1){dx=0;dy=-1;}
          else if(dx == 1){dx=0;dy=1;}
          else if(dy == -1){dx=1;dy=0;}
          else if(dy == 1){dx=-1;dy=0;}
          break;
        case 'D':
          if(dx == -1){dx=0;dy=1;}
          else if(dx == 1){dx=0;dy=-1;}
          else if(dy == -1){dx=-1;dy=0;}
          else if(dy == 1){dx=1;dy=0;}
          break;

        case 'F':
          cnt += move_to(G, sx, sy, dx, dy);
          break;
        default:
          cout<<"GRD"<<endl;
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
