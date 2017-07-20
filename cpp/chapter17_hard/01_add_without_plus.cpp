//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Wirte a function that adds two numbers. You should not use + or any arithmetic operators.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * XOR can do add bit without carry
 * carry only happens when both are 1s, so AND can record carry, then carry << 1.
 * the sign bit should also be taken into account.
 */
int add(int n1, int n2) {
  // not consider overflow here.
  unsigned int res = n1 ^ n2;
  unsigned int carry = (n1 & n2) << 1;
//  cout << "n1:      " << bitset<32>(n1) << endl;
//  cout << "n2:      " << bitset<32>(n2) << endl;
//  cout << "res:     " << bitset<32>(res) << endl;
//  cout << "carry:   " << bitset<32>(carry) << endl;
  // This is important!!! We have to do the loop until all carry finished.
  // NOTE  bit manipulation's priority is lower than !=, == condition operator!!!
  // so we must add () around "carry & res"!!!
  while ((carry & res) != 0) {
    unsigned int _res, _carry;
    _res = res;
    _carry = carry;
    res = _res ^ _carry;
    carry = (_res & _carry) << 1;
//    cout << "res:     " << bitset<32>(res) << endl;
//    cout << "carry:   " << bitset<32>(carry) << endl;
//    cout << "result:  " << bitset<32>(carry | res) << endl;
  }
  return (carry) | res;
}



// 2nd method
/*
 * More concise form.
 * The book solution.
 */
int add2(int n1, int n2) {
  while (n2 != 0) {
    int sum = n1 ^ n2;
    int carry = (n1 & n2) << 1;
    n1 = sum;
    n2 = carry;
  }
  return n1;
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

  void test(int n1, int n2) {
//    printf("%d + %d = %d\n", n1, n2, add(n1, n2));
    printf("%d + %d = %d\n", n1, n2, add2(n1, n2));
  }

  void unit_test() {
    test(1, 1);
    test(0, 0);
    test(1, 0);
    test(13, 12);
    test(213, 12);
    test(1234567, 7654321);

    test(-1, 0);
    test(-2, 0);
    test(-2, -1);
    test(-100, -100);
    test(-213, -12);
    test(1234567, -1234567);

    test(00111, 00111);
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

