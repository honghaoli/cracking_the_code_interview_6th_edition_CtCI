//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Numbers are randomly generated and passed to a method. Write a program to find and maintain the median values as new values are generated.
 */



#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * The book solution
 * Two heaps to maintain the left and right part of the median
 */


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
    cout << "medians: " << endl;
    for (auto &v : input) {
      cout << ", ";
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

