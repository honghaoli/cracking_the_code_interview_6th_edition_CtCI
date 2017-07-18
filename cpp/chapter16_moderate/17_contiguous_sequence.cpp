//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum.
 * EXAMPLE:
 * Input:   2, -8, 3, -2, 4, -10
 * Output:  5 (i.e., {3, -2, 4})
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * The book solution:
 * consider alternating pos/neg sequences, if the sequence < 0, no need to add that sequence, otherwise add it.
 */
int max_sum(vector<int> &vec) {
  // assume the min max = 0, if all values are negative, the sequence has 0 element.
  int maxsum = 0;
  int sum = 0;
  for (auto &i : vec) {
    sum += i;
    if (maxsum < sum) {
      maxsum = sum;
    } else {  // negative element.
      if (sum < 0)
        sum = 0;
    }
  }
  return maxsum;
}

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

  void test(vector<int> &input) {
    printf("\n");
    print_vector(input);
    printf("The max sum: %d\n", max_sum(input));
  }

  void unit_test() {
    vector<int> vec;
    vec = {2, -8, 3, -2, 4, -10};
    test(vec);
    vec = {-1, -1, -1};
    test(vec);
    vec = {};
    test(vec);
    vec = {5, -9, 6, -2, 3};
    test(vec);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    unit_test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

