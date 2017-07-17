//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given any integer, print an English phrase that describes the integer (e.g., "One Thousand, Two Hundred Thirty Four").
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * From large to small, billion, million, thousand, hundred
 * special treatment for < 20
 */
vector<string> levels = {"", "Thousand", "Million", "Billion"};
vector<int> levelsInt = {1, 1000, 1000000, 1000000000};
string hundred = "Hundred";
vector<string> tens = {
    "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
vector<string> ones = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string convert_under_thousand(int num) {
  if (num >= 1000)
    return "Err";
  if (num == 0)
    return "";
  string result = "";
  int h = num / 100;
  if (h > 0)
    result += ones[h] + " " + hundred;

  int t = num % 100;
  // avoid trailing zero
  if (t == 0)
    return result;

  if (t < 20) {
    result += " " + ones[t];
  } else {
    int tt = t / 10;
    int o = t % 10;
    result += " " + tens[tt - 2] + " " + ones[o];
//    printf("tt %d, o %d \n", tt, o);
  }
//  printf("h %d, t %d \n", h, t);
  return result;
}

string convert(long num) {
  if (num > numeric_limits<int>::max())
    return "input number > than max integer!\n";
  if (num < numeric_limits<int>::min())
    return "input number < than min integer!\n";
  // the max level is billion now.
  const int N = levels.size();

  if (num == 0)
    return "Zero";

  string result = "";
  if (num < 0) {
    result = "Minus";
    num = -num;
  }

  for (int i = N; i > 0; --i) {
    long floor = levelsInt[i - 1];
    long ceil = (long) levelsInt[i - 1] * 1000;
    long n = (num % ceil) / floor;
//    printf("ceil %ld, floor %ld, n: %d\n", ceil, floor, n);
    string tmp = convert_under_thousand(n);
    if (tmp != "") {
      // add space only when there is something already.
      if (result != "")
        result += " ";
      result += tmp + " " + levels[i - 1];
    }
  }

  return result;
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

  void test(long num) {
    cout << num << " converted into: " << convert(num) << endl;
  }

  void unit_test() {
    for (int i = 0; i <= 100; ++i) {
      test(i);
    }

    for (int i = 0; i >= -100; --i) {
      test(i);
    }

    test(1000);
    test(1001);
    test(1011);
    test(1111);
    test(2101);
    test(9999);
    test(19999);
    test(129999);
    test(1000000);
    test(1000001);
    test(1000012);
    test(1000312);
    test(1004312);
    test(1054312);
    test(7654312);
    test(87654312);
    test(987654312);
    test(1000000000);
    test(1000000001);
    test(1001001101);
    test(-1001001101);
    test(21000000001);
    test(321000000001);
    test(-21000000001);
    test(-321000000001);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    printf("max integer: %d\n", numeric_limits<int>::max());
    // customize your own tests here

    unit_test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

