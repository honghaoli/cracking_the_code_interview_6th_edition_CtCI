//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a number x (the number of values less than or equal to x). Implement the data structures and algorithms to support these operations. That is, implement the method track(int x), which is called when each number is generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal to x (not including x itself).
 *  EXAMPLE:
 *  Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3
 *  getRankOfNumber(1) = 0
 *  getRankOfNumber(3) = 1
 *  getRankOfNumber(4) = 3
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Book soluton:  Binary Search Tree
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

  void test() {
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

