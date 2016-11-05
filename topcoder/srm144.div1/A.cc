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

class BinaryCode {
public:
  vector <string> decode(string);
};

vector <string> BinaryCode::decode(string message) {
  vector<string> v;
  for(int i = 0; i <= 1; i++){
    std::stringstream ss;
    int prev1 = 0, prev2 = i;
    ss<<i;
    int flag = false;
    for(int j = 1; j <= message.size(); j++){
      int p = message[j-1] - '0' - prev1 - prev2;
      if( p != 0 && p != 1){
        flag = true;
        break; 
      }
      prev1 = prev2;
      prev2 = p;
      if(j != message.size())
        ss<<p;
      else if( p == 1){
        flag = true;
        break;
      }
    }
    v.push_back(flag?"NONE": ss.str());
  }
  return v;
}


double test0() {
  string p0 = "123210122";
  BinaryCode * obj = new BinaryCode();
  clock_t start = clock();
  vector <string> my_answer = obj->decode(p0);
  clock_t end = clock();
  delete obj;
  cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  string t1[] = { "011100011",  "NONE" };
  vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
  cout <<"Desired answer: " <<endl;
  cout <<"\t{ ";
  if (p1.size() > 0) {
    cout <<"\""<<p1[0]<<"\"";
    for (int i=1; i<p1.size(); i++)
      cout <<", \"" <<p1[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  cout <<endl <<"Your answer: " <<endl;
  cout <<"\t{ ";
  if (my_answer.size() > 0) {
    cout <<"\""<<my_answer[0]<<"\"";
    for (int i=1; i<my_answer.size(); i++)
      cout <<", \"" <<my_answer[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  if (my_answer != p1) {
    cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
    return -1;
  }
  else {
    cout <<"Match :-)" <<endl <<endl;
    return (double)(end-start)/CLOCKS_PER_SEC;
  }
}
double test1() {
  string p0 = "11";
  BinaryCode * obj = new BinaryCode();
  clock_t start = clock();
  vector <string> my_answer = obj->decode(p0);
  clock_t end = clock();
  delete obj;
  cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  string t1[] = { "01",  "10" };
  vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
  cout <<"Desired answer: " <<endl;
  cout <<"\t{ ";
  if (p1.size() > 0) {
    cout <<"\""<<p1[0]<<"\"";
    for (int i=1; i<p1.size(); i++)
      cout <<", \"" <<p1[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  cout <<endl <<"Your answer: " <<endl;
  cout <<"\t{ ";
  if (my_answer.size() > 0) {
    cout <<"\""<<my_answer[0]<<"\"";
    for (int i=1; i<my_answer.size(); i++)
      cout <<", \"" <<my_answer[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  if (my_answer != p1) {
    cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
    return -1;
  }
  else {
    cout <<"Match :-)" <<endl <<endl;
    return (double)(end-start)/CLOCKS_PER_SEC;
  }
}
double test2() {
  string p0 = "22111";
  BinaryCode * obj = new BinaryCode();
  clock_t start = clock();
  vector <string> my_answer = obj->decode(p0);
  clock_t end = clock();
  delete obj;
  cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  string t1[] = { "NONE",  "11001" };
  vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
  cout <<"Desired answer: " <<endl;
  cout <<"\t{ ";
  if (p1.size() > 0) {
    cout <<"\""<<p1[0]<<"\"";
    for (int i=1; i<p1.size(); i++)
      cout <<", \"" <<p1[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  cout <<endl <<"Your answer: " <<endl;
  cout <<"\t{ ";
  if (my_answer.size() > 0) {
    cout <<"\""<<my_answer[0]<<"\"";
    for (int i=1; i<my_answer.size(); i++)
      cout <<", \"" <<my_answer[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  if (my_answer != p1) {
    cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
    return -1;
  }
  else {
    cout <<"Match :-)" <<endl <<endl;
    return (double)(end-start)/CLOCKS_PER_SEC;
  }
}
double test3() {
  string p0 = "123210120";
  BinaryCode * obj = new BinaryCode();
  clock_t start = clock();
  vector <string> my_answer = obj->decode(p0);
  clock_t end = clock();
  delete obj;
  cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  string t1[] = { "NONE",  "NONE" };
  vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
  cout <<"Desired answer: " <<endl;
  cout <<"\t{ ";
  if (p1.size() > 0) {
    cout <<"\""<<p1[0]<<"\"";
    for (int i=1; i<p1.size(); i++)
      cout <<", \"" <<p1[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  cout <<endl <<"Your answer: " <<endl;
  cout <<"\t{ ";
  if (my_answer.size() > 0) {
    cout <<"\""<<my_answer[0]<<"\"";
    for (int i=1; i<my_answer.size(); i++)
      cout <<", \"" <<my_answer[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  if (my_answer != p1) {
    cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
    return -1;
  }
  else {
    cout <<"Match :-)" <<endl <<endl;
    return (double)(end-start)/CLOCKS_PER_SEC;
  }
}
double test4() {
  string p0 = "3";
  BinaryCode * obj = new BinaryCode();
  clock_t start = clock();
  vector <string> my_answer = obj->decode(p0);
  clock_t end = clock();
  delete obj;
  cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  string t1[] = { "NONE",  "NONE" };
  vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
  cout <<"Desired answer: " <<endl;
  cout <<"\t{ ";
  if (p1.size() > 0) {
    cout <<"\""<<p1[0]<<"\"";
    for (int i=1; i<p1.size(); i++)
      cout <<", \"" <<p1[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  cout <<endl <<"Your answer: " <<endl;
  cout <<"\t{ ";
  if (my_answer.size() > 0) {
    cout <<"\""<<my_answer[0]<<"\"";
    for (int i=1; i<my_answer.size(); i++)
      cout <<", \"" <<my_answer[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  if (my_answer != p1) {
    cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
    return -1;
  }
  else {
    cout <<"Match :-)" <<endl <<endl;
    return (double)(end-start)/CLOCKS_PER_SEC;
  }
}
double test5() {
  string p0 = "12221112222221112221111111112221111";
  BinaryCode * obj = new BinaryCode();
  clock_t start = clock();
  vector <string> my_answer = obj->decode(p0);
  clock_t end = clock();
  delete obj;
  cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  string t1[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" };
  vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
  cout <<"Desired answer: " <<endl;
  cout <<"\t{ ";
  if (p1.size() > 0) {
    cout <<"\""<<p1[0]<<"\"";
    for (int i=1; i<p1.size(); i++)
      cout <<", \"" <<p1[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  cout <<endl <<"Your answer: " <<endl;
  cout <<"\t{ ";
  if (my_answer.size() > 0) {
    cout <<"\""<<my_answer[0]<<"\"";
    for (int i=1; i<my_answer.size(); i++)
      cout <<", \"" <<my_answer[i]<<"\"";
    cout <<" }" <<endl;
  }
  else
    cout <<"}" <<endl;
  if (my_answer != p1) {
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
  
  time = test3();
  if (time < 0)
    errors = true;
  
  time = test4();
  if (time < 0)
    errors = true;
  
  time = test5();
  if (time < 0)
    errors = true;
  
  if (!errors)
    cout <<"You're a stud (at least on the example cases)!" <<endl;
  else
    cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
