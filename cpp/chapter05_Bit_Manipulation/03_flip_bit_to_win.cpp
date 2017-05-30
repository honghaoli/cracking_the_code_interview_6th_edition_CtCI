//
// Created by Honghao Li on 5/28/17.
//

// PROBLEM
// You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.





#include <cstdio>
#include <iostream>
#include <bitset>
#include <gmpxx.h>

using namespace std;


//////////////////////// Solutions ///////////////////////////////
// Assume the sign bit is included for negative interger.

// 1st method
int longest_1s(int num) {
  const int size = 32;  // 32 bit for integer
  auto bits = bitset<size>(num);
  int last = 0, current = 0;  // 1s sequences
  int length = 0;
  bool can_connect = false;

  for (int i = 0; i < size; ++i) {
    if (bits[i] == 1) {
      current++;
      // check if two pieces can connect or not
      if (i >= 2 && bits[i-1] == 0 && bits[i-2] == 1)
        can_connect = true;
    } else {
      if (can_connect && current + last + 1> length)
        length = current + last + 1;
      else if (current + 1 > length)
        length = current + 1;
//      printf("current = %d, last = %d, length = %d, can_connect = %d\n", current, last, length, can_connect);
      last = current;
      current = 0;
      can_connect = false;
    }
  }

  // if last bit is not zero
  if (can_connect && current + last + 1> length)
    length = current + last + 1;
  else if (current + 1 > length)
    length = current + 1;

//  // all 1 bits, at most 32 bits
  if (length > size)
    return size;

  return length;
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
    cout << n << " = " << bitset<32>(n) << ", has longest " << longest_1s(n) << endl;
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    //
    cout << "Test -1 = " << bitset<32>(-1) << endl;
    cout << endl;

    //
    test(-1);
    test(std::numeric_limits<int>::min());
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

