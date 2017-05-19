//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Given a binary tree, design an algorithm witch creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked list).




#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>

#include "../lib/linked_list.h"

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
// choose the middle element as the root, left part for left child, right part for right child, recursively.
void add_node_to_list(Node<int> *node, vector<LinkedList<int>> &lists, int level) {
  if (node == nullptr)
    return;
  if (lists.size() <= level) {
    LinkedList<int> new_list;
    lists.push_back(new_list);
  }
  lists.at(level).appendToHead(node->item);
  //
  add_node_to_list(node->left, lists, level + 1);
  add_node_to_list(node->right, lists, level + 1);
}


vector<LinkedList<int>> create_lists(Node<int> *root) {
  vector<LinkedList<int>> lists;
  add_node_to_list(root, lists, 0);
  return lists;
}

// 2nd method
// As the text book claimed, the 1st method is DFS, the 2nd method can be BFS.
// notice this method create different order in the linked lists.
vector<LinkedList<Node<int> *>> create_lists_bfs(Node<int> *root) {
  vector<LinkedList<Node<int> *>> lists;
  LinkedList<Node<int> *> current_list;
  // add the root
  if (root != nullptr) {
    current_list.appendToHead(root);
  }
  // add children level by level
  while (!current_list.isEmpty()) {   // if current level has nodes, find all the children
    lists.push_back(current_list);
    LinkedList<Node<int> *> parent_list = current_list;
    current_list = LinkedList<Node<int> *>();   // create new empty linked list
    //linked list should have iterator implementation
    for (auto &l: parent_list) {
      if (l->left != nullptr)
        current_list.appendToHead(l->left);
      if (l->right != nullptr)
        current_list.appendToHead(l->right);
    }
  }

  return lists;
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

    vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    auto res = minimal_tree(v);
    print_tree(&res);

    // test 1st method
    auto lists = create_lists(&res);
    cout << endl;
    for (auto &l : lists) {
      l.print();
    }

    // test 2nd method
    auto lists2 = create_lists_bfs(&res);
    printf("\nMethod 2\n");
    for (auto &l : lists2) {
      for (auto &elem : l) {
        cout << elem->item << " -> ";
      }
      cout << "nullptr " << endl;
    }

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
