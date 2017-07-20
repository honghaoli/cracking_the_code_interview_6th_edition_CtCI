//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Each year, the government release a list of the 10000 most common baby names and their frequencies ( the number of babies with that name). The only problem with this is that some names have multiple spellings. For example, "John" and "Jon" are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive and symmetric.) In the final list, any name can be used as the "real" name.
 * EXAMPLE
 *    INPUT:
 *          Names: John(15), Jon(12), Chris(13), Kris(4), Christopher(19)
 *          Synonyms:  (John, Jon), (John, Johnny), (Chris, Kris), (Chris, Christopher)
 *    OUTPUT:
 *          John(27), Kris(36)
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method

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

