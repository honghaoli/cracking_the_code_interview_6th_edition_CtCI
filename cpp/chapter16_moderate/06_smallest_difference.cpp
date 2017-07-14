//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.
 * EXAMPLE:
 * Input: {1,3,15,11,2}, {23,127,235,19,8}
 * Output:  3.  That is, the pair (11, 8)
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Sort both arrays, then check alternatively two elements.
 */
int min_diff(vector<int> &v1, vector<int> &v2) {
  // boundary check
  if (v1.size() == 0 || v2.size() == 0) {
    printf("Wrong input!!!\n");
    return -1;
  }
  // sort both arrays
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  // find the min diff
  int i1 = 0, i2 = 0;
  int d = abs(v1[i1] - v2[i2]);
  while (i1 < v1.size() && i2 < v2.size()) {
    if (v1[i1] > v2[i2]) {
      i2++;
    } else if (v1[i1] < v2[i2]) {
      i1++;
    } else {
      return d;
    }
    d = min(d, abs(v1[i1] - v2[i2]));
  }
  //
  return d;
};

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
    vector<int> v1 {1,3,15,11,2};
    vector<int> v2 {23,127,235,19,8};
    cout << endl;
    print_vector(v1);
    print_vector(v2);
    printf("The min diff is: %d\n", min_diff(v1, v2));
  }
  void test2() {
    vector<int> v1 {1,3,15,11,2,126};
    vector<int> v2 {23,127,235,19,8};
    cout << endl;
    print_vector(v1);
    print_vector(v2);
    printf("The min diff is: %d\n", min_diff(v1, v2));
  }
  void test3() {
    vector<int> v1 {1,3,15,11,2,127};
    vector<int> v2 {23,127,235,19,8,3};
    cout << endl;
    print_vector(v1);
    print_vector(v2);
    printf("The min diff is: %d\n", min_diff(v1, v2));
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
    test2();
    test3();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

