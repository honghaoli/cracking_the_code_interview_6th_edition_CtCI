//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Master Mind: The Game of Master Mind is played as follows:
 * The computer has four slots, and each slot will contain a ball that is red (R), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (slot #1,2,3,4 are red,green,green,blue).
 * You, the user, are trying to guess the solution. You might, for example, guess YRGB.
 * When you guess the correct color for the correct slot, you get a "hit". If you gess a color that exists but is in the wrong slot, you get "pseudo-hit". Note that a slot that is a hit can nver count as a pseudo-hit.
 * For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudo-hit. Write a method that, given a guess and a solution, returns the number of hits and pseduo-hits.
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

