//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given a string b and an array of smaller strings T, design a method to search b for each small string in T.
 */


/*
 * Suppose the big string b has m chars;
 * the array of T has n elements;
 * It's actually a sub-string search problem.
 */
/*
 * By brutal force:
 * search a sub-string in b would take O(m^2) time.
 */


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Convert b into a trie: ~ O(b^2)
 * the longest string in T has k chars;
 * Each search needs ~ O(k);
 * So total ~ O(b^2 + k*n)
 */



// 2nd method
/*
 *  The book solution
 *  Convert T into a trie: ~ O(k*n)
 *  search all strings: ~ O(b*k)
 *  total ~ O(bk + kn)
 */



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test1() {
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

