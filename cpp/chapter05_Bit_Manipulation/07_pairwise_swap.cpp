//
// Created by Honghao Li on 5/28/17.
//


// PROBLEM
// Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).






#include <cstdio>
#include <iostream>
#include <bitset>
#include <limits>
#include <iomanip>

using namespace std;


//////////////////////// Solutions ///////////////////////////////

// 1st method
// use two masks to store the odd and even bits.
// two shifts, two ANDs, one OR. total 5 operations.
int swap(int n) {
  // assume the integer is 32 bit
  int mask_odd  = 0b10101010101010101010101010101010;
  int mask_even = 0b01010101010101010101010101010101;
  return ((n << 1) & mask_odd) | ((n >> 1) & mask_even);
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

  void test(int n) {
    int m = swap(n);
    cout << setw(12) << n << " = " << bitset<32>(n) << endl
         << setw(12) << m << " = " << bitset<32>(m) << endl << endl;
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    //
    test(numeric_limits<int>::min());
    test(numeric_limits<int>::max());
    test(-1);
    test(0);
    test(1);
    test(0b1101);
    test(0b1101101);
    test(0b1011011);
    test(0b11110011011);
    test(0b111110011011);
    test(0b1011111011011);


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

