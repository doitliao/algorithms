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

class TeleportationMaze {
public:
	int pathLength(vector <string>, int, int, int, int);
};

int TeleportationMaze::pathLength(vector <string> a, int r1, int c1, int r2, int c2) {
  static vector<vector<bool> > visited(a.size(), vector<bool>(a[0].size(), false));
  if(r1 == r2 && c1 == c2) return 0;

  int ret = std::numeric_limits<int>::max(), ans = 0;
  int r = r1, c = c1;
  // up
  if(r > 0){
    r = r - 1;
    while(r >= 0 && a[r][c] != '.')r--;
    if(a[r][c] == '.') {
      visited[r][c] = true;
      ans = pathLength(r, c, r2, c2);
      ans += (r == r1 - 1)? : 1 : 2;
      
      visited[r][c] = false;
      ret = min(ret, ans);
    }
  }
  // down
  r = r1;
  c = c1;
  if(r )
  
}

double test0() {
	string t0[] = {".##.",
 ".###",
 ".###",
 "...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 0;
	int p3 = 3;
	int p4 = 3;
	TeleportationMaze * obj = new TeleportationMaze();
	clock_t start = clock();
	int my_answer = obj->pathLength(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"#.",
 ".#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 0;
	TeleportationMaze * obj = new TeleportationMaze();
	clock_t start = clock();
	int my_answer = obj->pathLength(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"......",
 "#####.",
 "#.###.",
 "#####.",
 "#.###.",
 "#####.",
 "#....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 0;
	int p3 = 6;
	int p4 = 1;
	TeleportationMaze * obj = new TeleportationMaze();
	clock_t start = clock();
	int my_answer = obj->pathLength(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
