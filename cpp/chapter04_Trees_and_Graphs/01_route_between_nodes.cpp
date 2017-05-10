//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Given a directed graph, design an algorithm to find out whether there is a route between two nodes.


// Answer:
// just use the basic implementation of graph.h

#include <cstdio>
#include <iostream>
#include <vector>

#include "../lib/graph.h"

using namespace std;

// 1st method
void test_bfs() {
  DiGraph G = DiGraph(13);
  G.addEdge(0, 5);
  G.addEdge(4, 3);
  G.addEdge(0, 1);
  G.addEdge(9, 12);
  G.addEdge(6, 4);
  G.addEdge(5, 4);
  G.addEdge(0, 2);
  G.addEdge(11, 12);
  G.addEdge(9, 10);
  G.addEdge(0, 6);
  G.addEdge(7, 8);
  G.addEdge(9, 11);
  G.addEdge(5, 3);

  int s = 0;
//  DepthFirstPaths search = DepthFirstPaths(G, s);
  BreadthFirstPaths search = BreadthFirstPaths(G, s);
  for (int v = 0; v < G.V(); ++v) {
    search.printPathTo(v);
  }

}



// 2nd method
void test_dfs() {
  DiGraph G = DiGraph(13);
  G.addEdge(0, 5);
  G.addEdge(4, 3);
  G.addEdge(0, 1);
  G.addEdge(9, 12);
  G.addEdge(6, 4);
  G.addEdge(5, 4);
  G.addEdge(0, 2);
  G.addEdge(11, 12);
  G.addEdge(9, 10);
  G.addEdge(0, 6);
  G.addEdge(7, 8);
  G.addEdge(9, 11);
  G.addEdge(5, 3);

  int s = 0;
  DepthFirstPaths search = DepthFirstPaths(G, s);
//  BreadthFirstPaths search = BreadthFirstPaths(G, s);
  for (int v = 0; v < G.V(); ++v) {
    search.printPathTo(v);
  }

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

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test_bfs();
    test_dfs();

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
