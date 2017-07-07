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

struct Coordinate {
  Coordinate() = default;
  Coordinate(int row, int col) : row(row), col(col) {}
  bool isNull() { return row < 0 || col < 0; }
  int row = -1;
  int col = -1;
};


Coordinate find_pos_sub(vector<vector<int>> &mat, Coordinate &start, Coordinate &end, int target) {
  int rlo = start.row;
  int rhi = end.row;
  int clo = start.col;
  int chi = end.col;

  // check boundary
  if (mat[rlo][clo] > target) {
    return Coordinate();
  }
  if (mat[rhi][chi] < target) {
    return Coordinate();
  }

  // binary search diagonal
  while(rhi >= rlo && chi >= clo) {
    int rmid = (rhi - rlo) / 2 + rlo;
    int cmid = (chi - clo) / 2 + clo;
    int value = mat[rmid][cmid];
    if (value == target)  {
      return Coordinate(rmid, cmid);
    } else if (value > target) {
      rhi = rmid - 1;
      chi = cmid - 1;
    } else {
      rlo = rmid + 1;
      clo = cmid + 1;
    }
  }
  // after the loop, mat[clo][rlo] is the first > target.

  auto upperRightStart = Coordinate(start.row, clo);
  auto upperRightEnd = Coordinate(rlo - 1, end.col);
  auto upperRightSearch = find_pos_sub(mat, upperRightStart, upperRightEnd, target);

  if (upperRightSearch.isNull()) {
    auto lowerLeftStart = Coordinate(rlo, start.col);
    auto lowerLeftEnd = Coordinate(end.row, clo - 1);
    auto lowerLeftSearch = find_pos_sub(mat, lowerLeftStart, lowerLeftEnd, target);
    return lowerLeftSearch;
  } else {
    return upperRightSearch;
  }
}

Coordinate find_pos(vector<vector<int>> &mat, int target) {
  // check boundary
  int m = mat.size();
  if (m < 1)
    return Coordinate();
  int n = mat.at(0).size();
  if (n < 1)
    return Coordinate();
  //
  auto start = Coordinate(0, 0);
  auto end = Coordinate(m - 1, n - 1);
  return find_pos_sub(mat, start, end, target);
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
    vector<vector<int>> mat = {{1,2}, {3,4}};
    for (int target = 0; target < 6; ++target) {
      auto coord = find_pos(mat, target);
      if (coord.isNull())
        printf("Not found %d in matrix.\n", target);
      else
        printf("%d's coordinate is (%d, %d).\n", target, coord.row, coord.col);
    }
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test();

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

