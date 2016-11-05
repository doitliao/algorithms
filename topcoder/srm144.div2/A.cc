#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Time {
public:
  string whatTime(int);
};

string Time::whatTime(int seconds) {
  int h = seconds / 3600;
  int m = (seconds % 3600) / 60;
  int s = seconds % 60;

  std::stringstream ss;
  ss<<h<<":"<<m<<":"<<s;
  return ss.str();
}

//Powered by [KawigiEdit] 2.0!
