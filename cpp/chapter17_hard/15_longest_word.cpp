//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given a list of words, write a program to find the longest word made of other words in the list.
 * EXAMPLE:
 *    INPUT:    cat, banana, dog, nana, walk, walker, dogwalker
 *    OUTPUT:   dogwalker
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

