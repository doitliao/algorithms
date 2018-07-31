#include <bits/stdc++.h>

const unsigned long long t = 10000000000;

unsigned long long x(unsigned long long a) {
  unsigned long long b = 1;
  for(size_t i = 0; i < a; i++) {
    b = (b * a) % t;
  }

  return b;
}

int main() {
  unsigned long long sum = 0;
  for(unsigned i = 1; i <= 1000; i++) {
    sum += x(i);

    sum %= t;
  }
  std::cout<<sum<<std::endl;
}
