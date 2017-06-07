//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n pairs of parentheses.
// EXAMPLE
// Input: 3
// Output: ((())), (()()), (())(), ()(()), ()()().





#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"



using namespace std;



// 1st method
// recursively add ( or ) for each position, count num of left - num of right = net, net must >= 0.
// so if net == 0, must add left ( ;
// if left == 0, can only add right ) ;
// otherwise, we can choose both left ( and right ) .
vector<string> find_next(int net, int left, int right) {
  // only right left
//  if (net == right) {   // also could be when (left == 0) as below.
  if (left == 0) {
    string s = "";
    for (int i = 0; i < net; ++i) {
      s += ")";
    }
    return vector<string> {s};
  }

  // equal number of ( and )
  if (net == 0) {
    vector<string> ss;
    for (auto &s : find_next(1, left - 1, right)) {
      ss.push_back("(" + s);
    }
    return ss;
  }


  // in the middle
  vector<string> ss;
  for (auto &s : find_next(net + 1, left - 1, right)) {
    ss.push_back("(" + s);
  }
  for (auto &s : find_next(net - 1, left, right - 1)) {
    ss.push_back(")" + s);
  }
  return ss;
}


vector<string> pairs(int n) {
  return find_next(0, n, n);
}


// 2nd method



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test(int n) {
    auto ss = pairs(n);
    printf("%d-layer has %d pairs: ", n, ss.size());
    print_vector(ss);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test(1);
    test(2);
    test(3);
    test(4);  // should have 14 results.

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

