//
// Created by Honghao Li on 4/22/17.
//

// Problem
// T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.
// A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n id identical to T2. that is, if you cut off the tree at node n, the two trees would be identical.

// clarification:
// when we say identical nodes, are they identical objects (address) or identical data ?
// we assume it's the first case, they are identical by object (address).
// BUT according to the book, identical is defined by data (item value).



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
// recursively compare two nodes and all children, return false once there is difference.
// this solution is similar to Solution 2 in the book
// this method takes O(log(n) + log(m)) space.
// time complexity is complex, ~ O(n + km), please refer to the book
bool two_node_identical(Node<int> *n1, Node<int> *n2) {
  return n1 == n2;    // identical by object
//  return n1->item == n2->item;    // identical by data
}

bool two_trees_identical(Node<int> *n1, Node<int> *n2) {
  if (!two_node_identical(n1, n2))
    return false;
  //
  if (n1 == nullptr && n2 == nullptr)
    return true;
  if (!two_trees_identical(n1->left, n2->left)) {
    return false;
  }
  if (!two_trees_identical(n1->right, n2->right)) {
    return false;
  }
  return true;
}

bool is_subtree(Node<int> *smaller, Node<int> *larger) {
  if (larger != nullptr) {
    if (two_trees_identical(larger, smaller))
      return true;
    if (is_subtree(smaller, larger->left))
      return true;
    if (is_subtree(smaller, larger->right))
      return true;
  } else if (smaller == nullptr) {  // both are nullptr
    return true;
  }
  return false;
}



// 2nd method
// TODO: here we include the Solution 1 in the book
// Create a pre-order traversal as a string, replace null end as special character.
// Then check if T2 string is a substring in T1
// this method takes O(n + m) time and O(n + m) space.



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
    auto n1 = tree1.left;
    auto n2 = &tree1;
    bool res  = two_trees_identical(n1, n2);
    printf("\nNode (%d) and Node (%d) are the same? %s\n", n1->item, n2->item, res ? "True" : "False");
    bool r = is_subtree(n1, n2);
    printf("Node (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");

    printf("\n============== Test tree 2 ==============\n");
    vector<int> v2 {1,2,3,4,5,6,7};
    auto tree2 = minimal_tree(v2);
    print_tree(&tree2);
    n1 = &tree2;
    n2 = &tree2;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");
    n1 = tree2.left;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");
    n1 = tree2.left->left;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");
    n1 = tree2.left->right;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");
    n1 = tree2.right->right;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");
    n2 = tree2.right;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");
    n1 = tree2.left->right;
    n2 = tree2.right;
    r = is_subtree(n1, n2);
    printf("\nNode (%d) is subtree of Node (%d)? %s\n", n1->item, n2->item, r ? "True" : "False");

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
