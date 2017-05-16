//
// Created by Honghao Li on 4/22/17.
//


// Problem 04
// Write a method to return all subsets of a set.



#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

template<typename T>
void printVector(vector<T> &vec) {
  cout << "1d vector: ";
  for (auto &v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

template<typename T>
void print2DVector(vector<vector<T> > &vec) {
  cout << "2d vector: \n";
  for (auto &v1 : vec) {
    if (v1.size() == 0) {
      cout << "ø";
    }
    for (auto &v : v1) {
      cout << v << " ";
    }
    cout << endl;
  }
  cout << endl;
}


// 1st method
// every time add an element, just double the sets with the new element
// { {}, {a}, {b}, {ab} }  ====> { {}, {a}, {b}, {ab},  {c}, {ac}, {bc}, {abc} }
void add_element(vector<vector<int>> &vec, int elem) {
  int N = vec.size();
  for (int i = 0; i < N; ++i) {
    auto v = vec[i];
    v.push_back(elem);
    vec.push_back(v);
  }
}

vector<vector<int>> subsets(vector<int> &v) {
  vector<vector<int>> res = {{}};
  for (auto &elem : v) {
    add_element(res, elem);
  }
  return res;
}



// 2nd method
// we can use binary number of a integer to represent the 101010 of index of the chosen element
// However!!! This method does not work for large set!!! since generally an int or long would only have 32 or 64 bit.
// So I don't think this method is good for real applications.



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here
    vector<int> s {1,2,3};
    auto r = subsets(s);
    printVector(s);
    print2DVector(r);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
