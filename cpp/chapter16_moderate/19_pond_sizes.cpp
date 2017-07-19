//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Your have an integer matrix representing a plot of land, where the value at that location represents the height above sea level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally, or diagonally. The size of the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.
 *
 * EXMAPLE:
 * Input:
 *    0 2 1 0
 *    0 1 0 1
 *    1 1 0 1
 *    0 1 0 1
 * Output:
 *    2, 4, 1 (in any order)
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * walk through the matrix, everytime finds a new 0, uses dfs/bfs to find all the neighbors 0, mark the size, push it into an array, and mark all visited sites. Then find another un-visited site, until all the matrix sites are visited.
 * // NOTE: Assume all integers are non-negative!
 * //       So we can use negative value as marks.
 */
vector<vector<int>> unvisited_pond_neigh(vector<vector<int>> &matrix, int row, int col) {
  vector<vector<int>> neigh;
  vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  for (int i = 0; i < 8; ++i) {
    int r = row + dy[i];
    int c = col + dx[i];
    if (r >= 0 && r < matrix.size() && c >= 0 && c < matrix.at(0).size() && matrix[r][c] == 0)
      neigh.push_back(vector<int>{r, c});
  }
  return neigh;
}

// find the pond size at site(row, col)
int pond_size(vector<vector<int>> &matrix, int row, int col) {
  int &site = matrix[row][col];
  if (site != 0)
    return 0;
  //
  vector<vector<int>> neigh = unvisited_pond_neigh(matrix, row, col);
  int size = 1; // include this site.
  site = -1;
  for (auto &nei : neigh) {
    size += pond_size(matrix, nei[0], nei[1]);
  }
  return size;
}

vector<int> pond_sizes(vector<vector<int>> &matrix) {
  // boundary check
  if (matrix.size() == 0 || matrix.at(0).size() == 0)
    return vector<int>{};
  //
  vector<int> sizes;
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.at(0).size(); ++j) {
      int &site = matrix[i][j];
      if (site == 0) {   // only consider water site
        sizes.push_back(pond_size(matrix, i, j));
      }
    }
  }

  return sizes;
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

  void test(vector<vector<int>> &matrix) {
    printf("matrix: ");
    print_vector2d(matrix);
    printf("\thas pond sizes: ");
    auto sizes = pond_sizes(matrix);
    print_vector(sizes);
    printf("\n");
  }

  void unit_test() {
    vector<vector<int>> input;

    input = {
        {0,2,1,0},
        {0,1,0,1},
        {1,1,0,1},
        {0,1,0,1},
    };
    test(input);

    input = {};
    test(input);

    input = {
        {0,2,1,0},
    };
    test(input);

    input = {
        {0},
        {0},
        {1},
        {0},
    };
    test(input);

    input = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };
    test(input);

    input = {
        {0,0,0,0},
        {1,1,1,0},
        {0,0,1,0},
        {1,0,0,0},
    };
    test(input);

    input = {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
    };
    test(input);

    input = {
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,1,1},
    };
    test(input);
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

