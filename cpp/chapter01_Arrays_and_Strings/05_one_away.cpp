//
// Created by Honghao Li on 3/26/17.
//

#include <iostream>
#include <cmath>


using namespace std;


// The boundary cases for this problem could be very dirty, like: how about a string with only tons of special character and no English letters? how about an empty string?
// For simplicity, we assume this changed char could be anything like space or special char.

////////////////////// Solution ////////////////////////
// The 1st method
// the difference of lengths could be at most 1
// we still count the characters
bool isOneAway1(string s1, string s2) {
  const int R = 128;
  int char_count[R]{};
  int d_length = static_cast<int> (s1.length() - s2.length());
  if (abs(d_length) > 1) {   // abs(int), s1.length() is not int, should be string::size_type
    return false;
  }
  // compute frequency of s1
  for (char &c : s1) {
    char_count[c]++;
  }
  // compute frequency of s1
  for (char &c : s2) {
    char_count[c]--;
  }
  int diff = 0;
  for (int &i : char_count) {
    diff += abs(i);
  }
  // same length, only one char different or all identical
  if (d_length == 0 && (diff == 2 || diff == 0))
    return true;
  //  insert or remove,
  if (d_length == 1 && diff == 1)
    return true;
  //
  return false;
}


// 2nd method
// compare two strings on-the-fly
bool isOneAway2(string s1, string s2) {
  string &s_short = s1.length() < s2.length() ? s1 : s2;
  string &s_long = s1.length() >= s2.length() ? s1 : s2;
  int d_length = s_long.length() - s_short.length();

  if (d_length > 1) {
    return false;
  } else if (d_length == 0) {
    int diff = 0;
    for (int i = 0; i < s_short.length(); ++i) {
      if (s_short[i] == s_long[i])
        continue;
      diff++;
      if (diff > 1)
        return false;
    }
  } else if (d_length == 1) {
    int diff = 0;
    for (int i = 0; i < s_short.length(); ++i) {
      if (s_short[i] == s_long[i + diff])
        continue;
      diff++;
      if (diff > 1)
        return false;
      // back one char for short string
      if (d_length == 1)
        i--;
    }
  }
  return true;
}

// 3rd method





////////////////////// Test ////////////////////////
class Test {

 public:

  Test(bool (*test_func)(string, string)) : func(test_func) {
    basicTests();
  }

 private:
  int num_fail = 0;
  bool (*func)(string, string);

  void basicTests() {
    // customize your own tests here
    unitTest("pale", "ple", true);
    unitTest("pales", "pale", true);
    unitTest("pale", "bale", true);
    unitTest("pale", "bake", false);
//    unitTest("Tact Coa", true);
//    unitTest("abcaefg", false);
//    unitTest("aaaaaaaaaa", true);
//    unitTest("234198098adfjlkajdslkfjlakdj", false );
//    unitTest("1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", false);
//    unitTest("---", false);
//    unitTest("-+=", false);
//    // test white space
//    unitTest("ab cd ef ", false);
//    unitTest("ab cd cdab ", true);
//    unitTest("         ", false);
//    unitTest("", false);
//    // test some special characters
//    unitTest("ab cd\tef", false);
//    unitTest("ab cd\tbad c", true);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(string s1, string s2, bool expected) {
    bool result = func(s1, s2);
    if (result != expected) {
      printf("\n========== test failed! ===========\n");
      printf("input string 1: %s\n", s1.c_str());
      printf("input string 2: %s\n", s2.c_str());
      printf("expected answer: %s\n", expected ? "True" : "False");
      printf("your answer: %s\n", result ? "True" : "False");
      printf("===================================\n");
      num_fail++;
    }
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test(isOneAway2);  // change the method you want to test here.
  return 0;
}