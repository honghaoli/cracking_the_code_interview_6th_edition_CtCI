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
vector<string> find_next(int net, int left, int right) {
  // back to equal
  if (net == 0) {
    if (left == 0) {
      return vector<string> {};
    }
    else {
      vector<string> ss;
      for (auto &s : find_next(1, left - 1, right)) {
        ss.push_back("(" + s);
      }
      return ss;
    }
  }

  // only right left
  if (net == right) {
    string s = "";
    for (int i = 0; i < net; ++i) {
      s += ")";
    }
    return vector<string> {s};
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
    test(4);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

