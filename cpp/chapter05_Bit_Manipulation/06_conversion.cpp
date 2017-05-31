//
// Created by Honghao Li on 5/28/17.
//


// PROBLEM
// Write a function to determine the number of bits you would need to flip to convert integer A to B.





#include <cstdio>
#include <iostream>
#include <bitset>
#include <limits>

using namespace std;


//////////////////////// Solutions ///////////////////////////////

// 1st method
// simply use XOR
int flips(int n, int m) {
  int num = 0;
  auto bits = bitset<32>(n ^ m);
  for (int i = 0; i < 32; ++i) {
    if (bits[i] == 1)
      num++;
  }
  return num;
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

  void test(int n, int m) {
    cout << n << " = " << bitset<32>(n) << endl
         << m << " = " << bitset<32>(m) << endl
         << "needs " << flips(n, m) << " flips\n";
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    //
    test(numeric_limits<int>::max(), numeric_limits<int>::min());
    test(0, -1);
    test(0, 1);
    test(0b1101, 0);
    test(0b1101101, 2);
    test(0b1011011, 0b11011);
    test(0b11110011011, 0b100);
    test(0b111110011011, 0b111110011011);
    test(0b1011111011011, 0b1011111011011);


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

