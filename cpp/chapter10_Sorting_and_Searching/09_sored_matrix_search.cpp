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
  if (rlo < 0  || rhi >= mat.size() || rlo > rhi)
    return Coordinate();
  if (clo < 0 || chi >= mat.at(0).size() || clo > chi)
    return Coordinate();
  if (mat[rlo][clo] == target) { // this is important !!!
    return Coordinate(rlo, clo);
  }
//  if (mat[rhi][chi] == target) { // this is important !!!
//    return Coordinate(rhi, chi);
//  }
//  if (mat[rlo][clo] > target) {
//    return Coordinate();
//  }
//  if (mat[rhi][chi] < target) {
//    return Coordinate();
//  }

  // only consider the square part for diagonal search
  int diag = min(rhi - rlo, chi - clo);
  rhi = diag + rlo;
  chi = diag + clo;
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
  // in the book, after the loop, mat[clo][rlo] is the first > target.

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

  void test1() {
    printf("\n");
    vector<vector<int>> mat = {{1}};
    for (int target = 0; target < 3; ++target) {
      auto coord = find_pos(mat, target);
      if (coord.isNull())
        printf("Not found %d in matrix.\n", target);
      else
        printf("%d's coordinate is (%d, %d).\n", target, coord.row, coord.col);
    }
  }
  void test2() {
    printf("\n");
    vector<vector<int>> mat = {{1,2}, {3,4}};
    for (int target = 0; target < 6; ++target) {
      auto coord = find_pos(mat, target);
      if (coord.isNull())
        printf("Not found %d in matrix.\n", target);
      else
        printf("%d's coordinate is (%d, %d).\n", target, coord.row, coord.col);
    }
  }
  void test3() {
    printf("\n");
    vector<vector<int>> mat = {{1,2,3,4}};
    for (int target = 0; target < 6; ++target) {
      auto coord = find_pos(mat, target);
      if (coord.isNull())
        printf("Not found %d in matrix.\n", target);
      else
        printf("%d's coordinate is (%d, %d).\n", target, coord.row, coord.col);
    }
  }
  void test4() {
    printf("\n");
    vector<vector<int>> mat = {{1},{2},{3},{4}};
    for (int target = 0; target < 6; ++target) {
      auto coord = find_pos(mat, target);
      if (coord.isNull())
        printf("Not found %d in matrix.\n", target);
      else
        printf("%d's coordinate is (%d, %d).\n", target, coord.row, coord.col);
    }
  }
  void test5() {
    printf("\n");
    vector<vector<int>> mat = {{1,11,21,31,41},{2,12,22,32,42},{3,13,23,33,43},{4,14,24,34,44}};
    for (int target = 0; target < 46; ++target) {
      auto coord = find_pos(mat, target);
      if (coord.isNull())
        printf("Not found %d in matrix.\n", target);
      else
        printf("%d's coordinate is (%d, %d).\n", target, coord.row, coord.col);
    }
  }
  void test6() {
    printf("\n");
    vector<vector<int>> mat = {
        {1,2,4,7,11,26},
        {3,5,8,12,16,27},
        {6,9,13,17,20,28},
        {10,14,18,21,23,29},
        {15,19,22,24,25,30},
        {31,32,33,34,35,36}
    };
    for (int target = 0; target < 38; ++target) {
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

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

