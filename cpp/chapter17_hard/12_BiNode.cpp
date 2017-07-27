//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 *
 * Consider a simple data structure called BiNode, which has pointers to two other nodes.
 *
 * public class BiNode {
 *    public BiNode node1, node2;
 *    public int data;
 * }
 *
 * The data structure BiNode could be used to represent both a binary tree (where node1 is the left node and node2 is the right node) or a doubly linked list (where node1 is the previous node and node2 is the next node). Implement a method to convert a binary search tree (implemented with BiNode) into a doubly linked list. The values should be kept in order and the operation should be performed in place (that is, on the original data structure).
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "../lib/helper.h"


using namespace std;


struct BiNode {
  BiNode() = default;
  BiNode(int value) : data(value) {}
  BiNode *node1 = nullptr, *node2 = nullptr;
  int data = 0;
};

// print the tree from top to bottom, in command line, it shows from left to right.
void print_tree(BiNode *p, int indent = 0) {
  if (p != nullptr) {
    if (p->node1) print_tree(p->node1, indent + 4);
    if (indent) {
      cout << setw(indent) << ' ';
    }
    cout << p->data << "\n ";
    if (p->node2) print_tree(p->node2, indent + 4);
  }
}


BiNode* insert_node(BiNode *node, int value) {
  if (node == nullptr) {
    return new BiNode(value);
  }
  if (value < node->data) {
    node->node1 = insert_node(node->node1, value);
  } else if (value > node->data) {
    node->node2 = insert_node(node->node2, value);
  } else {
    cout << "duplicate values in binary search tree! " << value << endl;
  }
  return node;
}

// create a BiNode from a vector
BiNode create_binode(vector<int> &vec) {
  BiNode node;
  if (vec.size() < 1)
    return node;

  node = BiNode(vec.at(0));
  for (int i = 1; i < vec.size(); ++i) {
    insert_node(&node, vec[i]);
  }

  print_tree(&node);
}


// 1st method
/*
 * DFS in order traversal, add node in this sequence.
 * This works, but the code is ugly.
 */
BiNode* add_node(BiNode *node, BiNode *last) {
  if (node != nullptr) {
    node->node1 = last;
    if (last != nullptr) {
      last->node2 = node;
    }
    last = node;
  }
  return last;
}

// traversal order.
BiNode* in_order_traversal(BiNode *node, BiNode *last) {
  if (node != nullptr) {
    last = in_order_traversal(node->node1, last);
    last = add_node(node, last);
    last = in_order_traversal(node->node2, last);
  }
  return last;
}

void convert_tree_to_linked_list(BiNode *node) {
  auto last = in_order_traversal(node, nullptr);
  while (last != nullptr) {
    cout << last->data << " <-- ";
    last = last->node1;
  }
}



// 2nd method
/*
 * The book solution, from top to bottom, recursively merge into a list
 */

void merge_list(BiNode *left_tail, BiNode *node, BiNode *right_head) {
  if (node != nullptr) {
    node->node1 = left_tail;
    node->node2 = right_head;
    if (left_tail != nullptr)
      left_tail->node2 = node;
    if (right_head != nullptr)
      right_head->node1 = node;
  }
}

pair<BiNode*, BiNode*> convert(BiNode *node) {
  BiNode *left_head = nullptr;
  BiNode *right_tail = nullptr;
  if (node == nullptr)
    return make_pair(left_head, right_tail);

  auto left = convert(node->node1);
  auto right = convert(node->node2);
  left_head = left.first;
  auto left_tail = left.second;
  auto right_head = right.first;
  right_tail = right.second;
  merge_list(left_tail, node, right_head);

  // this is important to avoid each node becomes  ( nullptr <- node -> nullptr )
  if (left_tail == nullptr)
    left_head = node;
  if (right_head == nullptr)
    right_tail = node;

  return make_pair(left_head, right_tail);  // front
}

void print_list(BiNode *node) {
  while (node != nullptr) {
    cout << node->data << " --> ";
    node = node->node2;
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

  void test_tree() {
    vector<int> vec {5,2,1,6,7,3,8,4,9,0};
    cout << "\nTest tree" << endl;
    auto node = create_binode(vec);

    // 1st method
//    convert_tree_to_linked_list(&node);

    // 2nd method
    auto list = convert(&node);
    print_list(list.first);
  }

  void unit_test() {
    test_tree();
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    unit_test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

