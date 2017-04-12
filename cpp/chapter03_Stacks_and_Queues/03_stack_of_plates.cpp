//
// Created by Honghao Li on 4/3/17.
//

// Problem
// Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and pop() should behave identically to a single stack.
// FOLLOW UP
// Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.



#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


////////////////////// Solution ////////////////////////
// 1st method
// For the follow up question, we would accept the stack not full. then it would be easier.
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


//
template<typename T>
class SetOfStacks {

 public:
  SetOfStacks() = default;

  void push(T item) {
    if (stacks[currentStack].size() >= capacity) {
      auto s = MyStack<T>();
      s.push(item);
      stacks.push_back(s);
      currentStack++;
    } else {
      stacks[currentStack].push(item);
    }
    //
    if (debug_mode)
      print();
  }

  T pop() {
    while (stacks[currentStack].isEmpty()) {
      stacks.pop_back();
      currentStack--;
    }
    if (currentStack < 0)
      throw out_of_range("Cannot pop from an empty stack!\n");
    auto p = stacks[currentStack].pop();
    //
    if (debug_mode)
      print();
    return p;
  }

  T popAt(int index) {
    if (index > currentStack)
      throw out_of_range("Cannot pop from sub stack at index!\n");
    auto p = stacks[index].pop();
    //
    if (debug_mode)
      print();
    return p;
  }

  void print() {
    printf("========================\n");
    for (int i = 0; i <= currentStack; i++) {
      printf("stack: %d\n", i);
      stacks[i].print();
    }
    printf("========================\n");
  }

 private:
  vector<MyStack<T>> stacks {MyStack<T>()};
  int currentStack = 0;
  int capacity = 2;
  bool debug_mode = true;
};

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
    SetOfStacks<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    s.pop();
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(7);
    s.push(10);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(20);
    s.push(21);
    s.push(22);
    s.push(23);
    s.push(24);
    s.push(25);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    //
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.popAt(0);
    s.popAt(1);
    s.popAt(2);
    s.popAt(3);
    s.popAt(1);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(99);
    s.pop();
    s.pop();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
