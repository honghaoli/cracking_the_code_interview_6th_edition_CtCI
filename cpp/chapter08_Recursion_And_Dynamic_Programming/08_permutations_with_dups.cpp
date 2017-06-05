//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Write a method to compute all permutations of a string whose characters are not necessarily unique. The list of permutations should not have duplicates.




#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include "../lib/helper.h"


using namespace std;

// 1st method



// 2nd method
// A direct extension from last problem.
vector<string> perms(string str) {
  if (str.size() == 0)
    return vector<string> {};
  if (str.size() == 1)
    return vector<string> {str};
  vector<string> ss;
  vector<int> hash (256, 0);   // simple hash for ASCII
  for (int i = 0; i < str.size(); ++i) {
    if (hash[str[i]] > 0)
      continue;
    for (string &s : perms(str.substr(0, i) + str.substr(i + 1, str.size() - i - 1))) {
      ss.push_back(str[i] + s);
    }
    hash[str[i]] = 1;
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
    test("aaaaaaaaaaaaaaaaaaaa");
    test("1aaaaaaaaaaaaaaaaaaa");
    test("112233");

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}



