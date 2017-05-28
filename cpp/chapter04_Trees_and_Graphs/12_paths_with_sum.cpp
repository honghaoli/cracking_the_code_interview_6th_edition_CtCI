//
// Created by Honghao Li on 4/22/17.
//

// Problem
// You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to given value. Tha path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).





#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>

#include "../lib/helper.h"

using namespace std;


template <typename T>
struct Node {
  T item;
  Node *left = nullptr;
  Node *right = nullptr;
  vector<T> sums;     // only for this problem.
  bool calculated = false;
  int count = -1;
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



int calculate_tree_size(Node<int> *n) {
  if (n == nullptr)
    return 0;
  int size = 1;   // current node counts 1
  if (n->left != nullptr)
    size += calculate_tree_size(n->left);
  if (n->right != nullptr)
    size += calculate_tree_size(n->right);
  return size;
}


//////////////////////// Solutions ///////////////////////////////

// 1st method
// recursively calculate all possible sums for each node.
void find_sums(Node<int> *n) {
  // only consider this node
  n->sums.push_back(n->item);
  // has children
  if (n->left != nullptr) {
    // if not calculated
    if (!n->left->calculated)
      find_sums(n->left);
    for (auto &s : n->left->sums) {
      n->sums.push_back(s + n->item);
    }
  }
  if (n->right != nullptr) {
    // if not calculated
    if (!n->right->calculated)
      find_sums(n->right);
    for (auto &s : n->right->sums) {
      n->sums.push_back(s + n->item);
    }
  }
  n->calculated = true;
  // for test
  printf("Node (%d) has sums:\n", n->item);
  print_vector(n->sums);
}

// count sums for only this node
int count_node(Node<int> *n, int target) {
  if (n == nullptr)
    return 0;
  int count = 0;
  for (auto &s : n->sums) {
    if (s == target)
      count++;
  }
  return count;
}

// count sums for this node and all its children
int count_sums(Node<int> *root, int target) {
  int sum = 0;
  if (root != nullptr) {
    sum += count_node(root, target);
    sum += count_sums(root->left, target);
    sum += count_sums(root->right, target);
  }
  return sum;
}


// 2nd method
// We can optimize above method, actually we don't need to recount, we can do it on-the-fly, with an implementation of count in each node.
// improve the find_sums() above, we have:
int count_sums2(Node<int> *n, int target) {
  // clear data in the 1st method
  n->sums.clear();
  n->count = 0;
  // only consider this node
  n->sums.push_back(n->item);
  if (n->item == target)
    n->count++;
  // has children
  if (n->left != nullptr) {
    // if not calculated
    if (n->left->count < 0)
      n->count += count_sums2(n->left, target);
    else
      n->count += n->left->count;
    for (auto &s : n->left->sums) {
      n->sums.push_back(s + n->item);
      if (s + n->item == target)
        n->count++;
    }
  }
  if (n->right != nullptr) {
    // if not calculated
    if (n->right->count < 0)
      n->count += count_sums2(n->right, target);
    else
      n->count += n->right->count;
    for (auto &s : n->right->sums) {
      n->sums.push_back(s + n->item);
      if (s + n->item == target)
        n->count++;
    }
  }
  // for test
//  printf("Node (%d) has %d target value(s), with sums:\n", n->item, n->count);
//  print_vector(n->sums);
  return n->count;
}



// Generally, the above methods are not the best, it takes ~ O(n*k), where n is number of nodes, k is the average sums length for each node.
// 3rd method
// use hash map store the running sum, from root to current node.
// use running sum - target sum = start point to find the start node, and count how many start nodes, store it as the path count to this node.
// this could be ~ O(n)
void change_hashmap(unordered_map<int, int> &hashmap, int key, int delta) {
  // NOTE: hashmap.count(key) only return 1 or 0;
  int newcount = ( hashmap.count(key) ?  hashmap[key] : 0 ) + delta;
  if (newcount == 0)  // no need for the key
    hashmap.erase(key);
  else
    hashmap[key] = newcount;
}

int path_count_for_node(Node<int> *node, int target, int running_sum, unordered_map<int, int> &hashmap) {
  if (node == nullptr)  // trivial case
    return 0;
  //
  int path_count = 0;
  running_sum += node->item;
  int s = running_sum - target;
  // count previous start point
  int tmp = hashmap[s];
  if (hashmap.count(s) > 0) {
    path_count += hashmap[s];
  }
  // count if this node is a correct end.
  if (running_sum == target)
    path_count++;
  // recursively find the children
  change_hashmap(hashmap, running_sum, 1);   // store running sum into the hashmap
  path_count += path_count_for_node(node->left, target, running_sum, hashmap);
  path_count += path_count_for_node(node->right, target, running_sum, hashmap);
  change_hashmap(hashmap, running_sum, -1);   // VERY IMPORTANT! remove this running sum for this node when this node is finished. e.g., when jump from this node to its parent's another child.

//  printf("Node (%d) has %d target value(s), running sum: %d, with previous start points %d:\n", node->item, path_count, running_sum, tmp);
  return path_count;
}

int count_sums3(Node<int> *root, int target) {
  unordered_map<int, int> hashmap;
  return path_count_for_node(root, target, 0, hashmap);
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
    find_sums(&tree1);
    for (int i = 0; i < 6; ++i) {
      printf("Tree has %d path(s) of value %d.\n", count_sums(&tree1, i), i);
    }

    printf("\n============== Test tree 2 ==============\n");
    vector<int> v2 {1,2,3,4,5,6,7};
    auto tree2 = minimal_tree(v2);
    print_tree(&tree2);
    printf("tree size %d.\n", calculate_tree_size(&tree2));
    find_sums(&tree2);
    for (int i = 0; i < 18; ++i) {
      printf("Tree has %d path(s) of value %d.\n", count_sums(&tree2, i), i);
    }

    printf("\n============== Test tree 3 ==============\n");
    vector<int> v3 {-3,-2,-1,0,1,2,3};
    auto tree3 = minimal_tree(v3);
    print_tree(&tree3);
    printf("tree size %d.\n", calculate_tree_size(&tree3));
    find_sums(&tree3);
    for (int i = -6; i <= 6; ++i) {
      printf("Tree has %d path(s) of value %d.\n", count_sums(&tree3, i), i);
    }

    printf("\n============== Test tree 4 ==============\n");
    Node<int> tree4 = Node<int>();
    Node<int> n1 = Node<int>();
    Node<int> n2 = Node<int>();
    Node<int> n3 = Node<int>();
    Node<int> n4 = Node<int>();
    Node<int> n5 = Node<int>();
    tree4.item = 0;
    n1.item = 1;
    n2.item = -1;
    n3.item = 1;
    n4.item = -1;
    n5.item = 1;
    tree4.left = &n1;
    n1.left = &n2;
    n2.left = &n3;
    n3.left = &n4;
    n4.left = &n5;

    print_tree(&tree4);
    printf("tree size %d.\n", calculate_tree_size(&tree4));
    find_sums(&tree4);
    for (int i = -3; i <= 3; ++i) {
      printf("Tree has %d path(s) of value %d.\n", count_sums(&tree4, i), i);
    }

    ///////////////////////////////////////////////////////////////
    // for method 2, need to clear the tree data structure every time.
    printf("\n============== Test the 2nd method ==============\n");
    printf("\n============== Test tree 1 ==============\n");
    for (int i = 0; i < 6; ++i) {
      vector<int> v {1, 2, 3};
      auto tree1 = minimal_tree(v);
      if (i == 0) {
        print_tree(&tree1);
        printf("tree size %d.\n", calculate_tree_size(&tree1));
      }
      printf("#2 Tree has %d path(s) of value %d.\n", count_sums2(&tree1, i), i);
    }

    printf("\n============== Test tree 3 ==============\n");
    for (int i = -6; i <= 6; ++i) {
      vector<int> v3 {-3,-2,-1,0,1,2,3};
      auto tree3 = minimal_tree(v3);
      if (i == -6) {
        print_tree(&tree3);
        printf("tree size %d.\n", calculate_tree_size(&tree3));
      }
      printf("#2 Tree has %d path(s) of value %d.\n", count_sums2(&tree3, i), i);
    }

    printf("\n============== Test tree 4 ==============\n");
    for (int i = -3; i <= 3; ++i) {
      Node<int> tree4 = Node<int>();
      Node<int> n1 = Node<int>();
      Node<int> n2 = Node<int>();
      Node<int> n3 = Node<int>();
      Node<int> n4 = Node<int>();
      Node<int> n5 = Node<int>();
      tree4.item = 0;
      n1.item = 1;
      n2.item = -1;
      n3.item = 1;
      n4.item = -1;
      n5.item = 1;
      tree4.left = &n1;
      n1.left = &n2;
      n2.left = &n3;
      n3.left = &n4;
      n4.left = &n5;

      if (i == -3) {
        print_tree(&tree4);
        printf("tree size %d.\n", calculate_tree_size(&tree4));
      }
      printf("#2 Tree has %d path(s) of value %d.\n", count_sums2(&tree4, i), i);
    }

    ///////////////////////////////////////////////////////////////
    printf("\n============== Test the 3rd method ==============\n");
    printf("\n============== Test tree 1 ==============\n");
    print_tree(&tree1);
    for (int i = 0; i < 7; ++i) {
      printf("#3 Tree has %d path(s) of value %d.\n", count_sums3(&tree1, i), i);
    }

    printf("\n============== Test tree 2 ==============\n");
    print_tree(&tree2);
    for (int i = 0; i < 18; ++i) {
      printf("#3 Tree has %d path(s) of value %d.\n", count_sums3(&tree2, i), i);
    }

    printf("\n============== Test tree 3 ==============\n");
    print_tree(&tree3);
    for (int i = -6; i <= 6; ++i) {
      printf("#3 Tree has %d path(s) of value %d.\n", count_sums3(&tree3, i), i);
    }

    printf("\n============== Test tree 4 ==============\n");
    print_tree(&tree4);
    for (int i = -3; i <= 3; ++i) {
      printf("#3 Tree has %d path(s) of value %d.\n", count_sums3(&tree4, i), i);
    }




  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
