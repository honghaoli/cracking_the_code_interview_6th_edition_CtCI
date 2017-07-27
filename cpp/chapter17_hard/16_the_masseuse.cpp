//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * A popular masseuse receives a sequence of back-to-back appointment request and is debating which ones to accept. She needs a 15-minute break between appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appointment requests (all multiples of 15 minutes, none overlap, and non can be moved), find the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.
 * EXAMPLE:
 *    INPUT:    {30, 15, 60, 75, 45, 15, 15, 45}
 *    OUTPUT:   180 minutes   ({30, 60, 45, 45}).
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * recursively find the max of a sub-array.
 */

int max_time(vector<int> &input, int start, vector<int> &times) {
  int n = input.size();
  if (start >= n)
    return 0;
  if (times[start] > 0)   // dynamical programming
    return times[start];
  if (start == n - 1) {   // only one elements array
    times[start] = input[n - 1];
    return times[start];
  }
  if (start == n - 2) {  // two elements array
    times[start] = max(input[n - 1], input[n - 2]);
    return times[start];
  }

  times[start] = max(input[start] + max_time(input, start + 2, times), max_time(input, start + 1, times));
  return times[start];
}

int max_time(vector<int> &input) {
  vector<int> times(input.size(), -1);
  return max_time(input, 0, times);
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

  void test() {
    vector<int> input = {30, 15, 60, 75, 45, 15, 15, 45};
    print_vector(input);
    printf("max time: %d.\n", max_time(input));
  }

  void unit_test() {
    test();
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

