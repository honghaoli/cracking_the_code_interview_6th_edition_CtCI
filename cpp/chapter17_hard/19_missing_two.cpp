//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * You are given an array with all the numbers from 1 to N appearing exactly once, except for one number that is missing. How can you find the missing number in O(N) time and O(1) space?  What if there were two number missing?
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * For one number missing:
 *        calculate the sum, compare it with 1+2+3+...+N
 * For two number missing:
 *        Do the same, find the sum of m1 + m2;
 *        then calculate the sum of all numbers smaller than (m1 + m2)/2, to find the m1, then find the m2;
 */
int find_one_missing(vector<int> &input) {
  int sum = 0;   // in case overflow, will this work?
  for (int i = 0; i < input.size(); ++i) {
    sum += input[i];
  }
  int perfect_sum = (2 + input.size()) * (1 + input.size()) / 2;
//  printf("sum: %d, perfect sum: %d\n", sum, perfect_sum);
  return perfect_sum - sum;
}


vector<int> find_two_missing(vector<int> &input) {
  int N = input.size() + 2;
  int perfect_sum = (N + 1) * (N) / 2;

  int sum = 0;
  for (int i = 0; i < input.size(); ++i) {
    sum += input[i];
  }
  int two_sum = perfect_sum - sum;

  int half_sum = 0;
  int mid = two_sum/2;
  int perfect_half_sum = (mid + 1) * (mid) / 2;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] <= mid)
      half_sum += input[i];
  }
  int m1 = perfect_half_sum - half_sum;
  int m2 = two_sum - m1;
  return vector<int>{m1, m2};
}


/*
 * Thoughts
 * The book solution for two missing number is more complicated and trouble-some than my algorithm. :)
 * It calcualtes 1^2 + 2^2 + 3^2 + ... + N^2 as another sum2, then solve the two values from a 2nd-order equation...
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

  void test(int N, int miss) {
    vector<int> input;
    for (int i = 1; i <= N; ++i) {
      if (i != miss) {
        input.push_back(i);
      }
    }
//    print_vector(input);
    printf("missing %d, calculated %d\n", miss, find_one_missing(input));
  }

  void test(int N, int miss1, int miss2) {
    vector<int> input;
    for (int i = 1; i <= N; ++i) {
      if (i != miss1 && i != miss2) {
        input.push_back(i);
      }
    }
    auto result = find_two_missing(input);
    int m1 = result.at(0);
    int m2 = result.at(1);
    printf("missing %d and %d, calculated %d and %d\n", miss1, miss2, m1, m2);
  }

  void unit_test() {
    // one missing
    test(5, 1);
    test(100, 99);

    cout << endl;
    // two missing
    test(5, 1, 2);
    test(100, 3, 9);
    test(100, 55, 56);
    test(999, 7, 9);
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

