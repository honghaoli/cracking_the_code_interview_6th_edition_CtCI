//
// Created by Honghao Li on 4/22/17.
//

// Problem
// You are implementing a binary tree class from scratch witch, in addition to insert, find and delete, has a method getRandomNode() which returns a random node from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm for get RandomNode, and explain how you would implement the rest of the methods.




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
  int size = -1;
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



// Since we are asked to write the tree from scratch, we can implement size in the data structure.
int calculate_tree_size(Node<int> *n) {
  if (n == nullptr)
    return 0;
  int size = 1;   // current node counts 1
  if (n->left != nullptr) {
    if (n->left->size < 0)  // not calcualted
      size += calculate_tree_size(n->left);
    else
      size += n->left->size;
  }
  if (n->right != nullptr) {
    if (n->right->size < 0)  // not calcualted
      size += calculate_tree_size(n->right);
    else
      size += n->right->size;
  }
  n->size = size;
  return size;
}


// 1st method
// since DFS has a specific order, so every time generate a number in [0, tree.size), the use DFS find the i-th node.
// this solution is not the best, the similar but optimal version is the option #7 in the book.
Node<int> * get_node(int &id, Node<int> *node) {
  if (id < 0)     // the random id starts from 0.
    return node;
  else
    return nullptr;
}

Node<int> * move_node(int &id, Node<int> *tree) {
  Node<int> *result;
  if (tree != nullptr) {
    result = get_node(--id, tree);
    if (result != nullptr)
      return result;
    result = move_node(id, tree->left);
    if (result != nullptr)
      return result;
    result = move_node(id, tree->right);
    if (result != nullptr)
      return result;
  }
  return nullptr;
}

int random_id(int size) {
  return rand() % size;
}

Node<int> * get_ranndom(Node<int> *tree, int size) {
  // change this part for a better random sample
  int id = random_id(size);
  return move_node(id, tree);
}

// 2nd method
// option #7 in the book
// skips all unnecessary traversal
Node<int> * get_ith_node(int id, Node<int> *node) {   // here id also starts from 0.
  int leftsize = (node->left == nullptr) ? 0 : node->left->size;
  if (id < leftsize) {
    return get_ith_node(id, node->left);
  } else if ( id == leftsize) {
    return node;
  } else {
    return get_ith_node(id - leftsize - 1, node->right);
  }
}


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
    int id = 0;
    int idcopy = id;
    auto node = move_node(idcopy, &tree1);
    printf("The %d-th Node is (%d).\n", id, node->item);

    printf("\n============== Test tree 2 ==============\n");
    vector<int> v2 {1,2,3,4,5,6,7};
    auto tree2 = minimal_tree(v2);
    print_tree(&tree2);
    printf("tree size %d.\n", calculate_tree_size(&tree2));
    for (int i = 0; i < 7; ++i) {
      int idcopy = i;
      auto node = move_node(idcopy, &tree2);
      printf("The %d-th Node is (%d), with size %d.\n", i, node->item, node->size);
    }
    // test solution 2
    for (int i = 0; i < 7; ++i) {
      node = get_ith_node(i, &tree2);
      printf("#2 The %d-th Node is (%d).\n", i, node->item);
    }

    printf("\n============== Random Test Tree 2 ==============\n");
//    srand (time(NULL));
    for (int i = 0; i < 20; ++i) {
      auto node = get_ranndom(&tree2, calculate_tree_size(&tree2));
      printf("The %d-th random Node is (%d).\n", i, node->item);
    }
    printf("\n============== Test Tree 2 for solution 2 ==============\n");
    for (int i = 0; i < 20; ++i) {
      auto id = random_id(tree2.size);
      auto node = get_ith_node(id, &tree2);
      printf("#2 The %d-th Node is (%d).\n", id, node->item);
    }

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
