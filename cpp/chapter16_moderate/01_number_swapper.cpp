//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Write a function to swap a number in place (that is, without temporary variables).
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;


// 1st method
/*
 * Do the following...
 *      a,    b
 *     a+b,   b
 *     a+b,   a
 *      b,    a
 */
/// notice this method could cause overflow problem.
void swap(int &a, int &b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

// 2nd method
/*
 * A better method uses bit manipulation.
 * It's better because it works for other types of data besides integers.
 */
void swap_bit(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}



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
    int a = 1;
    int b = 2;
    printf("before swap, a = %d, b = %d.\n", a, b);
//    swap(a, b);
    swap_bit(a, b);
    printf("after swap, a = %d, b = %d.\n", a, b);
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

