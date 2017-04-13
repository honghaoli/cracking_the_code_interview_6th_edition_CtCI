//
// Created by Honghao Li on 4/5/17.
//

// Problem
// Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
// Note: we are only allowed to sort the stack out of the class definition, so only push, pop ,etc methods are allowed.



#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template<typename T>
class MyStack {


 public:

  bool isEmpty() {
    return first == nullptr;
  }

  void push(T item) {
    Node *old = first;
    first = new Node(item);
    first->next = old;
    num++;
    //
    if (debug_mode)
      print();
  }

  T pop() {
    if (isEmpty())
      throw out_of_range("The stack is empty.\n");
    Node *p = first;
    first = p->next;
    num--;
    //
    if (debug_mode)
      print();
    return p->item;
  }

  T peek() {    // only return, no remove
    if (isEmpty()) throw runtime_error("Cannot pop from an empty stack!\n");
    return first->item;
  }

  inline int size() { return num; }

  string toString() {
    ostringstream s;
    Node *n = first;
    while (n != nullptr) {
      s << n->item << " <- ";
      n = n->next;
    }
    s << "nullptr" << " (total: " << num << " nodes)";
    return s.str();
  }

  void print() {
    cout << toString() << endl << flush;
  }

 private:
  struct Node {
    Node() = default;
    Node(T item) : item(item) {}
    T item;
    Node *next = nullptr;
  };

  Node *first = nullptr;
  int num = 0;
  bool debug_mode = false;
};


// 1st method
// According
// Mergesort and Quicksort needs more stacks, every recursion creates two extra stacks.
// so use the naive O(N^2) method as shown in the textbook.
template<typename T>
void sort_stack(MyStack<T> *s) {
  MyStack<T> tmps;

  // move items into tmps with reversed order.
  while (!s->isEmpty()) {
    // next item in s
    T p = s->pop();
    // find the correct position to insert in tmps, move all larger items back to s
    while (!tmps.isEmpty() && tmps.peek() > p) {
      s->push(tmps.pop());
    }
    // insert to the correct position
    tmps.push(p);
  }

  // move back to s with required order
  while (!tmps.isEmpty()) {
    s->push(tmps.pop());
  }

}




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
    MyStack<int> s;
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(10);
    s.push(22);
    s.push(23);
    s.push(24);
    s.push(9);
    s.push(8);
    s.push(1);
    s.push(6);
    s.push(7);
    s.push(11);
    s.push(20);
    s.push(21);
    s.push(25);
    //
    s.print();
    sort_stack(&s);
    s.print();
    //
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

