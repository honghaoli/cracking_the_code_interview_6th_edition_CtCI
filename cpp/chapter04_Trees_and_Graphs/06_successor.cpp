//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.



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
  Node *parent = nullptr;

  void add_left(Node *l) {
    this->left = l;
    l->parent = this;
  }

  void add_right(Node *r) {
    this->right = r;
    r->parent = this;
  }
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

////////// use modified method to create a binary search tree /////////////////////
void add_to_node(Node<int> *n, vector<int> &v, int lo, int hi) {
  int mid = (hi - lo) / 2 + lo;
  n->item = v[mid];
  if (mid > lo) {
    n->add_left(new Node<int>());
    add_to_node(n->left, v, lo, mid - 1);
  }
  if (mid < hi) {
    n->add_right(new Node<int>());
    add_to_node(n->right, v, mid + 1, hi);
  }
}

Node<int> minimal_tree(vector<int> &v) {
  Node<int> result;
  add_to_node(&result, v, 0, v.size() - 1);
  return result;
}



// 1st method
// the next node could be at
// 1: the right subtree of this node, so go to the right child, and then recursively go left until reach the end.
// 2: recursively go upstream until reach the root.
// NOTE: there may be duplicate node, so we choose the node >= this node.
Node<int> *next(Node<int> *node) {
  Node<int> *nex = nullptr;
  Node<int> *search = nullptr;
  // right subtree
  if (node->right != nullptr) {
    search = node->right;
    while (search->left != nullptr) {
      search = search->left;
    }
    nex = search;
  }
  // upstream search parents
  if (node->parent != nullptr) {
    search = node;
    while (search->parent != nullptr) {
      search = search->parent;
      if (search->item >= node->item && (nex == nullptr || search->item < nex->item) ) {  // new smallest in all the nodes which are >= this node
        nex = search;
      }
    }
  }

  return nex;
}

void test(Node<int> *node) {
  auto nex = next(node);
  if (nex != nullptr)
    printf("Node (%d)'s next is node (%d).\n", node->item, nex->item);
  else
    printf("Node (%d) is the last node! no next node exists.\n", node->item);
}

void unit_test(Node<int> *n) {
  if (n->left != nullptr)
    unit_test(n->left);
  test(n);
  if (n->right != nullptr)
    unit_test(n->right);
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


    // 1st tree test
    vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    auto res = minimal_tree(v);
    print_tree(&res);
    cout << endl;

    unit_test(&res);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

