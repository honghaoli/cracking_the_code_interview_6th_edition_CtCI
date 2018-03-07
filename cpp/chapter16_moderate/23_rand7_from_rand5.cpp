//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Implement a method rand7() given rand5(). That is, given a method that generates a random number between 0 and 4 (inclusive), write a method that generates a random number between 0 and 6 (inclusive).
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
// This is wrong!!!!
// it's 5^7, NOT 7^5!!!
/*
 * Image we have n digits, each digit has m possible values
 * Then the total number of possible values are n^m.
 * here n = 7, m = 5. 7^5 % 7 == 0.
 * Note all values from 11111... to mmmmm... are equally possible.
 * so all 7^5 values are equally distributed when mod 7.
 *
 * Thus, we need to do 7 times rand5(), and convert into a 7 digits, then map this value into 0~6.
 */




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

  void test() {
    int N = 100000;
    printf("Test rand5():\t average: %f\n", N / static_cast<double>(5));
    vector<int> r5 {0,0,0,0,0};
    for (int i = 0; i < N; ++i) {
      r5[rand5()]++;
    }
    print_vector(r5);
    //
    printf("Test rand7():\t average: %f\n", N / static_cast<double>(7));
    vector<int> r7 {0,0,0,0,0,0,0};
    for (int i = 0; i < N; ++i) {
      r7[rand7()]++;
    }
    print_vector(r7);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

