//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given an array of integers, write a method to find indices m and n such that if you sorted elements m through n, the entire array would be sorted. Minimize n - m  (that is, find the smallest such sequence).
 * EXAMPLE:
 * Input: 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
 * Output:  (3, 9)
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * sort and compare to original array.
 * ~ O(N log N), not the best
 */



// 2nd method
/*
 * The book solution:  ~ O(N).
 * Find the no decreasing head part, no decreasing tail part, and middle part.
 * Then start from the boundary,
 *     find the place where (last of head part) <= min of middle part.
 *     find the place where (first of tail part) >= max of middle part.
 *  The range is what we need.
 */

pair<int, int> find_range(vector<int> &vec) {
  if (vec.size() == 0)
    return make_pair(-1, -1);
  if (vec.size() == 1)
    return make_pair(0, 0);

  // separate into three parts
  int start_middle = 0;
  int end_middle = 0;
  bool found_last_head = false;
  int prev = vec.at(0);
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] < prev) {
      if (!found_last_head) {
        found_last_head = true;
        start_middle = i;
        end_middle = start_middle;
      } else {
        end_middle = i - 1;
      }
    }
    prev = vec[i];
  }
  printf("size: %d, start: %d, end: %d.\n", vec.size(), start_middle, end_middle);

  // find max and min in middle part.
  int max_middle = *max_element(vec.begin() + start_middle, vec.begin() + end_middle + 1);
  int min_middle = *min_element(vec.begin() + start_middle, vec.begin() + end_middle + 1);

  /*
   * Note!!!!
   * The book solution seems only do one time, first shrink left, then shrink right. That's not correct since shrink left would affect the max and shrink right would affect the min of middle.
   * Or maybe I missed something in the book solution ?
   */
  for(;;) {
    // move start pointer
    if (start_middle > 0 && min_middle < vec[start_middle - 1]) {
      start_middle--;
      max_middle = max(vec[start_middle], max_middle);
      cout << "shrink left" << endl;
    }
    else
    // move end pointer
    if (end_middle < vec.size() - 1 && max_middle > vec[end_middle + 1]) {
      end_middle++;
      min_middle = min(vec[end_middle], min_middle);
      cout << "shrink right" << endl;
    }
    // found both sides.
    else
      break;
  }

//  printf("max middle: %d, min middle: %d.\n", max_middle, min_middle);
  //
  return make_pair(start_middle, end_middle);
};



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test(vector<int> &input) {
    printf("\n");
    print_vector(input);
    auto result = find_range(input);
    printf("The range is: (%d, %d)\n", result.first, result.second);
  }

  void unit_test() {
    vector<int> vec;
    vec = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    test(vec);
    vec = {1,2,3,4,5,6,7,8,9};
    test(vec);
    vec = {1,2,3,4,5,6,7,8,9,0};
    test(vec);
    vec = {1,2,3,1,5,6,7,11,9,10};
    test(vec);
    vec = {1,2,3,8,7,6,5,4,9,10};
    test(vec);
    vec = {1,2,3,8,7,6,5,4,1,9,10};
    test(vec);
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

