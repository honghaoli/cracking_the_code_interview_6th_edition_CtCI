//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * A circus is designing a tower routine consisting of people standing atop one another's shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower.
 * EXAMPLE:
 *    INPUT (ht, wt):
 *        (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
 *    OUTPUT:
 *        The longest tower is length of 6 and includes from top to bottom:
 *        (56, 90) (60, 95) (65, 100) (68, 110) (70, 150) (75, 190)
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

