//
// Created by Honghao Li on 6/13/17.
//



/*
 * PROBLEM
 *  Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a number x (the number of values less than or equal to x). Implement the data structures and algorithms to support these operations. That is, implement the method track(int x), which is called when each number is generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal to x (not including x itself).
 *  EXAMPLE:
 *  Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3
 *  getRankOfNumber(1) = 0
 *  getRankOfNumber(3) = 1
 *  getRankOfNumber(4) = 3
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Book soluton:  Binary Search Tree
 */
/*
 * Implement binary search tree as Algorithm 3.3 (page 398) in the Algorithm book.
 * implement for integer for simplicity.
 * modification:
 *     since there may be duplicate integers, we need to add the size of node when node has duplicate input.
 *     here value = number of duplicate keys. So rank = original rank + value - 1.
 */

struct Node {
  Node() = default;
  Node(int key, int value, int N) : key(key), value(value), N(N) {};
  int key;
  int value;
  Node *left = nullptr, *right = nullptr;
  int N;    // size of node
};

// print the tree from top to bottom, in command line, it shows from left to right.
void print_tree(Node *p, int indent = 0) {
  if(p != nullptr) {
    if(p->left) print_tree(p->left, indent + 4);
    if (indent) {
      cout << setw(indent) << ' ';
    }
    cout<< p->key << "(" << p->value << "," << p->N << ")" << "\n ";
    if(p->right) print_tree(p->right, indent + 4);
  }
  cout << endl;
}


class BST {

 public:

  int size() { return size(root); }

  int rank(int key) { return rank(key, root); }

  void put(int key) { root = put(root, key); }

  void print() { print_tree(root); }

 private:

  int size(Node *n) {
    if (n == nullptr)
      return 0;
    else
      return n->N;
  }

  // return number of keys less than key, in the subtree rotted at n.
  int rank(int key, Node *n) {
    if (n == nullptr)
      return 0;
    if (key == n->key) {
      return size(n->left) + n->value - 1;
    } else if (key < n->key) {
      return rank(key, n->left);
    } else {
      return size(n->left) + n->value + rank(key, n->right);
    }
  }

  // increase the value of key's node by one if key in subtree rotted at n.
  // otherwise, add new node to subtree with key.
  Node* put(Node *n, int key) {
    if (n == nullptr)
      return new Node(key, 1, 1);
    if (key == n->key) {
      n->value++;
      n->N++;
    } else if (key < n->key) {
      n->left = put(n->left, key);
    } else {
      n->right = put(n->right, key);
    }
    n->N = size(n->left) + size(n->right) + n->value;
    return n;
  }

  Node *root = nullptr;
};

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

  void test() {
    BST bst;
    vector<int> arr {5, 1, 4, 4, 5, 9, 7, 13, 3};
    for (auto &a : arr) {
      bst.put(a);
    }
    bst.print();
    for (auto &a : arr) {
      printf("rank of %d = %d\n", a, bst.rank(a));
    }
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test();

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

