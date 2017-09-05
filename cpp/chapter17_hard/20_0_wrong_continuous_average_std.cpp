//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Numbers are randomly generated and passed to a method. Write a program to find and maintain the average values and std as new values are generated.
 */

/*
 * This is a classic problem!
 * Actually we could expand it to calculate the median and the variance at the same time! on-the-fly!.
 */


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * new = (old * N + value) / (N + 1)
 */
class Stats {
 public:
  Stats() : N(0), average(0) {}

  double get_average() { return average; }

  void add(double value) {
    average = (average * N + value) / (N + 1);
    N++;
  }

 private:
  int N;
  double average;

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

  void test(vector<double> &input) {
    cout << endl << "input: " << endl;
    print_vector(input);
    Stats s = Stats();
    cout << "average: " << endl;
    for (auto &v : input) {
      s.add(v);
      cout << s.get_average() << ", ";
    }
    cout << endl;
  }

  void unit_test() {
    vector<double> input;
    input = {1,2,3,4,5,6,7,8,9,10};
    test(input);
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

