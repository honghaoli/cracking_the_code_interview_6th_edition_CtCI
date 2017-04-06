//
// Created by Honghao Li on 4/3/17.
//

// Problem
// Describe how you could use a single array to implement three stacks



#include <cstdio>
#include <iostream>
#include <sstream>
#include <array>

using namespace std;


////////////////////// Solution ////////////////////////
// 1st method
// In the array, each of [3k, 3k+1, 3k+2] is element in three stacks. The size of array can increase if there are too many items.

template <typename T>
class MyMultiStack {

 public:

  MyMultiStack() {
    initialize();
  }
  MyMultiStack(int num_stacks, int stack_size) : num_stacks(num_stacks), stack_size(stack_size) {
    MyMultiStack();
  }
  ~MyMultiStack() {
    deallocate();
  }

  bool isEmpty(int n_stack) {
    if (n_stack >= num_stacks)
      throw out_of_range("stack number is out of range!\n");
    return current_indices[n_stack] < 0;
  }

  void push(int n_stack, T item) {
    if (current_indices[n_stack] == stack_size * num_stacks - 1) // full
      increase_size();
    current_indices[n_stack] += num_stacks;
    arr[current_indices[n_stack]] = item;
    //
    if (debug_mode)
      print();
  }

  T pop(int n_stack) {     // return and remove
    if (isEmpty(n_stack)) throw runtime_error("Cannot pop from an empty stack!\n");
    T item = arr[current_indices[n_stack]];
    current_indices[n_stack] -= num_stacks;
    //
    if (debug_mode)
      print();
    return item;
  }

  T peek() {    // only return, no remove
  }

  virtual string toString(int n_stack) {
    ostringstream s;
    int n = current_indices[n_stack];
    int N = 0;
    while (n >= 0) {
      T item = arr[n];
      s << item << " -> " ;
      n -= num_stacks;
      N++;
    }
    s << "nullptr" << " (total: " << N << " items)";
    return s.str();
  }

  void print() {
    for (int i = 0; i < num_stacks; i++) {
      cout << "Stack " << i << " : " << toString(i) << endl;
    }
    cout << endl << flush;
  }

 private:

  int stack_size = 10;
  int num_stacks = 3;
  T *arr;
  int *current_indices;

  bool debug_mode = true;

  void initialize() {
    allocate();
    initialize_indices();
  }

  void allocate() {
    arr = new T[stack_size * num_stacks];
    current_indices = new int[num_stacks];
  }

  void deallocate() {
    delete [] arr;
    delete [] current_indices;
  }

  void initialize_indices() {
    for (int i = 0; i < num_stacks; i++) {
      current_indices[i] = i - num_stacks;
    }
  }

  void increase_size() {
    // this can be standard array resize implementation, skip here.
    //    stack_size *= 2;
    throw out_of_range("stack is full!\n");
  }

  void decrease_size() {};

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
    MyMultiStack<int> s;
    s.push(0, 1);
    s.push(0, 2);
    s.push(0, 3);
    s.pop(0);
    s.pop(0);
    s.pop(0);
    s.push(0, 10);
    s.push(1, 9);
    s.push(2, 8);
    s.push(0, 7);
    s.push(1, 6);
    s.push(2, 7);
    s.push(0, 10);
    s.pop(2);
    s.pop(1);
    s.pop(0);
    s.pop(0);
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


