//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  Given a sorted array of strings that is interspersed with empty strings, write method to find the location of a given string.
 *  EXAMPLE:
 *  Input: ball, {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}.
 *  Output:   4
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
// use standard binary search, every time mid hit an empty string, simply find the nearest non-empty string.
int binary_search(vector<string> &vec, int lo, int hi, string &target) {
  if (hi < lo)
    return -1;

  int mid = (hi - lo) / 2 + lo;
  if (vec[mid] == target)   // if target is empty string, return any empty string index.
    return mid;

  // if mid is empty string, find the nearest non-empty string
  int mid2 = mid;
  // search left
  while (vec[mid2] == "" && mid2 >= lo) {
    mid2--;
  }

  // all left strings are empty string
  if (mid2 < lo)
    return binary_search(vec, mid+1, hi, target);

  if (vec[mid2] == target)
    return mid2;
  if (vec[mid2] > target)
    return binary_search(vec, lo, mid2-1, target);
  if (vec[mid2] < target)
    return binary_search(vec, mid+1, hi, target);
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

  void test(vector<string> &vec, string &target) {
    printf("\nFind %s in vector: ", target.c_str());
    print_vector(vec);
    printf("The index is %d.\n", binary_search(vec, 0, vec.size()-1, target));
  }

  void test1() {
    vector<string> vec;
    string target;
    vec = {"aa", "bb", "cc", "dd"};
    target = "aa";
    test(vec, target);
    target = "bb";
    test(vec, target);
    target = "cc";
    test(vec, target);
    target = "dd";
    test(vec, target);
    target = "ee";
    test(vec, target);
  }

  void test2() {
    vector<string> vec;
    string target;
    vec = vector<string>(20, "");
    vec[3] = "aa";
    vec[8] = "bb";
    vec[15] = "cc";
    vec[16] = "dd";
    target = "aa";
    test(vec, target);
    target = "bb";
    test(vec, target);
    target = "cc";
    test(vec, target);
    target = "dd";
    test(vec, target);
    target = "ee";
    test(vec, target);
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

