//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Oh, no! You have accidentally removed all spaces, punctuation, and capitalization in a lengthy document. A sentence like "I reset the computer. It still didn't boot!" became "iresetthecomputeritstilldidntboot". You'll deal with the punctuation and capitalization later; right now you need to re-insert the spaces. Most of the words are in a dictionary but a few are not. Given a dictionary (a list of strings) and the document (a string), design an algorithm to unconcatenate the document in a way that minimizes the number of unrecognized characters.
 * EXAMPLE:
 *    INPUT:    jesslookedjustliketimherbrother
 *    OUTPUT:   jess looked just like tim her brother ( 7 unrecognized characters)
 *              ----                  ---
 */





#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * each time found a word, calculate the min unrecognized chars in the rest sub-string.
 */
int min_unrecognized_chars(string &str, int start) {
  int unchar = 0;
  for (int i = start; i < str.size(); ++i) {

  }
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

  void test1() {
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

