//
// Created by Honghao Li on 3/26/17.
//

#include <iostream>

using namespace std;


// From the example, this problem is not case-sensitive, not whitespace sensitive. So we assume only 26 English characters matter.
// then we need a simple function to convert a-z A-z to 0-25, we only need array[26]
// The boundary cases for this problem could be very dirty, like: how about a string with only tons of special character and no English letters? how about an empty string?

////////////////////// Solution ////////////////////////
int convertLetterToInt(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a';
  } else if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  }
  return -1;
}

// The 1st method
// Odd length string should have exactly one odd number char, even length string should have all even number chars.
// only charaters other than English letters, or empty string, assume false
bool isPermutation1(string s1) {
  const int R = 26;
  int odd_count = 0;
  int letter_count = 0;   // only count 26 English characters
  bool char_odd[R] = {};
  // compute frequency of s1
  for (char &c : s1) {
    int index = convertLetterToInt(c);
    if (index < 0) continue;
    letter_count++;
    if (char_odd[index]) {
      char_odd[index] = false;
      odd_count--;
    } else {
      char_odd[index] = true;
      odd_count++;
    }
  }
  // only charaters other than English letters, or empty string, assume false
  if (letter_count == 0) {
    return false;
  }
  // final check identical
  bool odd_len = (letter_count % 2 == 1);
//  printf("length(only letters): %d, odd count: %d\n", letter_count, odd_count);
// Odd length string should have exactly one odd number char, even length string should have all even number chars.
  return (odd_len && odd_count == 1) || (!odd_len && odd_count == 0);
}


// 2nd method

// 3rd method





////////////////////// Test ////////////////////////
class Test {

 public:

  Test(bool (*test_func)(string)) {
    func = test_func;
    basicTests();
  }

 private:
  int num_fail = 0;
  bool (*func)(string);

  void basicTests() {
    // customize your own tests here
    unitTest("Tact Coa", true);
    unitTest("abcaefg", false);
    unitTest("aaaaaaaaaa", true);
    unitTest("234198098adfjlkajdslkfjlakdj", false );
    unitTest("1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", false);
    unitTest("---", false);
    unitTest("-+=", false);
    // test white space
    unitTest("ab cd ef ", false);
    unitTest("ab cd cdab ", true);
    unitTest("         ", false);
    unitTest("", false);
    // test some special characters
    unitTest("ab cd\tef", false);
    unitTest("ab cd\tbad c", true);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(string s1, bool expected) {
    bool result = func(s1);
    if (result != expected) {
      printf("\n========== test failed! ===========\n");
      printf("input string 1: %s\n", s1.c_str());
      printf("expected answer: %s\n", expected ? "True" : "False");
      printf("your answer: %s\n", result ? "True" : "False");
      printf("===================================\n");
      num_fail++;
    }
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test(isPermutation1);  // change the method you want to test here.
  return 0;
}