#include <bits/stdc++.h>

using namespace std;

/*
class Node {
public:
  Node(unsigned x, unsigned y, unsigned z) {

  }
  unsigned x, y, z;
};
  */
int main(){
  unsigned xm, ym, zm, n, m, k, x, y, z;

  using trip = tuple<unsigned, unsigned, unsigned>;
  
  vector<trip> opened;
  vector<trip> closed;

  cin>>xm>>ym>>zm>>n>>m>>k;
  
  for(unsigned i = 0; i < n; i++) {
    cin>>x>>y>>z;
    opened.push_back(std::make_tuple(x, y, z));
  }
  for(unsigned i = 0; i < m; i++) {
    cin>>x>>y>>z;
    closed.push_back(std::make_tuple(x, y, z));
  }

  auto tcmp = [](const trip& a, const trip& b) {
    if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
    if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);

    return false;
  };
  auto teq = [](const trip& a, const trip& b) {
    return get<0>(a) == get<0>(b) &&
    get<1>(a) == get<1>(b) &&
    get<2>(a) == get<2>(b);
  };

  sort(opened.begin(), opened.end());
  sort(closed.begin(), closed.end());

  trip& lb = * opened.begin();
  trip& rb = opened.back();
  trip& lc = *closed.begin();
  trip& rc = closed.back();

  auto print = [] (trip & i) {
    printf("%u %u %u\n", get<0>(i), get<1>(i), get<2>(i));
  };
  
  for(auto i : {lb, rb, lc, rc}) {
    print(i);
  }

  if(lb <= lc && lc <= rb || lb <= rc && rc <= rb) {
    printf("INCORRECT\n");
    return 0;
  }
  
 
  for(unsigned i = 0; i < k; i++) {
    cin>>x>>y>>z;
    printf("Q: %u %u %u\n", x, y, z);
    trip t = std::make_tuple(x, y, z);
    if(t >= lb && t <= rb) {
      printf("OPEN\n");
    }else if(rc < lb && t <= lc){
      printf("CLOSED\n");
    }else if(lc > rb && t >= lc){
      printf("CLOSED\n");
    }else if(lc <lb && rc > rb && (t <= lc || t >= rc)){
      printf("CLOSED\n");
    }else{
      printf("UNKNOWN\n");
    }
  }
  return 0;
}
