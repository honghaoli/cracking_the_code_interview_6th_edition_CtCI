//
// Created by Honghao Li on 5/28/17.
//

// PROBLEM
// Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.



// It should be rephrased like: print the smallest and largest number that have the same 1bits, and the number is larger than current integer.



#include <cstdio>
#include <iostream>
#include <bitset>
#include <gmpxx.h>
#include <tuple>

using namespace std;


//////////////////////// Solutions ///////////////////////////////

// 1st method
// largest number, all 1s are in the head part;
// smallest number, change the last 1 of first sequence of 1s and the first 0 after the first sequence of 1s.
// Assume smallest = largest = number integer if no other exists.
tuple<int, int> small_large(int number) {
  const int size = 32;
  auto bits = bitset<size>(number);
  int small, large;

  int last1_before0 = -1;
  int first0_after1 = -1;
  int total1s = 0;
  for (int i = 0; i < size - 1; ++i) {  // exclude sign bit
    if (bits[i] == 1) {
      total1s++;
      if (first0_after1 < 0)
        last1_before0 = i;
    } else {
      if (last1_before0 >= 0 && first0_after1 < 0)
        first0_after1 = i;
    }
  }

  if (last1_before0 < 0) {    // no 1s, so it's zero
    small = 1;
    large = 1 << (size - 2);
  } else if (first0_after1 < 0) {   // otherwise, all 1s are at head part.
    small = number;
    large = number;
  } else {            // general cases
    // change 1 and 0 bit, for smallest
    bits.set(first0_after1, 1);
    bits.set(last1_before0, 0);
    small = bits.to_ulong();
    // large, set the head part with 1s.
    bitset<size> lar = bitset<size>(0);
    for (int i = size - 2; i > size - 2 - total1s && i >= 0 ; --i) { // exclude sign bit
      lar.set(i, 1);
    }
    large = lar.to_ulong();
  }

  return make_tuple(small, large);
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

  void test(int n) {
    int small, large;
    tie(small, large) = small_large(n);
    cout << n << " = " << bitset<32>(n) << "\nnext smallest " << small << " = " << bitset<32>(small) << "\nnext largest " << large << " = " << bitset<32>(large)<< endl;
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    //
//    test(-1);
//    test(std::numeric_limits<int>::min());
    test(std::numeric_limits<int>::max());
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

