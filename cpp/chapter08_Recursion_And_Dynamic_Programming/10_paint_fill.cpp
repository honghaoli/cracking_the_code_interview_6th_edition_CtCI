//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill the surrounding area until the color changes from the original color.



#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include "../lib/helper.h"


using namespace std;



// 1st method
// BFS to search neighbor and change color.
void paint_fill(vector<vector<int>> &screen, int i, int j, int color) {
  if (screen.size() == 0)
    throw "Wrong screen parameters!\n";

  int old = screen[i][j];
  if (color == old)   // old color == new color, no need to fill
    return;
  const vector<int> dx = {0, 0, 1, -1};
  const vector<int> dy = {1, -1, 0, 0};

  queue<vector<int>> frontier;
  frontier.push({i, j});
  while (!frontier.empty()) {
    int fx = frontier.front()[0];
    int fy = frontier.front()[1];
    screen[fx][fy] = color;
    frontier.pop();
    for (int k = 0; k < 4; ++k) {
      int x = fx + dx[k];
      int y = fy + dy[k];
      if (x >= 0 && x < screen.size() && y >= 0 && y < screen[0].size() && screen[x][y] == old)
        frontier.push({x, y});
    }
  }
}



// 2nd method
// TODO: the book solution use DFS recursive function.



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test(vector<vector<int>> &screen, int i, int j, int color) {
    printf("original screen");
    print_vector2d(screen);
    paint_fill(screen, i, j, color);
    printf("after fill (%d, %d) with color %d", i, j, color);
    print_vector2d(screen);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    vector<vector<int>> screen = {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
    };
    test(screen, 2, 2, 2);
    test(screen, 1, 2, 3);
    test(screen, 1, 1, 4);

    vector<vector<int>> screen2 = {
        {0,1,0,3,3,3,3,3,3},
        {0,1,1,0,0,0,0,0,3},
        {0,0,1,0,0,3,3,0,3},
        {0,0,1,1,0,3,3,3,3},
        {0,1,1,1,0,3,0,0,0},
        {0,0,1,0,0,0,0,2,2},
        {0,1,1,0,0,2,2,2,2},
        {0,1,1,0,2,2,2,2,0},
        {0,0,0,0,2,0,0,0,0}
    };
    test(screen2, 0, 1, 4);
    test(screen2, 0, 8, 5);
    test(screen2, 8, 4, 6);
    test(screen2, 0, 0, 7);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

