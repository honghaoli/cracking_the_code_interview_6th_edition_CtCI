//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Pattern Matching: You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern with a string. For example, the string "catcatgocatgo" matches the pattern aabab (where cat is a and go is b). It also matches pattern like a, ab, and b. Write a method to determine if value matches pattern.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Note: pattern a = b, ab = ba.
 * Note: Assume a could equal to b, for example, "tttt" could match "ab".
 * Assume there are i 'a's and j 'b's in the pattern,
 * then value.size() = i * a.size() + j * b.size().
 * a.size(), b.size() >= 1. We can calculate possible sizes first, then check the string.
 */
vector<vector<int>> all_sizes(int total, int na, int nb) {
  vector<vector<int>> result;
  if (na + nb > total)  // not possible, return empty.
    return result;
  if (nb == 0) {
    if (total % na == 0)
      return vector<vector<int>>{{total / na, 0}};
    else
      return result;
  }
  if (na == 0) {
    if (total % nb == 0)
      return vector<vector<int>>{{0, total / nb}};
    else
      return result;
  }

  int maxsizea = total / na;
  for (int i = 1; i <= maxsizea; ++i) {
    int left = total - i * na;
    if (left % nb == 0) {
      int sizeb = left / nb;
      result.push_back(vector<int>{i, sizeb});
//      printf("sizea: %d, sizeb: %d\n", i, sizeb);
    }
  }
  //
  return result;
}

bool didMatch(string &value, string &pattern) {
  // quick boundary check
  if (pattern.size() == 0) {
    if (value.size() == 0)
      return true;
    else
      return false;
  } else if (pattern == "a" || pattern == "b") {
    if (value.size() >= 1)
      return true;
    else
      return false;
  } else if (pattern == "ab" || pattern == "ba") {
    if (value.size() >= 2)
      return true;
    else
      return false;
  }

  // count how many 'a' and 'b' in the pattern
  int na = 0, nb = 0;
  for (int i = 0; i < pattern.size(); ++i) {
    if (pattern[i] == 'a')
      na++;
    else if (pattern[i] == 'b')
      nb++;
    else {
      cout << "Error!!! pattern contains chars other than 'a' or 'b'! " << pattern << endl;
      return false;
    }
  }

  // calculate possible sizes for a and b
  auto sizes = all_sizes(value.size(), na, nb);
  for (auto &size : sizes) {
    int sizea = size[0];
    int sizeb = size[1];
    string sa = "", sb = "";
    int idx = 0;
    bool canMatch = false;
    for (auto &c : pattern) {
      if (c == 'a') {
        string nexta = value.substr(idx, sizea);
        idx += sizea;
        if (sa != "" && nexta != sa)  // not match for a pattern
          break;
        else if (sa == "")   // first time, set the string of a
          sa == nexta;
      }
      else
      if (c == 'b') {
        string nextb = value.substr(idx, sizeb);
        idx += sizeb;
        if (sb != "" && nextb != sb)  // not match for a pattern
          break;
        else if (sb == "")   // first time, set the string of b
          sb == nextb;
      }
      //
      if (idx >= value.size()) {
        canMatch = true;
      }
    }
    //
    if (canMatch) {
      return true;
    }
  }

  // no match for all possible sizes.
  return false;
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

  void test(string value, string pattern) {
    cout << value << " , " << pattern << " ? ";
    if (didMatch(value, pattern))
      cout << "\tMatch!!!" << endl;
    else
      cout << "\tNO!!!" << endl;
  }

  void unit_test() {
    test("catcatgocatgo", "aabab");
    test("catcatgocatgo", "a");
    test("catcatgocatgo", "b");
    test("catcatgocatgo", "ab");
    test("catcatgocatgo", "ba");
    test("catcatgocatgo", "abb");
    test("catcatgocatgo", "aa");
    test("catcatgocatgo", "bb");
    test("tttt", "ab");
    test("tttt", "bb");
    test("ttttt", "bb");
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

