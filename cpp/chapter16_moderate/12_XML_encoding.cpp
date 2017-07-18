//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Since XML is very verbose, you are given a way of encoding it where each tag gets mapped to a pre-defined integer value. The language/grammar is a follows:
 *
 * Element    -->   Tag Attributes END Children END
 * Attribute  -->   Tag Value
 * END        -->   0
 * Tag        -->   some predefined mapping to int
 * Value      --> string value
 *
 * For example, the following XML might be converted into the compressed string below (assuming a mapping of family -> 1, person -> 2, firstName -> 3, lastName -> 4, state -> 5).
 * <family lastName="McDowell" state="CA">
 *    <person firstName="Gayle">Some Message</person>
 * </family>
 * Becomes:
 * 1 4 McDowell 5 CA 0 2 3 Gayle 0 Some Message 0 0
 * Write code to print the encoded version of an XML element (passed in Element and Attribute objects).
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * "<" is the start of Tag, then attributes, then ">" for END.
 */

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

