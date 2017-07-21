//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Shuffle and take the first m element.
 * Too easy to implement
 * but shuffle is ~ O(n)
 * we can reduce it to ~ O(m) use the same method.
 */

default_random_engine generator;

// both lo and hi are inclusive.
int random_range(int lo, int hi) {
  uniform_int_distribution<int> distribution(lo, hi);
  return distribution(generator);
}


vector<int> random_m(vector<int> &input, int m) {
  vector<int> result;
  // boundary check
  if (m > input.size())
    return result;

  for (int i = 0; i < m; ++i) {   // last element can only exchange with itself.
    int idx = random_range(i, input.size() - 1);
    // exchange i and idx.
    int tmp = input[idx];
    input[idx] = input[i];
    input[i] = tmp;
    result.push_back(tmp);
  }

  return result;
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

  void test(vector<int> vec, int m, int N) {
    print_vector(vec);
    printf("shuffle %d times, the first %d element:\n", N, m);
    for (int i = 0; i < N; ++i) {
      auto result = random_m(vec, m);
      print_vector(result);
    }
  }

  void unit_test() {
    test({1,2,3,4,5,6,7,8,9,0}, 3, 20);
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

