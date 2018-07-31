#include <bits/stdc++.h>

using namespace std;

int main(){
  char ch;
  while(ch = getchar(), ch != EOF) {
    if(ch != '\n') {
      ch -= 7;
    }
    putchar(ch);
  }
}
