//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it could hold if someone poured water across the top. You can assume that each histogram bar ha width 1.
 *
 * EXAMPLE
 *    (Black bars "=" are histogram. Gray "." is water.)
 *
 *    INPUT:    {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0}
 *
 *                             =
 *                             =  .  .  .  .  =
 *                    =  .  .  =  .  .  .  .  =
 *                    =  .  .  =  .  .  =  .  =
 *                    =  .  .  =  .  .  =  .  =
 *                    =  .  .  =  .  .  =  .  =  .  =
 *              ----------------------------------------------
 *              0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0
 *
 *              water =    8   +     17       +   1    = 26
 *
 *    OUTPUT:   26
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

