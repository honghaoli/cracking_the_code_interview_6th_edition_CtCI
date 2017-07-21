//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 *  record the difference number of letters and digits (sum from the start to index)
 *  for example:            a  a  1  1  1  1  1  1  a  a
 *    letter - digits: (0)  1  2  1  0 -1 -2 -3 -4 -3 -2
 *
 *    0 could be the end index
 *                     ---------------  length = 4
 *           or
 *    find the same sum:                  -2          -2
 *                                        ---------------  length = 4
 *
 *    use hashmap, ~ O(n)
 */

bool charIsDigit(char &c) {
  if (c >= 48 && c <= 57)
    return true;
  return false;
}

bool charIsLetter(char &c) {
  // consider lower/upper case letters
  if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
    return true;
  return false;
}

string substring(string &input) {
  // calculated the difference sums
  vector<int> sums(input.size(), 0);
  int sum = 0;
  for (int i = 0; i < input.size(); ++i) {
    char &c = input[i];
    if (charIsDigit(c))
      sum--;
    else if (charIsLetter(c)) {
      sum++;
    }
    sums[i] = sum;
  }

  //
  int start = 0, end = -1;
  int maxsize = 0;
  unordered_map<int, int> hashmap;

  // elegant solution for 0, see below.
  hashmap[0] = -1;

  for (int i = 0; i < sums.size(); ++i) {
    // if the sum == 0, then substring starts from the beginning
    /*
     * The book solution gives a more elegant solution for this part.
     */
//    if (sums[i] == 0) {
//      int size = i + 1;
//      if (size > maxsize) {
//        maxsize = size;
//        start = 0;
//        end = i;
//      }
//    } else
    // find the same sum in previous position
    if (hashmap.count(sums[i]) != 0) {
      int size = i - hashmap[sums[i]];
      if (size > maxsize) {
        maxsize = size;
        start = hashmap[sums[i]] + 1;
        end = i;
      }
    } else {  // not found this sum, record its index
      hashmap[sums[i]] = i;
    }
  }

  //
  if (end >= start)
    return input.substr(start, maxsize);
  else
    return "";
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

  void test(string input) {
    cout << input << " : " << substring(input) << endl;
  }

  void unit_test() {
    test("aa111111aa");
    test("111111");
    test("aaaaaaa");
    test("");
    test("aaa1aaa");
    test("aa111a111aaa1aaaa1");

    test("aaaa11a11aa1aa1aaaaa");
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

