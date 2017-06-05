//
// Created by Honghao Li on 4/22/17.
//

// Problem
// In the clasic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following constraints:
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto another tower.
// (3) A disk cannot be placed on top of a smaller disk.
// Write a program to move the disks from the first tower to the last using stacks.




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
// If we want to move disk 1...N from stack A to stack C, we first move disks 1...N-1 from A to B, and move disk N from A to C, then move disks 1...N-1 from B to C.
// and the 2nd step is a recursive function.
// for simplicity, we usw vector as stack.
// the function returns total steps needed
int move_k_disks(int k, vector<int> &from, vector<int> &to, vector<int> &temp, bool show_step = false) {
  if (from.size() < k)
    throw "ERROR! not enough disks to move from\n.";
  if (k == 1) {     // only one disk, move directly
    int elem = from.back();
    from.pop_back();
    to.push_back(elem);
    // for debug the steps
    if (show_step) {
      cout << "\nStep\n";
      cout << "from: ";
      print_vector(from);
      cout << "to: ";
      print_vector(to);
      cout << "temp: ";
      print_vector(temp);
    }
    return 1;
  } else {          // more than one disks, move k-1 disks to temp, and last one to to, then move k-1 from temp to to.
    return move_k_disks(k - 1, from, temp, to, show_step)
        + move_k_disks(1, from, to, temp, show_step)
        + move_k_disks(k - 1, temp, to, from, show_step);
  }
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

  // move n disks from A to C, with temp B.
  void test(int n) {
    vector<int> A, B, C;
    // initial disks in A.
    for (int i = n; i > 0; --i) {
      A.push_back(i);
    }
    cout << "\nInitial\n";
    cout << "A: ";
    print_vector(A);
    cout << "B: ";
    print_vector(B);
    cout << "C: ";
    print_vector(C);
    //
    int steps = move_k_disks(n, A, C, B, true);
    //
    cout << "\nAfter\n";
    cout << "A: ";
    print_vector(A);
    cout << "B: ";
    print_vector(B);
    cout << "C: ";
    print_vector(C);

    printf("\nTotal steps %d\n", steps);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test(3);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

