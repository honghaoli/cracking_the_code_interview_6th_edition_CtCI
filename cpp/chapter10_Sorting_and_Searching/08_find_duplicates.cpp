//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  You have an array with all the numbers from 1 to N, where N is at most 32,000. The array may have duplicate entries and you do not know what N is. With only 4 kilobytes of memory available, how would you print all duplicate elements in the array?
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * short integer 2 bytes are enough for numbers <= 32000;
 * so 4kb is enough for 2000 shorts.
 * make a chunk from 0 - 1999, go through all numbers in the array, find duplicates in the range of 0-1999; then choose next chunk 2000-39999, go through again..
 */

// 2nd method
/*
 * Book solution
 * 4kb = 32 * 2^10 > 32000, so create a bit vector<32000>.
 */



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test() {
  }

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

