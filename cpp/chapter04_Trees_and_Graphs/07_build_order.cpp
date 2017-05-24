//
// Created by Honghao Li on 4/22/17.
//

// Problem
// You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first project). All of a project's dependencies must be build before the project is. Find a build order that will allow the projects to be built. If there is no valid build order, return an error.
// EXAMPLE:
// Input:
//    projects:     a, b, c, d, e, f
//    dependencies:   (a, b), (f, d), (b, d), (f, a), (d, c)
// Output:
//    f, e, a, b, d, c





#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

#include "../lib/graph.h"

using namespace std;




// 1st method
// see graph.h for implementation of topological order of a graph.
// also see Algorithm 4th, page 574 -- page 581 for details
void unit_test() {
  // 1st test
  // Algorithm 4th, page 579 example
  DiGraph g = DiGraph(13);
  g.addEdge(0, 5);
  g.addEdge(0, 1);
  g.addEdge(0, 6);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(5, 4);
  g.addEdge(6, 4);
  g.addEdge(6, 9);
  g.addEdge(7, 6);
  g.addEdge(8, 7);
  g.addEdge(9, 10);
  g.addEdge(9, 11);
  g.addEdge(9, 12);
  g.addEdge(11, 12);

  DirectedCycle dc = DirectedCycle(g);
  if (!dc.hasCycle()) {
    DepthFirstOrder order = DepthFirstOrder(g);
    order.printReversePost();
  } else {
    printf("Test 1 graph has cycle!!!\n");
  }

  // 2nd test
  DiGraph g2 = DiGraph(3);
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.addEdge(2, 0);
  DirectedCycle dc2 = DirectedCycle(g2);
  if (!dc2.hasCycle()) {
    DepthFirstOrder order2 = DepthFirstOrder(g2);
    order2.printReversePost();
  } else {
    printf("Test 2 graph has cycle!!!\n");
  }

  // 3rd test, example in the title
  // Input:
  //    projects:     a, b, c, d, e, f
  //    dependencies:   (a, b), (f, d), (b, d), (f, a), (d, c)
  // Output:
  //    f, e, a, b, d, c
  DiGraph g3 = DiGraph(6);
  g3.addEdge(0, 1);
  g3.addEdge(5, 3);
  g3.addEdge(1, 3);
  g3.addEdge(5, 0);
  g3.addEdge(3, 2);
  DirectedCycle dc3 = DirectedCycle(g3);
  if (!dc3.hasCycle()) {
    DepthFirstOrder order3 = DepthFirstOrder(g3);
    //  should be:    -> 5 -> 4 -> 0 -> 1 -> 3 -> 2
    order3.printReversePost();
  } else {
    printf("Test 3 graph has cycle!!!\n");
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

