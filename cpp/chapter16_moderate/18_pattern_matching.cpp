//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Pattern Matching: You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern with a string. For example, the string "catcatgocatgo" matches the pattern aabab (where cat is a and go is b). It also matches pattern like a, ab, and b. Write a method to determine if value matches pattern.
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

