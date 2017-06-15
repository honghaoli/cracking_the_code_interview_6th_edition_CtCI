//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.
 *  EXAMPLE:
 *  Input: find 5 in {15, 16, 19, 20, 1, 3, 4, 5, 7, 10, 14}
 *  Output:  8 (the index of 5 in the array)
 */


/*
 * What is the definition of array rotation?????????!!!!!!!
 * see LeetCode website for better articulation:
 * https://leetcode.com/problems/rotate-array/#/description
 * Rotate an array of n elements to the right by k steps.
    For example, with n = 7 and k = 3,
    the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 */



#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
// Note the rotation will not change the relative order in the array. There are two separate pieces, first > second. So the only difference is the start point or the smallest item.
// still use binary search, only consider the separate point.

int find_idx(vector<int> &vec, int lo, int hi, int target) {
  if (hi < lo)
    return -1;

  int mid = (hi - lo) / 2 + lo;
  int iter = vec[mid];

  if (iter < target) {
    if (iter > vec[lo]) {
      lo = mid + 1;
      return find_idx(vec, lo, hi, target);
    } // else, mid is in 2nd part.
    if (vec[hi] < target) {
      hi = mid - 1;
      return find_idx(vec, lo, hi, target);
    } else if (vec[hi] > target) {
      lo = mid + 1;
      return find_idx(vec, lo, hi, target);
    } else {
      return hi;
    }
  } else if (iter > target) {
    if (iter < vec[hi]) {
      hi = mid - 1;
      return find_idx(vec, lo, hi, target);
    } // else, mid is in 1st part
    if (vec[lo] > target) {
      lo = mid + 1;
      return find_idx(vec, lo, hi, target);
    } else if (vec[lo] < target) {
      hi = mid - 1;
      return find_idx(vec, lo, hi, target);
    } else {
      return lo;
    }
  } else {    // vec[mid] == iter.
    return mid;
  }

  //
  cerr << "logical error! lo: " << lo<< ", mid: " << mid << ", hi: " << mid << ", target: " << mid << ".\n" << flush;
  exit(EXIT_FAILURE);
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

  void test(vector<int> &vec, int target) {
    printf("\nFind %d in vector: ", target);
    print_vector(vec);
    printf("The index is %d.\n", find_idx(vec, 0, vec.size()-1, target));
  }

  void test_all_values(vector<int> &vec) {
    for (auto i : vec) {
      test(vec, i);
    }
  }

  void test_all_rotations(vector<int> &vec) {

  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    vector<int> vec;
    vec = {1,2,3,4,5,6,7};
    test_all_values(vec);
    printf("====================");
    vec = {5,6,7,1,2,3,4};
    test_all_values(vec);
    printf("====================");
    vec = {7,1,2,3,4,5,6};
    test_all_values(vec);
    printf("====================");
    vec = {2,3,4,5,6,7,1};
    test_all_values(vec);
    printf("====================");

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

