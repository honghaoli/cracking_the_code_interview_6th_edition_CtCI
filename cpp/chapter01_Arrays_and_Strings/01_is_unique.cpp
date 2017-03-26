#include <iostream>

using namespace std;


////////////////////// Solution ////////////////////////
// The 1st method
// Assume we already know the alphabet of the string, say ASCII for example, so the size of alphabet is 128.
// we could also take the alphabet size as an input argument R.
bool isUnique1(string str) {
  // size of char is 128, unsigned char is 256
  const int R = 128;
  if (str.length() > R) {
    return false;
  }
  bool alphabet[R] = {};
  for(char &s : str) {
    if (alphabet[s])
      return false;
    else
      alphabet[s] = true;
  }
  return true;
}

// 2nd method
// we could use a bit array instead of a bool array to save some space;
bool isUnique2(string str) {
  return false;
}

// 3rd method
// if the alphabet could be really huge, we could also use a hashtable instead of arrays;




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
    unitTest("abcdefg", true);
    unitTest("abcaefg", false);
    unitTest("234198098adfjlkajdslkfjlakdj", false);
    unitTest("1234567890qwertyuiopasdfghjklzxcvbnm,./;'[]-=", true);
    unitTest("---", false);
    // test white space
    unitTest("  ", false);
    unitTest("ab cd ef ", false);

    // test non ex-ASCII
    unitTest("中文字符是不是对的？", false);
    unitTest("重复的中文字符中？", false);
    // cannot correctly deal with Chinese characters
    // NOTE: you can change the implementation char -> wchar_t and string -> wstring, however, things would be trick for many situations (e.g. cross-platform)
    unitTest("为什么中文字符不能通过呢，如果这个没有重复的话。", true);
    unitTest("为什么中文字符不能通过呢", true);
    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(string str, bool expected) {
    bool result = func(str);
    if (result != expected) {
      printf("\n========== test failed! ===========\n");
      printf("input string: %s\n", str.c_str());
      printf("expected answer: %s\n", expected ? "True" : "False");
      printf("your answer: %s\n", result ? "True" : "False");
      printf("===================================\n");
      num_fail++;
    }
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test(isUnique1);
  return 0;
}