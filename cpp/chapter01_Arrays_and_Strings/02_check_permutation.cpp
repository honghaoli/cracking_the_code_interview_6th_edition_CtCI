//
// Created by Honghao Li on 3/26/17.
//

#include <iostream>

using namespace std;


// Assume we already know the alphabet of the string, say ASCII for example, so the size of alphabet is 128.
// Assume the comparison is case sensitive, and whitespace sensitive (different numbers of whitespace matter)
////////////////////// Solution ////////////////////////
// The 1st method
// Two strings are permutation of each other when they have identical char frequency.
bool isPermutation1(string s1, string s2) {
  // size of char is 128, unsigned char is 256
  const int R = 128;
  int char1[R] = {};
  int char2[R] = {};
  // compute frequency of s1
  for (char &c : s1) {
    char1[c]++;
  }
  // compute frequency of s2
  for(char &c : s2) {
    char2[c]++;
    if (char2[c] > char1[c]) {  // once s2 has more c char than s1, they are not permutaion of each other
      return false;
    }
  }
  // final check identical
  for(int i = 0; i < R; i++) {
    if (char1[i] != char2[i]) {
      return false;
    }
  }
  return true;
}

// 2nd method
// imporved from the 1st method
// 1. they must have the same length to be permutation;
// 2. we can save some space using only one array.
bool isPermutation2(string s1, string s2) {
  const int R = 128;
  if (s1.length() != s2.length()) {
    return false;
  }
  int char_count[R] = {};
  // compute frequency of s1
  for (char &c : s1) {
    char_count[c]++;
  }
  // compute frequency of s2
  for(char &c : s2) {
    char_count[c]--;
    if (char_count[c] < 0) {  // once s2 has more c char than s1, they are not permutaion of each other
      return false;
    }
  }
  // since the have same length, there could not be any positive number left in the array if no negative left.
  return true;
}

// 3rd method
// sort both strings first, then compare with sorted result.
// Higher time complexity, but very compact solution
bool isPermutation3(string s1, string s2) {
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  return s1 == s2;
}





////////////////////// Test ////////////////////////
class Test {

 public:

  Test(bool (*test_func)(string, string)) {
    func = test_func;
    basicTests();
  }

 private:
  int num_fail = 0;
  bool (*func)(string, string);

  void basicTests() {
    // customize your own tests here
    unitTest("abcdefg", "gfedcba", true);
    unitTest("abcaefg", "aacbefg", true);
    unitTest("abcaefg", "adcbefg", false);
    unitTest("aaaaaaaaaa", "aaaaaaaaaa", true);
    unitTest("234198098adfjlkajdslkfjlakdj", "234198098adfjlkajdslkfjlakdj", true );
    unitTest("1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", "1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", true);
    unitTest("1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", ",./;'[]-=mnbvcxzlkjhgfdsapoiuytrewq0987654321", true);
    unitTest("---", "===", false);
    // test white space
    unitTest("ab cd ef ", " abc def ", true);
    unitTest("ab cd ef ", "abcdef", false);
    // test some special characters
    unitTest("ab cd\tef", "\tabcdef ", true);

    // test non ex-ASCII
    // cannot correctly deal with Chinese characters
    // NOTE: you can change the implementation char -> wchar_t and string -> wstring, however, things would be trick for many situations (e.g. cross-platform)
    // TODO: not sure why method 2 & 3 can pass but method 1 cannot???
    unitTest("中中中中中中", "中中中中中中", true);
    unitTest("中文测试", "测试中文", true);
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
  Test t = Test(isPermutation2);  // change the method you want to test here.
  return 0;
}