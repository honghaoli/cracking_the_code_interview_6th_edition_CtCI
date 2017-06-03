//
// Created by Honghao Li on 5/28/17.
//

// PROBLEM
// You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.


//////// IMPORTANT!!! ///////////
// C++ takes << >> as arithmetic shifts for signed integers and logical shifts for unsigned integers!!!  https://en.wikipedia.org/wiki/Logical_shift



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
// Everytime it shifts one bit to check 1 or 0, and use (num & 0b10) to see if two 1s sequences are connected by one 0.
// last length =  (num & 2) ? 0 : current length
// maxlength = max(last + current + 1, maxlength)
////////////////////////////////////////////////////////
// Important to convert the input number to unsigned to make sure it's logical shift!!!
////////////////////////////////////////////////////////
int longest_1s_2(unsigned int num) {
  const int size = 32;  // 32 bit for integer
  int last = 0, current = 0;  // 1s sequences
  int length = 0;

  for (int i = 0; i <= size; ++i) { // loop size+1 times, make sure the last (or extra) bit is always zero, to execute the 2nd part code.
//    cout << num << " = " << bitset<32>(num) << endl << flush;
    if (num & 1 == 1) {
      current++;
    } else {
//      printf("current = %d, last = %d, length = %d, \n", current, last, length);
      length = max(last + current + 1, length);
      last = (num & 2) ? current : 0;
      current = 0;
    }
    num >>= 1;
  }

//  // all 1 bits, at most 32 bits
  if (length > size)
    return size;

  return length;
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

  void test(int n) {
//    cout << n << " = " << bitset<32>(n) << ", has longest " << longest_1s(n) << endl;
    cout << n << " = " << bitset<32>(n) << ", has longest " << longest_1s_2(n) << endl;
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

