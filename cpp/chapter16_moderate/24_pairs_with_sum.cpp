//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Design an algorithm to find all pairs of integers within an array which sum to a specified value.
 */


/*
 * Thoughts
 * How about duplicate values?
 */


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * A typical two-sum problem
 * Use hashmap
 * This is ~O(N) time and O(N) space.
 */
vector<vector<int>> find_pairs(vector<int> &vec, int target) {
  vector<vector<int>> result;
  unordered_map<int, int> hashmap;
  for (auto &i : vec) {
    if (hashmap.count(target - i) != 0) {
      // push duplicate values multiple times.
      for (int j = 0; j < hashmap[target - i]; ++j) {
        result.push_back(vector<int>{i, target - i});
      }
    }
    // record duplicate values
    if (hashmap.count(i) == 0) {
      hashmap[i] = 1;
    } else {
      hashmap[i]++;
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

  void test(vector<int> vec, int target) {
    printf("\n");
    print_vector(vec);
    printf("target sum: %d", target);
    auto result = find_pairs(vec, target);
    print_vector2d(result);
  }

  void unit_test() {
    test({1,2,3}, 5);
    test({1,1,1}, 2);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    unit_test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

