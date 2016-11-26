#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct PT{
  int x,y;
  PT(int x, int y):x(x), y(y){}
};

int main(){
  int n, w, v, u;
  int  x,y;
  cin>>n>>w>>v>>u;
  vector<PT> B;
  int xmin,ymin, px,py;
  xmin = 0; ymin = w;
  px = 0; py = w;
  bool first = true;
  bool start = false;
  while(n--){
    cin>>x>>y;
    if(x < 0)first = false;
    if(first && y >= 0 && x >= 0 && (y / (double) u > x / (double)v))first = false;

    while(!B.empty() && x > B.back().x && y < B.back().y){
      //cout<<"B.pop back: "<<B.size()<<" # "<<B.back().x<<" "<<B.back().y<< " " << x<< " " <<y<<endl;
      B.pop_back();
    }
    if(!B.empty() && x <= B.back().x && y < 0){
      B.clear();
      start = false;
      continue;
    }
    if(!start && x > xmin && y > 0 && y < ymin)start = true;
    if (start)
      B.push_back(PT(x, y));
  }

  if(first){
    printf("%.15lf\n", w/(double)u);
    return 0;
  }
  
  
  double sum = 0;
  x = 0; y = 0;
  px = 0;py = 0;
  for(size_t i = 0; i < B.size(); i++){
    if(B[i].y > w)B[i].y = w;
    if(B[i].x > px && (B[i].x - px) / (double)v > (B[i].y - py) / (double)u){
      x += B[i].x - px;
    }else{
      y += B[i].y - py;
    }
    px = B[i].x;
    py = B[i].y;
    if(B[i].y >= w)break;
  }
  y += w - py; 
  sum = x / (double)v + y / (double) u;
  printf("%.15lf\n",sum);
  return 0;
}
