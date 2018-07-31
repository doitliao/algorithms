#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin>>t;
  char ch;
  map<char, int> m;
  while(true) {
    cin>>ch;
    if(cin.eof())break;
    if(!std::isalpha(ch)) continue;
    
    m[std::toupper(ch)]++;
  }

  vector<tuple<int, char>> v;
  for(auto it : m) {
    v.push_back(std::make_tuple(it.second, it.first));
    
  }
  sort(v.begin(), v.end(), [](const tuple<int, char> a, tuple<int, char> b) {
      if(get<0>(a) != get<0>(b)){
	return get<0>(a) > get<0>(b);
      }

      return get<1>(a) < get<1>(b);
    });
  
  for(auto it : v) {
    cout<<get<1>(it)<<" "<<get<0>(it)<<endl;
  }
}
