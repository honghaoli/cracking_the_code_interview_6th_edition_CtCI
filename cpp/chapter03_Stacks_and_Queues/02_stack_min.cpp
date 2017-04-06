//
// Created by Honghao Li on 4/3/17.
//

// Problem
// How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? push, pop and min should all operate in O(1) time.



#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;





////////////////////// Solution ////////////////////////
// 1st method
// create another field in the node to store the current min when this node is at top.
//template <typename T>
//class MyStack {
//
// public:
//
//  MyStack() : first(nullptr) {}
//
//  bool isEmpty() { return first == nullptr; }
//  void push(T item) {
//    Node *n = new Node(item);
//    if (isEmpty())
//      n->min_value = item;
//    else
//      n->min_value = item < first->min_value ? item : first->min_value;
//    n->next = first;
//    first = n;
//    //
//    if (debug_mode)
//      print();
//  }
//
//  T pop() {     // return and remove
//    if (isEmpty()) throw runtime_error("Cannot pop from an empty stack!\n");
//    Node *n = first;
//    first = first->next;
//    //
//    if (debug_mode)
//      print();
//    return n->item;
//  }
//
//  T peek() {    // only return, no remove
//    if (isEmpty()) throw runtime_error("Cannot pop from an empty stack!\n");
//    return first->item;
//  }
//
//  T min() {
//    if (isEmpty()) throw runtime_error("No min value for an empty stack!\n");
//    return first->min_value;
//  }
//
//  string toString() {
//    ostringstream s;
//    Node *n = first;
//    int N = 0;
//    while (n != nullptr) {
//      s << n->item << " <- ";
//      n = n->next;
//      N++;
//    }
//    s << "nullptr" << " (total: " << N << " nodes)";
//    if (!isEmpty())
//      s << ", (with min = " << min() << " )";
//    return s.str();
//  }
//
//  void print() {
//    cout << toString() << endl << flush;
//  }
//
// private:
//
//  struct Node {
//    Node() = default;
//    Node(T item) : item(item) {}
//    Node *next = nullptr;
//    T item;
//    T min_value;
//  };
//
//  Node *first;
//  bool debug_mode = true;
//
//};

// 2nd method
// create another linked list in the stack to store the min value for each state.
// One can be confused at first why this method is more efficient, maybe it looks like we still need to store another N nodes.
// However, with careful implementation as in the textbook, this is surely more efficient.
// KEY POINT HERE
// we push new min the min list even when new min = old min, and pop out min when current min = pop out node's min.

template <typename T>
class MyStack {

 public:

  MyStack() : first(nullptr) {}

  bool isEmpty() { return first == nullptr; }
  void push(T item) {
    Node *n = new Node(item);
    n->next = first;
    first = n;
    //
    if (debug_mode)
      print();
  }

  T pop() {     // return and remove
    if (isEmpty()) throw runtime_error("Cannot pop from an empty stack!\n");
    Node *n = first;
    first = first->next;
    //
    if (debug_mode)
      print();
    return n->item;
  }

  T peek() {    // only return, no remove
    if (isEmpty()) throw runtime_error("Cannot pop from an empty stack!\n");
    return first->item;
  }

  virtual string toString() {
    ostringstream s;
    Node *n = first;
    int N = 0;
    while (n != nullptr) {
      s << n->item << " <- ";
      n = n->next;
      N++;
    }
    s << "nullptr" << " (total: " << N << " nodes)";
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
  Node *min_value;

  bool debug_mode = false;

};


// TODO: make this extend class better later.
template <typename T>
class MyStackWithMin : MyStack<T> {

 public:


  void push(T item) {
    if (smin.isEmpty())
      smin.push(item);
    else if (item <= min())
      smin.push(item);
    MyStack<T>::push(item);
    //
    if (debug_mode)
      MyStack<T>::print();
  }

  T pop() {
    T t = MyStack<T>::pop();
    if (t == min())
      smin.pop();
    //
    if (debug_mode)
      MyStack<T>::print();
  }

  T min() {
    if (smin.isEmpty()) throw runtime_error("No min value for an empty stack!\n");
    return smin.peek();
  }

  string toString() override {
    ostringstream s;
    s << MyStack<T>::toString();
    if (!smin.isEmpty())
      s << ", (with min = " << min() << " )";
    return s.str();
  }

 private:
  MyStack<T> smin;
  bool debug_mode = true;


};


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
    MyStackWithMin<int> s;
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
//    l = createLinkedList({1,2,3,4,5});
//    linkTheTailToKthNode(&l, 0);
//    unitTest(&l, getKthNode(&l, 0));


    //
//    if (num_fail == 0) {
//      printf("Test passed!\n");
//    } else {
//      printf("\nTotal fail cases: %d\n", num_fail);
//    }
  }

//  void unitTest(Node *head, Node *expected) {
//    ostringstream s;
//    s << "\n========== test failed! ===========\n";
//    s << "Linked list input 1: " << toString(head) << endl;
//    if (expected)
//      s << "expected answer: " << expected->item << endl;
//    else
//      s << "expected answer: nullptr " << endl;
//    if (result)
//      s << "your answer: " << result->item << endl;
//    else
//      s << "your answer: nullptr " << endl;
//    s << "===================================\n";
//    if (result != expected){
//      cerr << s.str() << endl << flush;
//      num_fail++;
//    }
//  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
