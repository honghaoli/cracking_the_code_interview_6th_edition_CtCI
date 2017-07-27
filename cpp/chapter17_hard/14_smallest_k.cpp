//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Design an algorithm to find the smallest K numbers in an array.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Directly sort ~O(NlogN), or if K < logN, find K times, so ~O(KN)
 */


// 2nd method
/*
 * The book solution
 * Max heap, only keep K items, O( N log K)
 */



// 3rd method
/*
 * The book solution
 * Find the ith smallest element in expected O(N) time, then walk through to find all K numbers.
 */




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

