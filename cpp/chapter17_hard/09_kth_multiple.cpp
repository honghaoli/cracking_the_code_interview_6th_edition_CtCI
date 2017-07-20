//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, 7 do not have to be factors, but it should not have any other prime factors.
 * For example, the first several multiples would be (in order) 1,3,5,7,9,15,21.
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

