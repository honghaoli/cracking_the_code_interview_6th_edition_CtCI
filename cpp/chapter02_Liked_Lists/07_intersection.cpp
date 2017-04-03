//
// Created by Honghao Li on 3/29/17.
//


// PROBLEM
// INTERSECTION
// Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.


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

Node* appendToTail(Node *head, int item) {
  if (head == nullptr) {
    head = new Node(item);
    return head;
  }
  Node *n = head;
  while (n->next != nullptr) {
    n = n->next;
  }
  n->next = new Node(item);
  return head;
}

Node createLinkedList(vector<int> items) {
  Node *head = nullptr;   // the initialization of nullptr is very important
  for (int i = items.size()-1; i >= 0; i--) {
    head = appendToHead(head, items[i]);
  }
  return *head;
}

Node createLinkedListReverseOrder(vector<int> items) {
  Node *head = nullptr;   // the initialization of nullptr is very important
  for (auto &item : items) {
    head = appendToHead(head, item);
  }
  return *head;
}

Node createLinkedListByCombineTwo(Node *head1, Node *head2) {
  Node *tail1 = head1;
  while (tail1 != nullptr && tail1->next != nullptr) {
    tail1 = tail1->next;
  }
  tail1->next = head2;
  return *tail1;
}


////////////////////// Solution ////////////////////////
// The 1st method
// Use hashmap to store all the pointer address while checking if key is in there.


// 2nd method
// From the textbook
// If two linked list intersects, the last node must be identical.
// Then chop off the extra head nodes in the longer list, move forward together, to find the exact intersection.
Node* findIntersection(Node *head1, Node *head2) {
  if (head1 == nullptr || head2 == nullptr)
    return nullptr;
  //
  Node *n1 = head1;
  Node *n2 = head2;
  int length1 = 0;
  int length2 = 0;
  while (n1 != nullptr) {
    length1++;
    n1 = n1->next;
  }
  while (n2 != nullptr) {
    length2++;
    n2 = n2->next;
  }
  // if the last nodes are not the same, no intersection
  if (n1 != n2)
    return nullptr;
  //
  int diff = abs(length1 - length2);
  // n1 is the longer list, n2 is the shorter list.
  n1 = length1 > length2 ? head1 : head2;
  n2 = length1 <= length2 ? head1 : head2;
  // chop off extra nodes
  for (int i = 0; i < diff; i++) {
    n1 = n1->next;
  }

  // move forward together
//  while (n1 != nullptr) {
//    if (n1 == n2)
//      return n1;
//    n1 = n1->next;
//    n2 = n2->next;
//  }
//  return nullptr;

  // better and clean writing from the textbook
  while (n1 != n2) {
    n1 = n1->next;
    n2 = n2->next;
  }
  return n1;

}


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
    Node l1, l2, tail;
    tail = createLinkedList({1});
    l1 = createLinkedList({1});
    l2 = createLinkedList({1});
    l1 = createLinkedListByCombineTwo(&l1, &tail);
    l2 = createLinkedListByCombineTwo(&l2, &tail);
    unitTest(&l1, &l2, &tail);
    l1 = createLinkedList({1});
    l2 = createLinkedList({1});
    unitTest(&l1, &l2, nullptr);

    tail = createLinkedList({1,2,3,4,5});
    l1 = createLinkedList({9,8,7});
    l2 = createLinkedList({0,10});
    l1 = createLinkedListByCombineTwo(&l1, &tail);
    l2 = createLinkedListByCombineTwo(&l2, &tail);
    unitTest(&l1, &l2, &tail);
    l1 = createLinkedList({1,2,3,4,5,6,7});
    l2 = createLinkedList({11,23,34,56});
    unitTest(&l1, &l2, nullptr);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(Node *head1, Node *head2, Node *expected) {
    ostringstream s;
    Node *intersection = findIntersection(head1, head2);
    s << "\n========== test failed! ===========\n";
    s << "Linked list input 1: " << toString(head1) << endl;
    s << "Linked list input 2: " << toString(head2) << endl;
    if (expected)
      s << "expected answer: " << expected->item << endl;
    else
      s << "expected answer: nullptr " << endl;
    if (intersection)
      s << "your answer: " << intersection->item << endl;
    else
      s << "your answer: nullptr " << endl;
    s << "===================================\n";
    if (intersection != expected){
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
