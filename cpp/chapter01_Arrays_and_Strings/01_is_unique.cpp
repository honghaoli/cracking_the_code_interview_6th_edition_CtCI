#include <iostream>

using namespace std;

////////////////////// Solution ////////////////////////
// The 1st method
// Assume we already know the alphabet of the string, say extended ASCII for example, so the size of alphabet is 256.
// we could also take the alphabet size as an input argument R.
bool isUnique1(string str, int R = 256) {
  if (str.length() > R) {
    return false;
  }
  bool alphabet[R];
  for (int i = 0; i < R; ++i) {
    alphabet[i] = false;
  }
  for(char &s : str) {
    if (s >= R) {
      throw invalid_argument("character index in string exceeds the size of given alphabet !\n");
    }
    if (alphabet[s])
      return false;
    else
      alphabet[s] = true;
  }
  return true;
}

////////////////////// Test ////////////////////////
int unitTest(string str, bool expected) {
  bool result = isUnique1(str);
  if (result != expected) {
    printf("========== test failed! ===========\n");
    printf("input string: %s\n", str.c_str());
    printf("expected answer: %s\n", expected ? "True" : "False");
    printf("your answer: %s\n", result ? "True" : "False");
    printf("===================================\n");
    return 1;
  }
  return 0;
}

void basicTests() {
  int fail = 0;
  fail += unitTest("abcdefg", true);
  fail += unitTest("abcaefg", false);
  fail += unitTest("234198098adfjlkajdslkfjlakdj", false);
  fail += unitTest("1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", true);
  fail += unitTest("---", false);
  // test white space
  fail += unitTest("  ", false);
  fail += unitTest("ab cd ef ", false);
  // test non ex-ASCII
  fail += unitTest("中文字符是不是对的？", false);
  fail += unitTest("重复的中文字符中？", false);
  // method 1 cannot correctly deal with Chinese characters
  fail += unitTest("为什么中文字符不能通过呢，如果这个没有重复的话。", true);
  fail += unitTest("为什么中文字符不能通过呢", true);
  if (fail == 0) {
    printf("Test passed!\n");
  } else {
    printf("\nTotal fail cases: %d", fail);
  }
}

////////////////////// Main ////////////////////////
int main() {
  basicTests();
  return 0;
}