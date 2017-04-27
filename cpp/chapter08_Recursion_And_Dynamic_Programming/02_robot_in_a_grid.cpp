//
// Created by Honghao Li on 4/22/17.
//


// Problem 02
// Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only move in two directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.



#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

#include "graph.h"

using namespace std;

struct Grid {
  Grid() = default;
  Grid(int r, int c) {
    row = r;
    col = c;
  }

  int row = 0;
  int col = 0;
  bool mark = false;
  bool block = false;

};


struct Grids {
  int row = 0;
  int col = 0;
  vector<vector<Grid> > grids;

  Grids() = default;
  Grids(int r, int c) : row(r), col(c) {
    for (int i = 0; i < r; ++i) {
      vector<Grid> tmp;
      for (int j = 0; j < c; ++j) {
        tmp.push_back(Grid(i, j));
      }
      grids.push_back(tmp);
    }
  }

  int id(int i, int j) {
    return i * col + j;
  }

  int r(int i) {
    return i / col;
  }
  int c(int i) {
    return i % col;
  }

  void add_block(int i, int j) {
    grids.at(i).at(j).block = true;
  }

  void print() {
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        printf("%c", grids[i][j].block? 'x' : 'o');
      }
      printf("\n");
    }
  }

};


// 1st method
// simple BFS
void find_path1(Grids& gs) {
  DiGraph g = DiGraph(gs.col * gs.row);

  // add edges if it is not a block
  for (int i = 0; i < gs.row; ++i) {
    for (int j = 0; j < gs.col; ++j) {
      if (j < gs.col - 1 && !gs.grids[i][j+1].block )
        g.addEdge(gs.id(i, j), gs.id(i, j+1));
      if (i < gs.row - 1 && !gs.grids[i+1][j].block )
        g.addEdge(gs.id(i, j), gs.id(i+1, j));
    }
  }

  int s = 0;
  int v = g.V() - 1;
  gs.print();

  BreadthFirstPaths search = BreadthFirstPaths(g, s);

  // print
  printf("(%d, %d) to (%d, %d): ", gs.r(s), gs.c(s), gs.r(v), gs.c(v));
  if (search.hasPathTo(v)) {
    for (auto &x : *search.pathTo(v)) {
      if (x == s)
        printf("(%d, %d)", gs.r(x), gs.c(x));
      else
        printf(" -> (%d, %d)", gs.r(x), gs.c(x));
    }
    printf("\n\n");
  } else {
    printf("No possible way found!\n\n");
  }
}



// 2nd method
// use dynamic programming
// as shown in the text book
vector<tuple<int, int> > path;

bool gridToStart(Grids &gs, int i, int j) {
  if (i < 0 || j < 0 || gs.grids[i][j].block || gs.grids[i][j].mark)
    return false;
  //
  bool isStart = (i == 0 && j == 0);
  if ( isStart || gridToStart(gs, i - 1, j) || gridToStart(gs, i, j - 1) ) {
    path.push_back(make_tuple(i, j));
    return true;
  }
  // restore fail points as marked
  gs.grids[i][j].mark = true;
  return false;
}

void find_path2(Grids& gs) {
  gs.print();

  path.clear();
  bool success = gridToStart(gs, gs.row - 1, gs.col - 1);

  // print
  if (!success) {
    printf("No possible way found!\n\n");
    return;
  }
  //
  for (auto &p : path) {
    printf(" -> (%d, %d)", get<0>(p), get<1>(p));
  }
  printf("\n\n");
}



////////////////////
void find_path(Grids& gs) {
//  find_path1(gs);
  find_path2(gs);
}

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
    Grids gs;
    gs = Grids(3, 3);
    find_path(gs);

    gs.add_block(0, 2);
    find_path(gs);

    gs.add_block(1, 1);
    find_path(gs);

    gs.add_block(2, 1);
    find_path(gs);

    gs = Grids(5, 5);
    gs.add_block(1, 1);
    gs.add_block(2, 1);
    gs.add_block(3, 1);
    gs.add_block(4, 1);
    gs.add_block(1, 4);
    gs.add_block(2, 4);
    gs.add_block(3, 4);
    gs.add_block(3, 3);
    find_path(gs);

    gs.add_block(1, 2);
    find_path(gs);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}



