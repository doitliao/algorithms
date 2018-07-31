#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,t;
  cin>>n;
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &t);
    sum1+=t;
  }

  for(int i = 0; i < n; i++) {
    scanf("%d", &t);
    sum2+=t;
  }

  if(sum2 <= sum1) {
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}
