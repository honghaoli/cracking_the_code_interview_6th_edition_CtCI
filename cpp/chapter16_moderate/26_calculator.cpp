//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given an arithmetic equation consisting of positive integers, +, -, * and / (no parentheses), compute the result.
 * EXAMPLE:
 *    INPUT:    2*3+5/6*3+15
 *    OUTPUT:   23.5
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

