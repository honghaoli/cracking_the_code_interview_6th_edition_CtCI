//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Given a boolean expression consisting of the symbols 0 (false), 1 (true), &(AND), | (OR), and ^ (XOR), and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result. The expression should be fully parenthesized (e.g., (0) ^ (1) ) but not extraneously (e.g., (((0)) ^ (1)) ).
// EXAMPLE
// countEval( "1^0|0|1", false) -> 2
// countEval( "0&0&0&1^1|0", true) -> 10




#include <cstdio>
#include <iostream>
#include <vector>


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

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
