//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  In an array of integers, a "peak" is an element which is greater than or equal to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers. For example, in the array {5, 8, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array of integers, sort the array into an alternating sequence of peaks and valleys.
 *  EXAMPLE:
 *  Input: {5, 3, 1, 2, 3}
 *  Output: {5, 1, 3, 2, 3}
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Sort the array first;
 * Then pick the smallest / largest alternatively.
 */

vector<int> peaks_valleys(vector<int> &vec) {
  // sort
  sort(vec.begin(), vec.end());
  //
  int start = 0;
  int end = vec.size() - 1;
  vector<int> result(vec.size(), 0);
  int i = 0;
  while (i < vec.size()) {
    if (i % 2 == 0) {
      result[i] = vec[end--];
    } else {
      result[i] = vec[start++];
    }
    i++;
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

  void test1() {
    vector<int> arr = {5,3,1,2,3};
    print_vector(arr);
    auto result = peaks_valleys(arr);
    print_vector(result);
  }
  void test2() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    print_vector(arr);
    auto result = peaks_valleys(arr);
    print_vector(result);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
    test2();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

