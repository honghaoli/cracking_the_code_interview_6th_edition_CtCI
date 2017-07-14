//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Write a method that finds the maximum of two numbers. You should not use if-else or any other comparison operator.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * use bit to test positive/negative
 */
int maximum(int n1, int n2) {
  // important for unsigned to shift the sign bit!
  // unsigned int could overflow!
  // use long to avoid overflow!!! the book solution uses other tricks.
  unsigned long diff = n1 - n2;
  diff = diff >> sizeof(int) * 8 - 1;  // 1 if n1 < n2
  return n1 + diff * (n2 - n1);
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

  void test1() {
    int a, b;
    a = 1;
    b = 2;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = -1;
    b = -2;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = 100000;
    b = 0;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = 100000;
    b = 100;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = 100;
    b = -100;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = -10000;
    b = -100;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = 100;
    b = 100;
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
    a = numeric_limits<int>::max();
    b = numeric_limits<int>::min();
    printf("maximum of %d and %d is: %d\n", a, b, maximum(a, b));
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    printf("size of int: %d\n", sizeof(int));
    printf("max of int: %d\n", numeric_limits<int>::max());
    // customize your own tests here

    test1();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

