//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Write a recursive function to multiply two positive integers without using the * operator. You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations.



#include <cstdio>


using namespace std;



// 1st method
// shift bit to do multiplication, notice it's the same for negative number.
// since the problem requires recursive function..
int shift_sum(unsigned int n, unsigned int m) {  // use unsigned to make sure logical shift.
  if (!m)
    return 0;
  if (m & 1)
    return n + shift_sum(n << 1, m >> 1);
  else
    return shift_sum(n << 1, m >> 1);
}


int multiply(int n, int m) {
  return shift_sum(n, m);
}

// 2nd method
// the book solution looks ugly.



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
    printf("%d * %d = %d\n", n, m, multiply(n, m));
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test(0, 0);
    test(0, 5);
    test(0, -5);
    test(1, -1);
    test(-1, -1);
    test(1, 1);
    test(1, 2);
    test(1, 1234);
    test(2, 4);
    test(111, 111);
    test(9, 9);
    test(-3, 112);
    test(-9, -9);
    test(-9, 9);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
