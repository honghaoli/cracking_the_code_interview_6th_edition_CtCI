//
// Created by Honghao Li on 4/25/17.
//

#ifndef CTCI_6TH_GRAPH_H
#define CTCI_6TH_GRAPH_H

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>

/// Undirected Graph
class Graph {
 public:
  Graph() = default;
  Graph(int V) : _V(V), _E(0) {
    for (int i = 0; i < V; ++i) {
      _adj.push_back(std::vector<int>());
    }
  }

  int V() { return _V; }
  int E() { return _E; }

  virtual void addEdge(int v, int w) {
    _adj[v].push_back(w);
    _adj[w].push_back(v);
    _E++;
  }

  std::vector<int> adj(int v) {
    return _adj[v];
  }

 protected:
  int _V;    // number of vertices
  int _E;    // number of edges
  std::vector<std::vector<int> > _adj;  // adjacency lists
};


// Directed Graph
class DiGraph : public Graph {
 public:
  DiGraph() = default;
  DiGraph(int V) : Graph(V) {}

  void addEdge(int v, int w) override {
    _adj[v].push_back(w);
    _E++;
  }

};



class DepthFirstPaths {
 public:
  DepthFirstPaths() = default;
  DepthFirstPaths(Graph G, int s) : s(s) {
    marked.resize(G.V(), false);
    edgeTo.resize(G.V(), -1);   // -1 means no vertex connects to current vertex
    dfs(G, s);
  }

  bool hasPathTo(int v) { return marked[v]; }

  std::vector<int>* pathTo(int v) {
    if (!hasPathTo(v))
      return nullptr;
    path.clear();
    for (int x = v; x != s; x = edgeTo[x]) {
      path.push_back(x);
    }
    path.push_back(s);
    std::reverse(path.begin(), path.end());
    return &path;
  }

  void printPathTo(int v) {
    printf("%d to %d: ", s, v);
    if (hasPathTo(v)) {
      for (auto &x : *pathTo(v)) {
        if (x == s)
          printf("%d", x);
        else
          printf("--%d", x);
      }
    }
    printf("\n");
  }

 private:
  std::vector<bool> marked;  // Has dfs() been called for this vertex?
  std::vector<int> edgeTo;   // last vertex on known path to this vertex
  std::vector<int> path;   // store the path
  int s;    // source

  void dfs(Graph& G, int v) {
    marked[v] = true;
    for (auto &w : G.adj(v)) {
      if (!marked[w]) {
        edgeTo[w] = v;
        dfs(G, w);
      }
    }
  }

};


class BreadthFirstPaths {
 public:
  BreadthFirstPaths() = default;
  BreadthFirstPaths(Graph G, int s) : s(s) {
      marked.resize(G.V(), false);
      edgeTo.resize(G.V(), -1);   // -1 means no vertex connects to current vertex
      bfs(G, s);
  }

  bool hasPathTo(int v) { return marked[v]; }

  std::vector<int>* pathTo(int v) {
    if (!hasPathTo(v))
      return nullptr;
    path.clear();
    for (int x = v; x != s; x = edgeTo[x]) {
      path.push_back(x);
    }
    path.push_back(s);
    std::reverse(path.begin(), path.end());
    return &path;
  }

  void printPathTo(int v) {
    printf("%d to %d: ", s, v);
    if (hasPathTo(v)) {
      for (auto &x : *pathTo(v)) {
        if (x == s)
          printf("%d", x);
        else
          printf("--%d", x);
      }
    }
    printf("\n");
  }

 private:
  std::vector<bool> marked;  // Has dfs() been called for this vertex?
  std::vector<int> edgeTo;   // last vertex on known path to this vertex
  std::vector<int> path;   // store the path
  int s;    // source

  void bfs(Graph& G, int s) {
    std::queue<int> q;
    marked[s] = true;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &w : G.adj(v)) {
        if (!marked[w]) {
          edgeTo[w] = v;
          marked[w] = true;
          q.push(w);
        }
      }
    }
  }

};


// Algorithm 4th, page 577,
// Finding a directed cycle
class DirectedCycle {
 public:
  DirectedCycle() = default;
  DirectedCycle(DiGraph G) {
    marked.resize(G.V(), false);
    onStack.resize(G.V(), false);
    edgeTo.resize(G.V(), -1);   // -1 means no vertex connects to current vertex
    for (int v = 0; v < G.V(); ++v) {
      if (!marked[v])
        dfs(G, v);
    }
  }

  bool hasCycle() {
    return cycle.size() > 0;
  }

  void printCycle() {
    for (auto &v : cycle)
      std::cout << v << " -> ";
    std::cout << std::endl;
  }

 private:
  std::vector<bool> marked;
  std::vector<int> edgeTo;   // last vertex on known path to this vertex
  std::vector<bool> onStack;
  std::vector<int> cycle;   // last vertex on known path to this vertex

  void dfs(Graph& G, int v) {
    onStack[v] = true;
    marked[v] = true;
    for (auto &w : G.adj(v)) {
      if (hasCycle()) return;
      else if (!marked[w]) {
        edgeTo[w] = v;
        dfs(G, w);
      }
      else if (onStack[w]) {
        cycle = std::vector<int>();
        for (int x = v; x != w; x = edgeTo[x]) {
          cycle.push_back(x);
        }
        cycle.push_back(w);
        cycle.push_back(v);
      }
    }
    onStack[v] = false;
  }

};



// Algorithm 4th, page 580
// Depth-first search vertex ordering in a digraph
class DepthFirstOrder {
 public:
  DepthFirstOrder() = default;
  DepthFirstOrder(Graph G) {
    marked.resize(G.V(), false);
    for (int v = 0; v < G.V(); ++v) {
      if (!marked[v])
        dfs(G, v);
    }
  }

  void printReversePost() {
    printf("total %lu nodes.\n", reversePost.size());
    for (int i = reversePost.size()-1; i >= 0; i--)
      std::cout << " -> " << reversePost[i];
    std::cout << std::endl;
  }

 private:
  std::vector<bool> marked;  // Has dfs() been called for this vertex?
  std::queue<int> pre;
  std::queue<int> post;
  std::vector<int> reversePost;

  void dfs(Graph& G, int v) {
    pre.push(v);

    marked[v] = true;
    for (auto &w : G.adj(v)) {
      if (!marked[w]) {
        dfs(G, w);
      }
    }

    post.push(v);
    reversePost.push_back(v);
  }
};



#endif //CTCI_6TH_GRAPH_H
