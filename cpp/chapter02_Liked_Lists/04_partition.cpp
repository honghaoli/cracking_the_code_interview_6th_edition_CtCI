//
// Created by Honghao Li on 3/29/17.
//

// PROBLEM
// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
// EXAMPLE
// Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
// Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8


// For simplicity, I will use a in-place defined linked list, and make the type of data only int or char.
// the linked list is represented by the head node

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
  Node() = default;
  Node(int item) : item(item) {}
  Node *next = nullptr;
  int item = 0;
};

string toString(Node *head) {
  using namespace std;
  ostringstream s;
  Node *n = head;
  int N = 0;
  while (n != nullptr) {
    s << n->item << " -> ";
    n = n->next;
    N++;
  }
  s << "nullptr" << " (total: " << N << ")";
  return s.str();
}

bool isEqual(Node *l1, Node *l2) {
  Node *n1 = l1;
  Node *n2 = l2;
  while (n1 != nullptr) {
    if (n2 == nullptr)
      return false;
    if (n1->item != n2->item)
      return false;
    n1 = n1->next;
    n2 = n2->next;
  }
  return true;
}

Node* appendToHead(Node *head, int item) {
  Node *oldhead = head;
  head = new Node(item);
  head->next = oldhead;
  return head;
}

Node createLinkedList(vector<int> items) {
  Node *head = nullptr;   // the initialization of nullptr is very important
  for (int i = items.size()-1; i >= 0; i--) {
    head = appendToHead(head, items[i]);
  }
  return *head;
}



////////////////////// Solution ////////////////////////
// The 1st method
// just move the node with smaller value to the head;
Node* partition1(Node *head, int value) {
  Node *n = head;
  // sorting makes sense with at least two elements
  while (n != nullptr && n->next != nullptr) {
    if (n->next->item < value) {
      Node *tmp = n->next;
      n->next = n->next->next;
      Node *oldhead = head;
      tmp->next = oldhead;
      head = tmp;
    } else {
      n = n->next;
    }
  }
  return head;
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
    Node l, l2;
    l = createLinkedList({0,1,2,3,0,4,5,0,0});
    l2 = createLinkedList({0,0,0,2,1,0,3,4,5});
    unitTest(&l, 3, &l2);
    l = createLinkedList({0,1,2,3,0,4,5,0,0});
    unitTest(&l, 0, &l);
    unitTest(&l, -1, &l);
    unitTest(&l, -1000, &l);
    l = createLinkedList({0,1,2,3,0,4,5,0,0});
    l2 = createLinkedList({0,0,0,0,1,2,3,4,5});
    unitTest(&l, 1, &l2);
    l = createLinkedList({0,1,2,3,4,5,6,7,8});
    l2 = createLinkedList({6,5,4,3,2,1,0,7,8});
    unitTest(&l, 7, &l2);
    l = createLinkedList({0,1,2,3,4,5,6,7,8});
    l2 = createLinkedList({7,6,5,4,3,2,1,0,8});
    unitTest(&l, 8, &l2);
    l = createLinkedList({0,1,2,3,4,5,6,7,8});
    l2 = createLinkedList({8,7,6,5,4,3,2,1,0});
    unitTest(&l, 9, &l2);
    l = createLinkedList({0,1,2,3,4,5,6,7,8});
    l2 = createLinkedList({8,7,6,5,4,3,2,1,0});
    unitTest(&l, 1000, &l2);
    l = createLinkedList({15,15,15,15,15,15,9,9,9,9,9,7,7,7,7,7,7});
    l2 = createLinkedList({7,7,7,7,7,7,15,15,15,15,15,15,9,9,9,9,9});
    unitTest(&l, 8, &l2);
    l = createLinkedList({15,15,15,15,15,15,9,9,9,9,9,7,7,7,7,7,7});
    l2 = createLinkedList({7,7,7,7,7,7,9,9,9,9,9,15,15,15,15,15,15});
    unitTest(&l, 10, &l2);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(Node *llist, int value, Node *expected) {
    ostringstream s;
    s << "\n========== test failed! ===========\n";
    s << "Linked list input: " << toString(llist) << endl;
    s << "Partition value: " << value << endl;
    s << "expected answer: " << toString(expected) << endl;
    llist = partition1(llist, value);
    s << "your answer: " << toString(llist) << endl;
    s << "===================================\n";
    if ( !isEqual(llist, expected) ){
      cerr << s.str() << endl << flush;
      num_fail++;
    }
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
