//
// Created by Honghao Li on 5/28/17.
//


// PROBLEM
// Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR".

// ?? How do you define "accurately"???
// The problem is badly described! Just say:
// convert a real number between 0 and 1 into 0.101010101....  at most 32 characters, number out of range (0, 1) should print "ERROR".




#include <cstdio>
#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;


//////////////////////// Solutions ///////////////////////////////

// 1st method
// According to the book solution
// every time multiply by 2 and check if that part is larger/equal than 1
// Assume double is 64 bits
#define ND 64
bitset<ND> convert_double(double r) {
  bitset<ND> bits;
  if (r <= 0.0 || r >= 1.0) {
    printf("Error!");
    return bits;
  }
  for (int i = ND - 1; i >= 0; --i) {
    r *= 2;
    if (r >= 1.0) {
      bits[i] = 1;
      r -= 1.0;
    } else {
      bits[i] = 0;
    }
  }
  return bits;
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

  void test(double r) {
    auto bits = convert_double(r);
    cout << setw(10) << r << " = 0." << bits << endl;
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    printf("double has %d bytes\n", sizeof(double));
    // customize your own tests here

    //
    test(1.0);
    test(0.0);
    test(0.5);
    test(0.25);
    test(0.125);
    test(0.75);
    test(0.7);
    test(0.0000000000001);


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

