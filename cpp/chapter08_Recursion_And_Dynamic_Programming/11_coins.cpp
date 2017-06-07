//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing n cents.



#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;



// 1st method
// consider from big to small
int num(int cents, int money) {
  return cents / money;
}

int total(int n) {
  if (n <= 0)   // boundary cases
    return 0;
  int m = 0;
  int n25 = num(n, 25);
  for (int i = 0; i <= n25; ++i) {
    int n10 = num(n - 25 * i, 10);
    for (int j = 0; j <= n10; ++j) {
      int n5 = num(n - 25 * i - 10 * j, 5);
      for (int k = 0; k <= n5; ++k) {
        m++;
        // for visual debug.
        printf("%d = %d x 25 + %d x 10 + %d x 5 + %d x 1\n", n, i, j, k, n - 25*i - 10*j - 5*k);
      }
    }
  }
  return m;
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
    int num = total(n);
    printf("%d has %d ways to represent.\n\n", n, num);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test(0);
    test(1);
    test(2);
    test(5);
    test(6);
    test(10);
    test(11);
    test(24);
    test(25);
    test(26);
    test(30);
    test(35);
    test(40);
    test(41);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

