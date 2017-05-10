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

  return 0;
}

