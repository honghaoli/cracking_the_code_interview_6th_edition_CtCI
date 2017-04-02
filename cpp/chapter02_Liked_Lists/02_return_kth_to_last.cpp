//
// Created by Honghao Li on 3/29/17.
//

// PROBLEM:
// Implement an algorithm to find the kth to last element of a singly linked list.


#include <cstdio>
#include <unordered_map>
#include "linked_list.h"



////////////////////// Solution ////////////////////////
// The 1st method
// use hash map to store all the items, maybe we can use another data structure rather than <key, value> pair.
template <typename T>
std::string LinkedList<T>::findKthToLastToString(int k) {
  if (k > N - 1 || k < 0)
    return "nullptr";
//    return nullptr;
  Node *n1 = head;
  Node *n2 = head;
  for (int i = 0; i < k; ++i) {
    // if we do not know the size N, we could remove the first if (N<k) and add here:
    // if (n2 == nullptr) return "nullptr";
    n2 = n2->next;
  }
  while (n2->next != nullptr) {
    n1 = n1->next;
    n2 = n2->next;
  }
//  return n1;
  std::ostringstream s;
  s << n1->item;
  return s.str();
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
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0}), 2, "5");
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0}), 8, "0");
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0}), 9, "nullptr");
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,7}), 0, "7");
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,7}), -1, "nullptr");

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(LinkedList<int> llist, int k, std::string expected) {

    using namespace std;
    ostringstream s;
    std::string n = llist.findKthToLastToString(k);
    if ( n == expected)
      return;
    s << "\n========== test failed! ===========\n";
    s << "Linked list input: " << llist.toString() << endl;
    s << "Find the " << k << "-th to the last element" << endl;
    s << "expected answer: " << expected << endl;
    s << "your answer: " << n << endl;
    s << "===================================\n";
    cerr << s.str() << endl;
    num_fail++;
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
