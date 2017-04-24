//
// Created by Honghao Li on 4/22/17.
//



// Problem 01
// A child is running up a stircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// 1st method
// top-down dynamic programming
long steps(int n, vector<long>& d) {
  if (d[n] > 0L)
    return d[n];
  //
  if (n == 1)
    return 1L;
  else if (n == 2)    // 1,1  2
    return 2L;
  else if (n == 3)    // 1,1,1  1,2   2,1   3
    return 4L;
  //
  long s = steps(n-1, d) + steps(n-2, d) + steps(n-3, d);
  d[n] = s;
  return s;
}

long solve(int n) {
  vector<long> d;
  for (int i = 0; i < n; ++i) {
    d.push_back(-1L);
  }
  return steps(n, d);
}

// 2nd method
// bottom-up dynamic programming
// and remove the redundant array
long steps2(int n) {
  if (n == 1)
    return 1L;
  else if (n == 2)    // 1,1  2
    return 2L;
  else if (n == 3)    // 1,1,1  1,2   2,1   3
    return 4L;
  //
  long s = 0L;
  long s1 = 4L;
  long s2 = 2L;
  long s3 = 1L;
  for (int i = 4; i < n; ++i) {
    s = s1 + s2 + s3;
    s3 = s2;
    s2 = s1;
    s1 = s;
  }
  s = s1 + s2 + s3;
  return s;
}


long solve2(int n) {
  return steps2(n);
}


////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here
    printf("%d, %ld\n", 20, solve(20));
    printf("%d, %ld\n", 20, solve2(20));
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}



