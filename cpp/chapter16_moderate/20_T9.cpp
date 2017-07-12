//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit mapped to a set of 0-4 letters. Implement an algorithm to return a list of matching words, given a sequence of digits. You are provided a list of valid words (provided in whatever data structure you'd like). The mapping is shown in the diagram below:
 *
 *              1         2          3
 *                       abc        def
 *
 *              4         5          6
 *             ghi       jkl        mno
 *
 *              7         8          9
 *             pqrs      tuv        wxyz
 *
 *                        0
 *
 * EXAMPLE:
 *    Input:      8733
 *    Output:     tree, used
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

