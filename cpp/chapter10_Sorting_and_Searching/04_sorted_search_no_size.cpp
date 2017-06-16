//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  You are given an array-like data structure Listy which lacks a size method. It does, however, have an elementAt(i) method that returns the element at index i in O(1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data structure only supports positive integers.) Given a List which contains sorted, positive integers, find the index at which an element x occurs. If x occurs multiple times, you may return any index.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
// It still a typical binary search with guessing the size.

// standard binary search, with guaranteed hi < size
int binary_search(vector<int> &vec, int lo, int hi, int target) {
  if (hi < lo)
    return -1;

  int mid = (hi - lo) / 2 + lo;
  if (target == vec[mid])
    return mid;

  if (vec[mid] > target) {
    return binary_search(vec, lo, mid-1, target);
  } else {
    return binary_search(vec, mid+1, hi, target);
  }
}


// first find the range, then do standard binary search
int find_idx(vector<int> &vec, int lo, int hi, int target) {
  if (vec[lo] < 0 || hi < lo)
    return -1;

  int mid = (hi - lo) / 2 + lo;

  // hi is out of boundary
  if (vec[hi] < 0) {
    if (vec[mid] < 0)   // mid also out of boundary
      return find_idx(vec, lo, mid-1, target);
    else if (vec[mid] < target)   // check mid --- hi
      return find_idx(vec, mid+1, hi-1, target);
    else  // check lo --- mid
      return find_idx(vec, lo, mid, target);
  }

  // hi is in boundary
  if (vec[hi] == target)
    return hi;
  else if (vec[hi] > target)    // search lo --- hi
    return binary_search(vec, lo, hi-1, target);
  else      // try hi --- 2 * hi, where 2*hi may be out of boundary
    return find_idx(vec, hi+1, 2 * hi, target);
}


// set initial range to 0-1, this value can be changed.
int find_idx_no_size(vector<int> &vec, int target) {
  return find_idx(vec, 0, 1, target);
}







// 2nd method
// The book solution is more concise!!!
// 1. the same, find the range;
// 2. treat the -1 as infinity when comparing, neat!
int binary_search2(vector<int> &vec, int lo, int hi, int target) {
  if (hi < lo)
    return -1;

  int mid = (hi - lo) / 2 + lo;
  if (target == vec[mid])
    return mid;

  if (vec[mid] > target || vec[mid] == -1) {  // -1 means infinity, move to left part.
    return binary_search2(vec, lo, mid-1, target);
  } else {
    return binary_search2(vec, mid+1, hi, target);
  }

}


int find_idx2(vector<int> &vec, int target) {
  int idx = 1;

  // NOTE: vec.size >= 2
  while (vec[idx] != -1 && vec[idx] < target) //
    idx *= 2;

  // very neat, since 1/2 = 0;
  return binary_search2(vec, idx/2, idx, target);
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

  void test(vector<int> vec, int target) {
    printf("\nFind %d in vector: ", target);
    print_vector(vec);

    // stuff out of boundary with enough -1 to simulate the data structure defined in the problem
    int n = vec.size();
    for (int i = 0; i < n; ++i) {    // at least put one for empty vector
      vec.push_back(-1);
    }
    // for method 1, we need at least one -1 for empty array.
    vec.push_back(-1);
    // for method 2, we need at least size of two for the while loop.
    vec.push_back(-1);

//    printf("The index is %d.\n", find_idx_no_size(vec, target));
    printf("The index is %d.\n", find_idx2(vec, target));
  }

  void test_all_values(vector<int> &vec) {
    for (auto i : vec) {
      test(vec, i);
    }
  }


  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here


    vector<int> vec;
    vec = {1,2,3,4,5,6,7};
    test_all_values(vec);
    printf("====================");

    test(vec, 0);
    test(vec, 8);

    vec = {2,2,2,2,2,3,3};
    test(vec, 2);
    test(vec, 3);
    printf("====================");
    vec = {2,2,2,2,3,5,5};
    test(vec, 2);
    test(vec, 3);
    test(vec, 5);
    printf("====================");

    vec = {};
    test(vec, 1);
    printf("====================");
    vec = {1};
    test(vec, 1);
    test(vec, 2);
    printf("====================");


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

