//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  Write a method to sort an array of strings so that all the anagrams are next to each other.
 *
 */

/*
 * Anagram:
 * noun
 * a word, phrase, or name formed by rearranging the letters of another, such as cinema, formed from iceman.
 * triangle  ->   integral
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * sort all the characters in each string, then sort the whole array.
 * Use a ordered map to maintain the re-ordered string and the original string.
 * Notice std::map only has unique key, std::multimap can have identical keys.  http://www.cplusplus.com/reference/map/multimap/
 */
void sort_anagrams(vector<string> &vec) {
  multimap<string, string> mymap;

  // sort chars in strings, and create a multi-key ordered map
  for (auto &s : vec) {
    string ss = s;
    sort(ss.begin(), ss.end());
    mymap.insert(make_pair(ss, s));
  }

  // sort the array
  vec.clear();
  for (auto &s : mymap) {
    vec.push_back(s.second);
  }
}

// 2nd method
// Todo: The book soultion use a hashmap list: <re-ordered chars of string, an array of all strings in this group>.



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test(vector<string> &vec) {
    cout << endl;
    print_vector(vec);
    sort_anagrams(vec);
    print_vector(vec);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    vector<string> vec;
    vec = {"triangle", "bad", "integral"};
    test(vec);
    vec = {"triangle", "ABN", "integral", "NBA", "coe", "BAN", "123", "oec", "321", "woo", "213", "231"};
    test(vec);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

