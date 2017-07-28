//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * You are given two arrays, one shorter (with all distinct elements) and one longer. Find the shortest subarray in the longer array that contains all the elements in the shorter array. The items can appear in any order.
 * EXAMPLE
 *    INPUT:    {1, 5, 9}  |  {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7}
 *                                                  ----------
 *    OUTPUT:   [7, 10]   (the underlined portion above)
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
 * two pointers, one start, one end.
 * The end pointer moves forward each step, once the end includes the same int as the start position, move start pointer until all elements has as less duplicates as possible. Recorde the shortest length and the start/end pointers.
 * How to check if an element is in shorter one?  hashmap.
 *    use the hashmap to store the counts of each element.
 *    use another variable to store how many elements have been included.
 *    everytime adding a new one (hashmap from 0 to 1), increase this number, never decrease the hashmap of element to 0 once it's >= 1.
 *
 * Suppose short array has m elements, larger array has n elements.
 * Takes ~ O(n) time, and O(m) space for hashmap.
 */

int move_start(vector<int> &input, int start, int end, unordered_map<int, int> &hashmap) {
  while (start < end) {
    int &elem = input[start];

    // not element we want, directly skip
    if (hashmap.count(elem) == 0) {
      start++;
      continue;
    }

    // if duplicate, move forward
    if (hashmap[elem] > 1) {
      start++;
      hashmap[elem]--;
      continue;
    }

    // else, stop
    break;
  }
  return start;
}

pair<int, int> shortest_subarray(vector<int> &target, vector<int> &input) {
  // boundary check
  if (input.size() == 0 || input.size() < target.size())
    return make_pair(-1, -1);

  // create hashmap for counts.
  unordered_map<int, int> hashmap;
  for (auto &i : target) {
    hashmap[i] = 0;
  }

  int min_length = input.size() + 1;    // length = end - start + 1, max length = input.size(); if >= that, then it's not valid.
  int min_start = -1, min_end = -1;

  int length;
  int count = 0;    // how many elements in target is included in current sequence.
  int start = 0, end = 0;

  // end pointer moves forward
  for (end = 0; end < input.size(); ++end) {
    int &elem = input[end];

    // if the element is not in the target array, skip and move forward.
    if (hashmap.count(elem) == 0)
      continue;

    // the first time find an elmenet in the target array.
    if (hashmap[elem] == 0)
      count++;
    hashmap[elem]++;    // increase the count for this element

    // check duplicate to move forward the start pointer
    if (hashmap[elem] > 1)
      start = move_start(input, start, end, hashmap);

    // calculate the length, only when all elements are found
    if (count == target.size()) {
      length = end - start + 1;
      if (length < min_length) {
        min_length = length;
        min_start = start;
        min_end = end;
      }
    }
  }

  return make_pair(min_start, min_end);
};



/*
 * Thoughts:
 * The book solutions seem to be very tedious, I'm not sure if it's necessary, or the best solution. Apparently, mime has better perfermance and is much easier to understand!
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

  void test(vector<int> &target, vector<int> &input) {
    printf("\ntarget array:\n");
    print_vector(target);
    printf("input array:\n");
    print_vector(input);
    auto result = shortest_subarray(target, input);
    printf("shortest sequence: start %d, end %d\n", result.first, result.second);
  }

  void unit_test() {
    vector<int> target;
    vector<int> input;

    target = {1, 5, 9};
    input = {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7};
    test(target, input);
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

