//
// Created by Honghao Li on 4/22/17.
//


// Problem
// Write a method to compute all permutations of a string of unique characters.



#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;

// 1st method
// find the permutations for n-1 characters, then add the last char to any possible place.
// or exchange the last char with any other chars.
// however this method will be not easy to extend to string with identical chars.



// 2nd method
// choose any char as the 1st char, then add all possible permutation of the rest n - 1 chars.
// this could be easily extended to next problem
vector<string> perms(string str) {
  if (str.size() == 0)
    return vector<string> {};
  if (str.size() == 1)
    return vector<string> {str};
  vector<string> ss;
  for (int i = 0; i < str.size(); ++i) {
    for (string &s : perms(str.substr(0, i) + str.substr(i + 1, str.size() - i - 1))) {
      ss.push_back(str[i] + s);
    }
  }
  return ss;
}


////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

  void test(string str) {
    auto ss = perms(str);
    cout << str << " has "<< ss.size() << " permutations:\t";
    print_vector(ss);
  }

 private:
  int num_fail = 0;

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test("");
    test("0");
    test("a");
    test("12");
    test("xyz");
    test("abc123");

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

