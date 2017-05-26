//
// Created by Honghao Li on 4/22/17.
//

// Problem
// A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.
// EXAMPLE
// INPUT:
//                     (2)
//                    /   \
//                  (1)   (3)
// OUTPUT:
// {2, 1, 3}, {2, 3, 1}



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
// for each node, the sequence would be current node + all combination of left and right subtree nodes' sequences.
// for example, left is {1} and right is {3}, then all combination would be {1,3} and {3,1}, choose one from two to set as the left sequence.
// for example, left is {1} and right is { {4, 3, 5}, {4, 5, 3} }, then total would be four elements. choose one from four:
//              {1, X, X, X} and {X, 1, X, X} and {X, X, 1, X} and {X, X, X, 1}, all the Xs are filled with right sequences.
// The trickiest part is to combine two sequences into one, the word 'weave' is used in the textbook. And a better recursive solution is provided in the book.
// combine {1, 2} and {3, 4} is recursively add {1} to the combination of {2} and {3, 4}, and add {3} to combination of {1,2} and {4}.
vector<vector<int>> weave_two(vector<int> &v1, int start1, vector<int> &v2, int start2) {
  vector<vector<int>> all;
  if (start1 >= v1.size()) {  // empty
    vector<int> v_;
    v_.insert(v_.begin(), v2.begin() + start2, v2.end());
    all.push_back(v_);
    return all;
  }
  if (start2 >= v2.size()) {  // empty
    vector<int> v_;
    v_.insert(v_.begin(), v1.begin() + start1, v1.end());
    all.push_back(v_);
    return all;
  }
  // recursion
  auto sub1 = weave_two(v1, start1 + 1, v2, start2);
  for (auto &s : sub1) {
    s.insert(s.begin(), v1[start1]);
    all.push_back(s);
  }
  auto sub2 = weave_two(v1, start1, v2, start2 + 1);
  for (auto &s : sub2) {
    s.insert(s.begin(), v2[start2]);
    all.push_back(s);
  }
  return all;
}

vector<vector<int>> sequence_of_node(Node<int> *n) {
  vector<vector<int>> left, right;
  if (n->left != nullptr)
    left = sequence_of_node(n->left);
  if (n->right != nullptr)
    right = sequence_of_node(n->right);
  //
  vector<vector<int>> all;
  if (left.size() == 0)
    all = right;
  else if (right.size() == 0)
    all = left;
  else {
    for (auto &l : left) {
      for (auto &r : right) {
        auto tmp = weave_two(l, 0, r, 0);
        all.insert(all.end(), tmp.begin(), tmp.end());
      }
    }
  }
  //  add current node to the head
  if (all.size() == 0)
    all = {{}};
  for (auto &s : all) {
    s.insert(s.begin(), n->item);
  }
  //
  return all;
}


// 2nd method
// from bottom to top, each time remove a leaf and add to the sequence, then reverse the sequence.
// but we need links to parents, and how can we dynamically mark the node as leaf when both children are removed.


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

    // test weave function
    vector<int> v1_ = {1, 2};
    vector<int> v2_ = {3, 4};
    auto test = weave_two(v1_, 0, v2_, 0);
    print_vector2d(test);

    //
    printf("\n============== Test tree 1 ==============\n");
    vector<int> v {1, 2, 3};
    auto tree1 = minimal_tree(v);
    print_tree(&tree1);
    auto res1 = sequence_of_node(&tree1);
    printf("\ntotal sequences: %d\n", res1.size());
    print_vector2d(res1);

    printf("\n============== Test tree 2 ==============\n");
    vector<int> v2 {1,2,3,4,5,6,7};
    auto tree2 = minimal_tree(v2);
    print_tree(&tree2);
    auto res2 = sequence_of_node(&tree2);
    printf("\ntotal sequences: %d\n", res2.size());   // correct should be 80,   4 * Choose 3 from 6
    print_vector2d(res2);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
