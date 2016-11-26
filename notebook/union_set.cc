#include <iostream>
#include <vector>

using namespace std;

const int N = 1000;
vector<int> pset(N);
int numOfSet = 0;
void initSet(int size){
  pset.resize(size);
  numOfSet = size; 
  for(int i = 0; i < size; i++)pset[i] = i;
}

int findSet(int i){ 
  return pset[i] == i? i: (pset[i] = findSet(pset[i]));
}

bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
void unionSet(int i, int j){
  if(!isSameSet(i, j))numOfSet--; 
  pset[findSet(i)] = findSet(j);
}

int numberOfSets(){return numOfSet;}
int main(){
  initSet(5);
  cout<<isSameSet(2, 4)<<endl;
  unionSet(1,2);
  unionSet(4, 5);
  unionSet(1, 5);
  cout<<isSameSet(2, 4)<<endl;
  cout<<numberOfSets()<<endl;

}
