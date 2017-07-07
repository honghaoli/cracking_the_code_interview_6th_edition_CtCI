//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  Given an M * N matrix in which each row and each column is sorted in ascending order, write a method to find an element.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Binary search for each col/row?
 */



// 2nd method
/* Book solution
 * for each element in the matrix, the matrix can be divided into 4 parts.
 * Left upper < element;
 * Right lower > element;
 * If m[i][j] < target < m[i+1][j+1], then the target can only be in the Left lower or Right upper matrices.
 * Then recursively find the target.
 */
vector<int> find_pos_sub(vector<vector<int>> &mat, int rlo, int rhi, int clo, int chi, int target) {
  // check boundary
  if (mat[rlo][clo] > target) {
    return vector<int>{-1, -1};
  }
  if (mat[rhi][chi] < target) {
    return vector<int>{-1, -1};
  }

  // binary search diagonal
  int lo = 0;
  int hi = min(rhi - rlo, chi - clo);
  for(;;) {
    int mid = (hi - lo) / 2 + lo;
    int value = mat[rlo + mid][clo + mid];
    if (value == target)  {
      return vector<int>{rlo + mid, clo + mid};
    }
    else if (value > target) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
    if (hi < lo)
      break;
  }
}

vector<int> find_pos(vector<vector<int>> &mat, int target) {
  // check boundary
  int m = mat.size();
  if (m < 1)
    return vector<int>(2, -1);
  int n = mat.at(0).size();
  if (n < 1)
    return vector<int>(2, -1);
  //
  return find_pos_sub(mat, 0, m - 1, 0, n - 1, target);
}



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test() {
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

