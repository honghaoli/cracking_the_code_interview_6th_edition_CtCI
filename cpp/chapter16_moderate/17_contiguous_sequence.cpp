//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum.
 * EXAMPLE:
 * Input:   2, -8, 3, -2, 4, -10
 * Output:  5 (i.e., {3, -2, 4})
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method

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

