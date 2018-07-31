#include <bits/stdc++.h>
using namespace std;

class Knight{
  public:
    Knight(int R, int C, int M, int N):
      R(R), C(C), M(M), N(N),
      g(R, vector<int>(C, -2)),
      v(R, vector<bool>(C, false)){}

    void setWater(int x, int y){
      g[x][y] = -1;
    }

    int check(int a, int b, int X, int Y){
      int c[2];
      int d[2];
      c[0] = a - X; c[1] = a + X;
      d[0] = b - Y; d[1] = b + Y;

      int cnt = 0;
      for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
          if(c[i] >=0 && c[i] < R
              && d[j] >=0 && d[j] < C
              //&& c[i] != a && d[j] != b
              && g[c[i]][d[j]] != -1){
            cnt++;
            if(v[c[i]][d[j]] == false){
              dfs(c[i], d[j]);
            }
          }
        }
      if(c[0] == c[1] || d[0] == d[1]){
        assert(cnt%2 == 0);
        cnt /=2;
      }
      return cnt;
    }

    void dfs(int x, int y){
      if(g[x][y] == -1)return;
      g[x][y] = 0;
      v[x][y] = true;
      g[x][y] += check(x, y, M, N);
      if(M != N)
        g[x][y] += check(x, y, N, M);
      if(g[x][y] & 1)odd++;
      else even++;
    }

    void do_knight(){
      even = 0;
      odd = 0;
      dfs(0, 0);
      cout<<even<<" "<<odd<<endl;
    }

  private:
    int R,C,M,N;
    int even,odd;
    vector<vector<int> > g;
    vector<vector<bool> > v;
};

int main(){
  int t;
  int R,C,M,N,W,x,y;
  cin>>t;
  for(int i = 1; i <= t; i++){
    cin>>R>>C>>M>>N;
    Knight r(R,C,M,N);
    cin>>W;
    while(W--){
      cin>>x>>y;
      r.setWater(x,y);
    }
    //if(i != 5)continue;
    cout<<"Case "<<i<<": ";
    r.do_knight();
  }
}
