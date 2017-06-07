//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Write an alogrithm to print all ways of arranging eight queens on an 8*8 chess board so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.



// NOTE: should have 92 solution
// consider symmetry, reflection and rotation, there is 12 unique solutions.
// 8 symmetry group of the square
// origin, rotate 90, 180, 270, reflect across y, x, y=x, y=-x.
// https://en.wikipedia.org/wiki/Eight_queens_puzzle


#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "../lib/helper.h"


using namespace std;



// 1st method
// Since row and col must have 0-7 numbers each, assume row are 0,1,2...7, and col has 8! choices. We can try 8! = 40320 ways, and check diagonals every time. use row + col = const and row - col = const to check diagonals.
// Generally, it's a n-queen problem.
vector<vector<int>> find_next(int j, vector<bool> col, vector<bool> plus, vector<bool> minus) {
  int n = col.size();
  vector<vector<int>> seq;
  // choose one from the rest cols,
  for (int i = 0; i < n; ++i) {
    if (col[i] || plus[i + j] || minus[i - j + n - 1])
      continue;
    // copy new ones, because each time is a new try.
    auto _col = col;
    auto _plus = plus;
    auto _minus = minus;
    // occupied col and diagonals
    _col[i] = true;
    _plus[i + j] = true;
    _minus[i - j + n - 1] = true;
    auto vs = find_next(j + 1, _col, _plus, _minus);
    // important because the last one would always have zero left.
    if (vs.size() == 0)
      seq.push_back({i});
    else
      for (auto &v : vs) {
        v.push_back(i);
        seq.push_back(v);
      }
  }
  return seq;
}

vector<vector<int>> cols(int n) {
  vector<bool> col(n, false);  // j
  vector<bool> plus(2*n+1, false); // i+j
  vector<bool> minus(2*n+1, false); // i-j
  auto raw = find_next(0, col, plus, minus);
  // remove shorter failure ones.
  vector<vector<int>> result;
  for (auto &r : raw) {
    if (r.size() == n)
      result.push_back(r);
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

  // find all symmetrical cases for one solution
  vector<vector<int>> symmetricals(vector<int> one) {
    int n = one.size();
    vector<int> v90(n, 0);    // rotate 90 counter-clockwise
    vector<int> v180(n, 0);    // rotate 180 counter-clockwise
    vector<int> v270(n, 0);    // rotate 270 counter-clockwise
    vector<int> vy(n, 0);      // reflect across y axis
    vector<int> vx(n, 0);      // reflect across x axis
    vector<int> vyx(n, 0);      // reflect across y = x axis
    vector<int> vyx_(n, 0);      // reflect across y = -x axis
    // j = one[i]
    // (i, j) to (7-j, i)
    for (int i = 0; i < n; ++i) {
      v90[n-1-one[i]] = i;
    }
    // (i, j) to (7-i, 7-j)
    for (int i = 0; i < n; ++i) {
      v180[n-1-i] = n-1-one[i];
    }
    // (i, j) to (j, 7-i)
    for (int i = 0; i < n; ++i) {
      v270[one[i]] = n-1-i;
    }
    // (i, j) to (i, 7-j) left/right
    for (int i = 0; i < n; ++i) {
      vy[i] = n-1-one[i];
    }
    // (i, j) to (7-i, j) up/down
    for (int i = 0; i < n; ++i) {
      vx[n-1-i] = one[i];
    }
    // (i, j) to (j, i)
    for (int i = 0; i < n; ++i) {
      vyx[one[i]] = i;
    }
    // (i, j) to (7-j, 7-i)
    for (int i = 0; i < n; ++i) {
      vyx_[n-1-one[i]] = n-1-i;
    }
    //
    return {one, v90, v180, v270, vy, vx, vyx, vyx_};
  }

  // convert vector<int> into string then use it as hashmap key.
  string to_string(vector<int> &v) {
    stringstream ss;
    for (auto &i : v)
      ss << i;
    return ss.str();
  }

  // remove all the symmetrical cases, return only fundamental solutions
  vector<vector<int>> fundamental(vector<vector<int>> &solutions) {
    vector<vector<int>> fund;
    unordered_map<string, bool> hash;
    for (auto &solution : solutions) {
      // already there
      if (hash.count(to_string(solution)))
        continue;
      // not found
      fund.push_back(solution);
      for (auto &sym : symmetricals(solution)) {
        hash[to_string(sym)] = true;
      }
    }
    return fund;
  }

  // print the solution visually in a chess board.
  // ONLY works for n = 8 now!!!
  void print_board(vector<int> &solution) {
    print_vector(solution);
    for (int &r : solution) {
      string s = "........";
      s[r] = 'x';
      cout << s << endl;
    }
    cout << endl;
  }

  void test(int n = 8) {
    auto result = cols(n);
    printf("%d-queens problem has %d solutions.\n", n, result.size());
    print_vector2d(result);

    auto fund = fundamental(result);
    printf("\n\n%d-queens problem has %d FUNDAMENTAL solutions.\n", n, fund.size());
    print_vector2d(fund);

    printf("\nVisual boards\n");
    for (auto &solution : fund) {
      print_board(solution);
    }
    printf("\nYou can compare above results with:\nhttps://en.wikipedia.org/wiki/Eight_queens_puzzle. :\)\n");
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test();
//    test(10);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

