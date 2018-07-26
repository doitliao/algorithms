#include <iostream>
#include <vector>
#include <map>

using namespace std;


class UFset{
public:
  UFset(int n):N(n){initSet(n);}
  vector<unsigned> cost;
  int N;
  
  vector<int> pset;
  int numOfSet = 0;
  void initSet(int size){
    pset.resize(size);
    cost.resize(size);
    numOfSet = size; 
    for(int i = 0; i < size; i++){
      pset[i] = i;
      cost[i] = 0;
    }
  }
  
  int findSet(int i){ 
    return pset[i] == i? i: (pset[i] = findSet(pset[i]));
  }	
  
  bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
  void unionSet(int i, int j){
    if(!isSameSet(i, j))numOfSet--; 
    //cout<<"unionSet"<<i<<" "<<j<<endl;
    int x = findSet(i);
    int y = findSet(j);
    //cout<<"unionSet root "<<x<<" "<<y<<endl;
    //cout<<"unionSet before "<<cost[x]<<" "<<cost[y]<<endl;
    cost[x] = min(cost[x], cost[y]);
    cost[y] = min(cost[x], cost[y]);
    //cout<<"unionSet after "<<cost[x]<<" "<<cost[y]<<endl;
    pset[x] = y;
  }

  int numberOfSets(){return numOfSet;}
};

int main()
{
  int n,k, m;
  cin>>n>>k>>m;
  UFset uf(n);
  char str[30];
  map<string, int> lexcon;
  for(int i = 0; i < n; i++){
    scanf("%s", str);
    lexcon[str] = i;
  }
  
  unsigned c;
  for(int i = 0; i < n; i++){
    scanf("%u", &c);
    uf.cost[i] = c;
  }

  for(int i = 0; i < k; i++){
    int x, y;
    scanf("%d", &x);
    int prev = -1;
    for(int j = 0; j < x; j++){
      scanf("%d", &y);
      y--;
      if(j != 0){
	uf.unionSet(prev, y);
      }
      prev = y;
    }
  }
  
  unsigned long long cost = 0;
  for(int i = 0; i < m; i++){
    scanf("%s", str);
    //cout<<"send "<<str<<" "<<lexcon[str]<<endl;
    cost += uf.cost[uf.findSet(lexcon[str])];
  }
  cout<<cost<<endl;

}
