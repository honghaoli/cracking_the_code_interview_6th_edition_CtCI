//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.





#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>


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
// To make the problem simpler, we assume each node has a link to its parent node.
// then we start from the given nodes to the root, reverse the path, the last common node is what we want.
// If each node has no link to parent, we would do a DFS to find the path way from root to given nodes.
Node<int>* find_ancestor(Node<int> *n1, Node<int> *n2) {
  vector<Node<int> *> parents1;
  vector<Node<int> *> parents2;
  while (n1 != nullptr) {
    parents1.push_back(n1);
    n1 = n1->parent;
  }
  while (n2 != nullptr) {
    parents2.push_back(n2);
    n2 = n2->parent;
  }

  Node<int> *ancestor = nullptr;
  vector<Node<int> *>::size_type s1 = parents1.size();
  vector<Node<int> *>::size_type s2 = parents2.size();
  while (s1-- > 0 && s2-- > 0) {
    if (parents1[s1]->item == parents2[s2]->item)
      ancestor = parents1[s1];
    else    // passed the last common ancestor
      break;
  }

  return ancestor;
}


// test
void test(Node<int> *n1, Node<int> *n2) {
  if (n1 == nullptr || n2 == nullptr) return;
  printf("Node (%d) and Node (%d) 's common ancestor is ", n1->item, n2->item);
  auto anc = find_ancestor(n1, n2);
  if (anc != nullptr)
    printf("Node (%d).\n", anc->item);
  else
    printf("nullptr.\n");
}

void test_all(Node<int> *n, Node<int> *root) {
  if (root->left != nullptr)
    test_all(n, root->left);
  if (n->item <= root->item)  // do only half
    test(n, root);
  if (root->right != nullptr)
    test_all(n, root->right);
}

void unit_test(Node<int> *n, Node<int> *root) {
  if (n->left != nullptr)
    unit_test(n->left, root);
  test_all(n, root);
  if (n->right != nullptr)
    unit_test(n->right, root);
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

    unit_test(&res, &res);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

