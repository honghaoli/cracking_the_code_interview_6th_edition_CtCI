//
// Created by Honghao Li on 4/22/17.
//

// Problem 03
// A magic index in an array A [0...n-1] is defined to be an index such that A[i] = i. given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
// FOLLOW UP
// What if the values are not distinct?

#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

// 1st method
// brutal force
int find_magic(vector<int> &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] == i)
      return i;
  }
  // not found magic index
  return -1;
}


// 2nd method
// TODO: a faster method as describled in the textbook



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here
    vector<int> v{3,2,1,5,4,8,7,6};
    printf("magic index is: %d\n", find_magic(v));
    v = {1,2,3,4,5,6,7,8};
    printf("magic index is: %d\n", find_magic(v));

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

