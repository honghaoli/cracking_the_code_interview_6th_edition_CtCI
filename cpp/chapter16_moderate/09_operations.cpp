//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Write medhods to implement the multiply, subtract, and divide operations for integers. The results of all of these are integers. Use only the add operator.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Note: The bit calculation is not allowed!
 * Then it's not a very interesting problem...
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

