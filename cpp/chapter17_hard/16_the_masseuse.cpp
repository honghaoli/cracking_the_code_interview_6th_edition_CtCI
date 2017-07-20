//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * A popular masseuse receives a sequence of back-to-back appointment request and is debating which ones to accept. She needs a 15-minute break between appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appointment requests (all multiples of 15 minutes, none overlap, and non can be moved), find the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.
 * EXAMPLE:
 *    INPUT:    {30, 15, 60, 75, 45, 15, 15, 45}
 *    OUTPUT:   180 minutes   ({30, 60, 45, 45}).
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

