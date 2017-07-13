//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Write an algorithm which computes the number of trailing zeros in n factorial.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Every X0 contribute one 0;
 * Every 5 and any of (2, 4, 6, 8) combined, contribute one 0;
 * notice the number of 2,4,6,8s is always > number of 5s.
 */
// Inspired by the book. this is wrong!!! because 25 contributes two 5s.
//int zeros(int num) {
//  if (num <= 0)
//    return 0;
//  int n10 = num / 10;
//  int n5 = n10;
//  if (num % 10 >= 5)
//    n5++;
//  return n10 + n5;
//}

/*
 * A modified version of above method, consider 25,125... has more 5s etc.
 * and 10s can be considered as 5s too.
 */
int zeros(int num) {
  if (num <= 0)
    return 0;
  // all 5s, including 10s.
  num /= 5;
  int n = num;
  // extra 5s
  while (num >= 5) {
    n++;
    num /= 5;
  }
  return n;
}

// 2nd method
/*
 * More elegant book solution
 */
int zeros_book(int num) {
  if (num <= 0)
    return 0;
  int n = 0;
  for (int i = 5; num / i > 0; i *= 5) {
    n += num / i;
  }
  return n;

}



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
    vector<int> tests {0,1,2,3,4,5,9,10,14,15,16,20,21,24,25,26};
    for (auto &i : tests) {
//      printf("zeros for %d!: %d\n", i, zeros(i));
      printf("zeros for %d!: %d\n", i, zeros_book(i));
    }
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

