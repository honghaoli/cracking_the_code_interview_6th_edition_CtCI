//
// Created by honghao on 4/26/17.
//

#include <cstdio>
#include "graph.h"


////////////////////// Main ////////////////////////
int main() {

  Graph G = Graph(13);
//  DiGraph G = DiGraph(13);
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



  // test directed graph
  DiGraph DG = DiGraph(5);
  DG.addEdge(0, 1);
  DG.addEdge(1, 2);
  DG.addEdge(2, 3);
  DG.addEdge(3, 4);

  DirectedCycle dc = DirectedCycle(DG);
  printf("\nDirected Graph has cycle? %s\n", dc.hasCycle() ? "True" : "False");
  dc.printCycle();
  DepthFirstOrder order = DepthFirstOrder(DG);
  order.printReversePost();

  DG.addEdge(4, 0);
  dc = DirectedCycle(DG);
  printf("Directed Graph has cycle? %s\n", dc.hasCycle() ? "True" : "False");
  dc.printCycle();

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
  DepthFirstOrder order2 = DepthFirstOrder(g);
  order2.printReversePost();

  return 0;
}

