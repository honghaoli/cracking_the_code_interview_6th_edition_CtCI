//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * An ant is sitting on an infinite grid of white and black squares. It initially faces right. At each step, it does the following:
 * (1) At a white squares, flip the color of the square, turn 90 degrees right (clockwise), and move forward one unit.
 * (2) At a black Square, flip the color of the square, turn 90 degrees left (counter-clockwise), and move forward one unit.
 * Write a program to simulate the first K moves that the ant makes and print the final board as a grid.
 * Note you are not provided with the data structure to represent the grid. This is something you must design yourself. The only input to your method is K. You should print the final grid and return nothing. The method signature might be something like void printKMoves(int K).
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method

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

  void test1() {
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

