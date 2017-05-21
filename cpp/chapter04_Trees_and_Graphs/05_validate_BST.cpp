//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Implement a function to check if a binary tree is a binary search tree.





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
void print_tree(Node<int> *p, int indent = 0) {
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
// for each node in BST, all elements in left subtree <= this node <= all elements in right subtree.

// first, find the max and min for the subtree rooted with node;
// if this subtree is not BST, return false bool; else return true;
tuple<bool, int, int> min_max_in_subtree(Node<int> *node) {
  if (node == nullptr)
    throw "input node cannot be nullptr.\n";
  int _max = node->item, _min = node->item;
  bool _bst = true;
  int _max_left, _min_left;
  bool _bst_left;
  int _max_right, _min_right;
  bool _bst_right;
  if (node->left != nullptr) {
    tie(_bst_left, _min_left, _max_left) = min_max_in_subtree(node->left);
    _bst = _bst && _bst_left && _max_left <= node->item;
    _min = max(_min, _min_left);
  }
  if (node->right != nullptr) {
    tie(_bst_right, _min_right, _max_right) = min_max_in_subtree(node->right);
    _bst = _bst && _bst_right && _max_right >= node->item;
    _max = max(_max, _max_right);
  }
  //
  return make_tuple(_bst, _min, _max);
}

bool is_bst(Node<int> *root) {
  int _max, _min;
  bool _bst;
  tie(_bst, _max, _min) = min_max_in_subtree(root);
  return _bst;
}


// 2nd method
// text book use another method similar to above, just passing from top to bottom, inverse of method above.


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


    // 1st tree test
    vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    auto res = minimal_tree(v);
    print_tree(&res);
    printf("BST?: %s\n\n", is_bst(&res) ? "True" : "False");

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
    printf("BST?: %s\n\n", is_bst(&tree2) ? "True" : "False");

    // 3rd tree test
    Node<int> tree3;
    Node<int> n1(1);
    Node<int> n2(2);
    Node<int> n3(3);
    Node<int> n4(4);
    Node<int> n5(5);
    tree3.right = &n1;
    n1.right= &n2;
    n2.right= &n3;
    n3.right= &n4;
    n4.right = &n5;
    print_tree(&tree3);
    printf("BST?: %s\n\n", is_bst(&tree3) ? "True" : "False");

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

