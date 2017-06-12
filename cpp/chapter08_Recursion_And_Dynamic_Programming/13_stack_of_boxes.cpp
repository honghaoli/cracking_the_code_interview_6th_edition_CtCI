//
// Created by Honghao Li on 4/22/17.
//


// Problem
// You have a stack of n boxes, with width wi, height hi, and depths di. The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height and depth. Implement a method to compute the height of the tallest possible stack. The height of a stack is the sum of the heights of each box.



#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// width etc. can be double or int.
// for convenience we use int
struct Box {
  Box() = default;
  Box(int wi, int hi, int di) : width(wi), height(hi), depth(di) {}
  int width = 0;
  int height = 0;
  int depth = 0;

  bool operator < (const Box &b) {
    return width < b.width && height < b.height && depth < b.depth;
  }

  bool operator > (const Box &b) {
    return width > b.width && height > b.height && depth > b.depth;
  }

};


// 1st method
// recursively calculate the height for each box when this box is in the bottom or on the top.

// max height when i-th box is at bottom;
int max_height_when_at_bottom(vector<Box> &boxes, int i, vector<int> &max_bottom) {

  if (max_bottom[i] > 0)  // dynamical programming in case.
    return max_bottom[i];

  if (i >= boxes.size())  // boundary check
    return 0;

  auto &b = boxes[i];
  int maxh = 0;
  for (int k = 0; k < boxes.size(); k++) {
    if (boxes[k] < b ) {
      int m = max_height_when_at_bottom(boxes, k, max_bottom);
      if (m > maxh)
        maxh = m;
    }
  }
  max_bottom[i] = b.height + maxh;
  return max_bottom[i];
}

int max_height(vector<Box> &boxes) {
  vector<int> max_bottom(boxes.size(), -1);
  for (int k = 0; k < boxes.size(); k++) {
    max_height_when_at_bottom(boxes, k, max_bottom);
  }
  return *max_element(max_bottom.begin(), max_bottom.end());
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

  void test1() {
    vector<Box> boxes;
    boxes.push_back(Box(1,1,1));
    boxes.push_back(Box(2,2,2));
    boxes.push_back(Box(3,3,3));
    int h = max_height(boxes);
    printf("max height is: %d, correct answer: 6.\n", h);
  }
  void test2() {
    vector<Box> boxes;
    boxes.push_back(Box(1,1,1));
    boxes.push_back(Box(2,2,2));
    boxes.push_back(Box(3,3,1));
    int h = max_height(boxes);
    printf("max height is: %d, correct answer: 3.\n", h);
  }
  void test3() {
    vector<Box> boxes;
    boxes.push_back(Box(1,1,1));
    boxes.push_back(Box(2,2,2));
    boxes.push_back(Box(3,3,3));
    boxes.push_back(Box(10,10,10));
    boxes.push_back(Box(80,80,80));
    boxes.push_back(Box(1,100,1));
    int h = max_height(boxes);
    printf("max height is: %d, correct answer: 100.\n", h);
  }
  void test4() {
    vector<Box> boxes;
    boxes.push_back(Box(100,100,100));
    boxes.push_back(Box(50,50,9));
    boxes.push_back(Box(30,30,8));
    boxes.push_back(Box(40,19,7));
    boxes.push_back(Box(30,70,50));
    boxes.push_back(Box(11,5,30));
    boxes.push_back(Box(10,4,10));
    int h = max_height(boxes);
    printf("max height is: %d, correct answer: 180.\n", h);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
    test2();
    test3();
    test4();

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

