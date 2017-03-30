//
// Created by Honghao Li on 3/29/17.
//

#include <iostream>
#include <sstream>

using namespace std;


// Assume we only have upper and lower case letters a-z A-Z

////////////////////// Solution ////////////////////////
bool isLetterValid(char c) {
  if (c >= 'a' && c <= 'z') {
    return true;
  } else if (c >= 'A' && c <= 'Z') {
    return true;
  }
  return false;
}

// The 1st method
// straight forward implementation
// iterate through the input string, each time find a different char, append it to result string, and start to count the repeat times.
string compress1(string s1) {
  char current = '0';
  int repeat = 0;
  ostringstream s;

  for (char &c : s1) {
    if (!isLetterValid(c))
      throw runtime_error("invalid input string!!! only a-z and A-Z allowed in the string.");
    if (c != current) {
      if (repeat > 0) {
        s << repeat;
      }
      current = c;
      repeat = 1;
      s << c;
    } else {
      repeat++;
    }
  }
  // the last letter
  s << repeat;
  return s.str().length() < s1.length() ? s.str() : s1;
}


// 2nd method

// 3rd method





////////////////////// Test ////////////////////////
class Test {

 public:

  Test(string (*test_func)(string)) {
    func = test_func;
    basicTests();
  }

 private:
  int num_fail = 0;
  string (*func)(string);

  void basicTests() {
    // customize your own tests here
    unitTest("aabccccccaaa", "a2b1c6a3");
    unitTest("AABCCCCCCAAA", "A2B1C6A3");
    unitTest("abcdefg", "abcdefg");
    unitTest("aa", "aa");
    unitTest("aaa", "a3");
    unitTest("AAA", "A3");
    unitTest("abababababababababa", "abababababababababa");
    unitTest("aabbaabbaabbccc", "a2b2a2b2a2b2c3");
    unitTest("abababababcccccccccccccc", "a1b1a1b1a1b1a1b1a1b1c14");
    unitTest("abababababccccccccccccc", "abababababccccccccccccc");
    unitTest("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(string s1, string expected) {
    string result = func(s1);
    if (result != expected) {
      printf("\n========== test failed! ===========\n");
      printf("input string 1: %s\n", s1.c_str());
      printf("expected answer: %s\n", expected.c_str());
      printf("your answer: %s\n", result.c_str());
      printf("===================================\n");
      num_fail++;
    }
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test(compress1);  // change the method you want to test here.
  return 0;
}