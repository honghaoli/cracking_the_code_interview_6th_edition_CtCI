//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include "../lib/helper.h"


using namespace std;



// 1st method
// a typical merge sort
// not easy to create a buffer here.
// the book solution use a index for the last element to indicates the buffer.
// Also, it avoids copying the array by start from the last, and find the max to store in the back.
// we'll use fixed array to do this.
void merge_b_into_a(int b[], int len_b, int a[], int len_a) {
  int n = len_a + len_b -1;
  int ia = len_a - 1;
  int ib = len_b - 1;
  while (ib >= 0) {
    if (ia >= 0 && a[ia] > b[ib]) {
      a[n--] = a[ia--];
    } else {
      a[n--] = b[ib--];
    }
  }
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

  void print_array(int a[], int length) {
    cout << "array: ";
    for (int i = 0; i < length; ++i) {
      cout << a[i] << ", ";
    }
    cout << endl;
  }

  void test1() {
    int a[] = {1,2,3,4,5,0,0,0,0,0,0,0,0,0};
    int b[] = {6,7,8,9,10};
    merge_b_into_a(b, 5, a, 5);
    print_array(a, sizeof(a) / sizeof(*a));
  }
  void test2() {
    int a[] = {6,7,8,9,10,0,0,0,0,0,0,0,0,0};
    int b[] = {1,2,3,4,5};
    merge_b_into_a(b, 5, a, 5);
    print_array(a, sizeof(a) / sizeof(*a));
  }
  void test3() {
    int a[] = {2,4,6,8,10,0,0,0,0,0,0,0,0,0};
    int b[] = {1,3,5,7,9};
    merge_b_into_a(b, 5, a, 5);
    print_array(a, sizeof(a) / sizeof(*a));
  }
  void test4() {
    int a[] = {2,4,6,8,100,0,0,0,0,0,0,0,0,0};
    int b[] = {1,10};
    merge_b_into_a(b, 2, a, 5);
    print_array(a, sizeof(a) / sizeof(*a));
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
    test2();
    test3();
    test4();

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

