//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given a two-dimensional graph with points on it, find a line which passes the most number of points.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * O(N^2)
 * For each pair, calculate the slope and intercept.
 * with special treatment for slope = infinity.
 */

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

  void test1() {
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

