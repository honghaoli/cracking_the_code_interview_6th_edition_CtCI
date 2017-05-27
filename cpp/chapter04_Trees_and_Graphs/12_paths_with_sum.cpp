//
// Created by Honghao Li on 4/22/17.
//

// Problem
// You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to given value. Tha path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).





#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

#include "../lib/helper.h"

using namespace std;


template <typename T>
struct Node {
  T item;
  Node *left = nullptr;
  Node *right = nullptr;
  vector<T> sums;     // only for this problem.
  bool calculated = false;
};

template <typename T>
void visit(Node<T> *node) {
  cout << node->item << " ";
}

template <typename T>
void in_order_traversal(Node<T> *node) {
  if (node != nullptr) {
    in_order_traversal(node->left);
    visit(node);
    in_order_traversal(node->right);
  }
}

// print the tree from top to bottom, in command line, it shows from left to right.
void print_tree(Node<int> *p, int indent = 0)
{
  if(p != nullptr) {
    if(p->left) print_tree(p->left, indent + 4);
    if (indent) {
      cout << setw(indent) << ' ';
    }
    cout<< p->item << "\n ";
    if(p->right) print_tree(p->right, indent + 4);
  }
}

////////// use previous method (problem 04-02) to create a tree /////////////////////
void add_to_node(Node<int> *n, vector<int> &v, int lo, int hi) {
  int mid = (hi - lo) / 2 + lo;
  n->item = v[mid];
  if (mid > lo) {
    n->left = new Node<int>();
    add_to_node(n->left, v, lo, mid - 1);
  }
  if (mid < hi) {
    n->right = new Node<int>();
    add_to_node(n->right, v, mid + 1, hi);
  }
}

Node<int> minimal_tree(vector<int> &v) {
  Node<int> result;
  add_to_node(&result, v, 0, v.size() - 1);
  return result;
}



int calculate_tree_size(Node<int> *n) {
  if (n == nullptr)
    return 0;
  int size = 1;   // current node counts 1
  if (n->left != nullptr)
    size += calculate_tree_size(n->left);
  if (n->right != nullptr)
    size += calculate_tree_size(n->right);
  return size;
}



// 1st method
// recursively calculate all possible sums for each node.
void find_sums(Node<int> *n) {
  // only consider this node
  n->sums.push_back(n->item);
  // has children
  if (n->left != nullptr) {
    // if not calculated
    if (!n->left->calculated)
      find_sums(n->left);
    for (auto &s : n->left->sums) {
      n->sums.push_back(s + n->item);
    }
  }
  if (n->right != nullptr) {
    // if not calculated
    if (!n->right->calculated)
      find_sums(n->right);
    for (auto &s : n->right->sums) {
      n->sums.push_back(s + n->item);
    }
  }
  // for test
  printf("Node (%d) has sums:\n", n->item);
  print_vector(n->sums);
}

// count sums for only this node
int count_node(Node<int> *n, int target) {
  if (n == nullptr)
    return 0;
  int count = 0;
  for (auto &s : n->sums) {
    if (s == target)
      count++;
  }
  return count;
}

// count sums for this node and all its children
int count_sums(Node<int> *root, int target) {
  int sum = 0;
  if (root != nullptr) {
    sum += count_node(root, target);
    sum += count_sums(root->left, target);
    sum += count_sums(root->right, target);
  }
  return sum;
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

    //
    printf("\n============== Test tree 1 ==============\n");
    vector<int> v {1, 2, 3};
    auto tree1 = minimal_tree(v);
    print_tree(&tree1);
    printf("tree size %d.\n", calculate_tree_size(&tree1));
    find_sums(&tree1);
    for (int i = 0; i < 6; ++i) {
      printf("Tree has %d path(s) of value %d.\n", count_sums(&tree1, i), i);
    }

    printf("\n============== Test tree 2 ==============\n");
    vector<int> v2 {1,2,3,4,5,6,7};
    auto tree2 = minimal_tree(v2);
    print_tree(&tree2);
    printf("tree size %d.\n", calculate_tree_size(&tree2));
    find_sums(&tree2);
    for (int i = 0; i < 18; ++i) {
      printf("Tree has %d path(s) of value %d.\n", count_sums(&tree2, i), i);
    }

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
