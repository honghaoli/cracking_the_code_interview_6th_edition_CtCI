//
// Created by Honghao Li on 3/29/17.
//

// Problem:
// Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed.

#include <cstdio>
#include <unordered_map>
#include "linked_list.h"


// Assume we only have upper and lower case letters a-z A-Z

////////////////////// Solution ////////////////////////
void removeDups(LinkedList<int> llist) {
  llist.removeDups();
}

// The 1st method
// use hash map to store all the items, maybe we can use another data structure rather than <key, value> pair.
//template <typename T>
//void LinkedList<T>::removeDups() {
//  using namespace std;
//  unordered_map<T, bool> map;
//  Node *n = head;
//  if (n == nullptr)
//    return;
//  map[n->item] = true;
//  while (n->next != nullptr) {
//    if (map.find(n->next->item) != map.end()) {
//      Node *tmp = n->next;
//      n->next = n->next->next;
//      delete tmp;
//      N--;
//    } else {
//      map[n->next->item] = true;
//      n = n->next;
//    }
//  }
//}



// 2nd method
// without buffer, do it ~O(N^2)
template <typename T>
void LinkedList<T>::removeDups() {
  Node *n = head;
  while (n != nullptr) {
    Node *m = n;
    while (m->next != nullptr) {
      if (m->next->item == n->item) {
        Node *tmp = m->next;
        m->next = m->next->next;
        delete tmp;
        N--;
        continue;
      }
      m = m->next;
    }
    n = n->next;
  }
}

// 3rd method





////////////////////// Test ////////////////////////
class Test {

 public:

  Test(void (*test_func)(LinkedList<int>)) {
    func = test_func;
    basicTests();
  }

 private:
  int num_fail = 0;
  void (*func)(LinkedList<int>);

  void basicTests() {
    // customize your own tests here
    unitTest(LinkedList<int>({0,1,2,3,0,4,5,0,0}), LinkedList<int>({0,1,2,3,4,5}));
    unitTest(LinkedList<int>({0,0,0,0,0,0,0,0,0}), LinkedList<int>({0}));
    unitTest(LinkedList<int>({0,1,0,1,0,1,0,1,0,1}), LinkedList<int>({0,1}));

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(LinkedList<int> llist, LinkedList<int> expected) {

    using namespace std;
    ostringstream s;
    s << "\n========== test failed! ===========\n";
    s << "Linked list input: " << llist.toString() << endl;
    s << "expected answer: " << expected.toString() << endl;
//    func(llist);
    llist.removeDups();
    s << "your answer: " << llist.toString() << endl;
    s << "===================================\n";
//    std::cerr << "llist size = " << llist.size() << std::endl;

    if (!llist.isEqual(expected) ) {
      cerr << s.str() << endl;
      num_fail++;
    }
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test(removeDups);  // change the method you want to test here.
  return 0;
}
