//
// Created by Honghao Li on 5/28/17.
//

// Problem
// You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M stars at big j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
// EXAMPLE:
// INPUT:   N = 10000000000, M = 10011, i = 2, j = 6;
// OUTPUT:  N = 10001001100





#include <cstdio>
#include <iostream>

using namespace std;


//////////////////////// Solutions ///////////////////////////////

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

    //


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
