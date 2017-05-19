//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.




#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

#include "../lib/linked_list.h"

using namespace std;

template <typename T>
struct Node {
  Node() = default;
  Node(T _item) : item(_item) {}
  T item;
  Node *left = nullptr;
  Node *right = nullptr;
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



// 1st method
// Get the height of two subtree of any node, then recursively reach the root.

// check if the node is balanced
// if not, return -1
// else return the height.
int is_node_balanced(Node<int> *node) {
  if (node == nullptr)
    return 0;
  //
  int left = is_node_balanced(node->left);
  int right = is_node_balanced(node->right);
  //
  if (left < 0 || right < 0 || abs(left - right) > 1)
    return -1;      // not balanced,
  else
    return max(left, right) + 1;    // balanced return height
}

bool is_tree_balanced(Node<int> *root) {
  int height = is_node_balanced(root);
  if (height < 0)
    return false;
  printf("tree height %d\n", height);
  return true;
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

    vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    auto res = minimal_tree(v);
    print_tree(&res);
    printf("Balanced: %s\n", is_tree_balanced(&res) ? "True" : "False");

    // second tree test
    Node<int> tree2;
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    tree2.left = &node1;
    tree2.right = &node2;
    node2.left = &node3;
    node3.left = &node4;
    node3.right = &node5;
    print_tree(&tree2);
    printf("Balanced: %s\n", is_tree_balanced(&tree2) ? "True" : "False");

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

