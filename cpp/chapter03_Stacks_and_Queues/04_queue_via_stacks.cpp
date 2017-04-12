//
// Created by Honghao Li on 4/3/17.
//

// Problem
// Implement a MyQueue class which implements a queue using two stacks.



#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


////////////////////// Solution ////////////////////////
// 1st method
// let the 1st stack store the pushed items, 2nd stack store reversed order items for pop.
template <typename T>
class MyStack {

 public:

  MyStack() : first(nullptr) {}

  bool isEmpty() { return first == nullptr; }
  void push(T item) {
    Node *n = new Node(item);
    n->next = first;
    first = n;
    num++;
    //
    if (debug_mode)
      print();
  }

  T pop() {     // return and remove
    if (isEmpty()) throw runtime_error("Cannot pop from an empty stack!\n");
    Node *n = first;
    first = first->next;
    num--;
    //
    if (debug_mode)
      print();
    return n->item;
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
    Node *next = nullptr;
    T item;
  };

  Node *first;
  int num = 0;
  bool debug_mode = false;

};


template<typename T>
class MyQueue {
 public:

  void enqueue(T item) {
    stack.push(item);
    //
    if (debug_mode)
      print();
  }

  T dequeue() {
    if (stack_reverse.isEmpty())
      transfer();
    auto p =  stack_reverse.pop();
    //
    if (debug_mode)
      print();
    return p;
  }

 private:
  MyStack<T> stack;
  MyStack<T> stack_reverse;

  // transfer items from stack to stack_reverse
  void transfer() {
    while (!stack.isEmpty())
      stack_reverse.push(stack.pop());
  }

  bool debug_mode = true;
  // for debug
  void print() {
    printf("==============================\n") ;
    stack.print();
    stack_reverse.print();
    printf("==============================\n") ;
  }

};






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
    MyQueue<int> s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.enqueue(10);
    s.enqueue(9);
    s.enqueue(8);
    s.enqueue(7);
    s.enqueue(6);
    s.enqueue(7);
    s.enqueue(10);
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.enqueue(20);
    s.enqueue(21);
    s.enqueue(22);
    s.enqueue(23);
    s.enqueue(24);
    s.enqueue(25);
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    //
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

