//
// Created by Honghao Li on 3/29/17.
//

// PROBLEM
// Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
// EXAMPLE
// Input: the node c from the linked list a->b->c->d->e->f
// Result: nothing is returned, but the new linked list looks like a->b->d->e->f

// The problem statment is not very clear, they want you to only use the node, without knowing the head.
// this does not make sense to me. Because once you can access a linked list, of course you can access to its head, otherwise how can you manipulate this linked list???


// It's better to re-organize our linked list data structure to solve / test problems

#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>
#include "../lib/linked_list2.h"

using namespace std;


////////////////////// Solution ////////////////////////
// The 1st method
//
template <typename T>
void removeNodeFromLinkedList(Node<T> *n) {
  // we cannot know if the Node is the head or not, but we know the end/tail, and we can not delete the end node with this method.
  if (n == nullptr || n->next == nullptr)
    throw std::invalid_argument("Invalid Node to remove!\n");
  Node<T> *tmp = n->next;
  // directly do n = n->next will not work, you have to copy all the contents, not the pointer.
  n->item = n->next->item;
  n->next = n->next->next;
  delete tmp;
}

template <typename T>
void LinkedList<T>::removeKthNodeFromLinkedList(int k) {
  // find the kth node
  if (k < 1)
    throw std::runtime_error("Cannot remove the head!\n");
  Node<T> *n = head;
  while (k > 0 && n != nullptr) {
    n = n->next;
    k--;
  }
  if (k > 0)
    throw std::runtime_error("Not found the Node to remove!\n");
  //
  removeNodeFromLinkedList(n);
}

// 2nd method

// 3rd method





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
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0,}), 2, LinkedList<int>({0,1,3,0,4,5,0,0}));
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0,}), 1, LinkedList<int>({0,2,3,0,4,5,0,0}));
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0,}), 7, LinkedList<int>({0,1,2,3,0,4,5,0}));

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(LinkedList<int> llist, int k, LinkedList<int> expected) {

    ostringstream s;
    s << "\n========== test failed! ===========\n";
    s << "Linked list input: " << llist.toString() << endl;
    s << "expected answer: " << expected.toString() << endl;
    llist.removeKthNodeFromLinkedList(k);
    s << "your answer: " << llist.toString() << endl;
    s << "===================================\n";
    if ( llist.isEqual(expected) )
      return;
    cerr << s.str() << endl << flush;
    num_fail++;
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}