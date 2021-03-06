//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.



#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <typename T>
struct Node {
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

// 1st method
// choose the middle element as the root, left part for left child, right part for right child, recursively.
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

// 2nd method
// text book gives the same method as I did above.



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

    vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    auto res = minimal_tree(v);
//    printf("tree root: %d\n", res.item);
//    in_order_traversal(&res);
    print_tree(&res);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
