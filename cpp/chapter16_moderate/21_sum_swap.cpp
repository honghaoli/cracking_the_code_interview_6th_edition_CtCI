//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the two arrays the same sum.
 * EXAMPLE
 * Input:   {4,1,2,1,1,2} and {3,6,3,3}
 * Output:  {1,3}
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
 * find the difference of sums, divide by two.
 * then find the two elements.
 *      first sort, then search.
 */
vector<int> find_swaps(vector<int> &vec1, vector<int> &vec2) {
  if (vec1.size() == 0 || vec2.size() == 0)
    return vector<int>{}; /// return empty when cannot find any

  int sum1 = accumulate(vec1.begin(), vec1.end(), 0);
  int sum2 = accumulate(vec2.begin(), vec2.end(), 0);
  if ((sum1 - sum2) % 2 != 0)
    return vector<int>{}; /// return empty when cannot find any

  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
  int diff = (sum1 - sum2) / 2;
  int n1 = 0, n2 = 0;
  while (n1 < vec1.size() && n2 < vec2.size()) {
    int tmp = vec1[n1] - vec2[n2];
    if (tmp == diff) {
      return vector<int>{vec1[n1], vec2[n2]};
    } else if (tmp > diff) {
      n2++;
    } else {
      n1++;
    }
  }

  return vector<int>{}; /// return empty when cannot find any
};



// 2nd method
/*
 * The book solution
 * to find the two elements.
 *    We can store one array into hashmap, and then find one - target.
 *    It just a variation of two-sum-problem.
 */
vector<int> find_swaps2(vector<int> &vec1, vector<int> &vec2) {
  if (vec1.size() == 0 || vec2.size() == 0)
    return vector<int>{}; /// return empty when cannot find any

  int sum1 = accumulate(vec1.begin(), vec1.end(), 0);
  int sum2 = accumulate(vec2.begin(), vec2.end(), 0);
  if ((sum1 - sum2) % 2 != 0)
    return vector<int>{}; /// return empty when cannot find any

  int diff = (sum1 - sum2) / 2;
  unordered_map<int, bool> hash;
  for (auto &i : vec2) {
    hash[i] = true;
  }
  for (auto &i : vec1) {
    if (hash.count(i - diff) != 0)
      return vector<int>{i, i - diff};
  }

  return vector<int>{}; /// return empty when cannot find any
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

  void test(vector<int> v1, vector<int> v2) {
    printf("\n");
    print_vector(v1);
    print_vector(v2);
    int sum1 = accumulate(v1.begin(), v1.end(), 0);
    int sum2 = accumulate(v2.begin(), v2.end(), 0);
    printf("sum1 = %d, sum2 = %d\n", sum1, sum2);
//    auto result = find_swaps(v1, v2);
    auto result = find_swaps2(v1, v2);
    if (result.size() == 2)
      printf("swap %d and %d\n", result.at(0), result.at(1));
    else
      printf("Cannot swap to make equal sum.\n");
  }

  void unit_test() {
    test({4,1,2,1,1,2}, {3,6,3,3});
    test({0}, {1});
    test({1}, {1});
    test({1}, {});
    test({}, {});
    test({1,2,3,4,5,6,7,8,9,0}, {1,2,3,4,5});
    test({1,2,3,4,5,6,7,8,9,0}, {9,8,7,6,5,4,3});
    test({1,2,3,4,5,6,7,8,9,0}, {9,8,7,6,5,4,3,1});
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

