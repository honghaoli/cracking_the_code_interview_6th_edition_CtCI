//
// Created by Honghao Li on 3/29/17.
//


// PROBLEM
// SUM LISTS
// You have two numbers represented by a linked lis, where each node contains a single digit. The digis are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and return the sum as a lined list.
// EXAMPLE
// INPUT: (7 -> 1 -> 6) + (5 -> 9 -> 2). that is 617 + 295.
// OUTPUT: 2 -> 1 -> 9. that is 912.
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem;
// EXAMPLE
// INPUT: (6 -> 1 -> 7) + (2 -> 9 -> 5). that is 617 + 295.
// OUTPUT: 9 -> 1 -> 2. that is 912.

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



////////////////////// Solution ////////////////////////
// The 1st method
// straight forward implementation
// Note append to a linked list here is not efficient, one should use previous data structure, store the head / tail pointer.
Node sumLists(Node *head1, Node *head2) {
  Node *n1 = head1;
  Node *n2 = head2;
  Node *s = nullptr;
  int carry = 0;
  for(;;) {
    if (n1 == nullptr && n2 == nullptr) {
      if (carry == 0)
        break;
    }
    int add = 0;
    if (n1 != nullptr) {
      add += n1->item;
      n1 = n1->next;
    }
    if (n2 != nullptr) {
      add += n2->item;
      n2 = n2->next;
    }
    add += carry;
    if (add > 9) {
      add -= 10;
      carry = 1;
    } else {
      carry = 0;
    }
    //
    s = appendToTail(s, add);
  }
  return *s;
}
// For the follow up problem
// I think the most efficient way is to just reverse the linked list, and use the above method with improved data structure.
// The answer in the text book seems tedious for me.


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
    Node l1, l2, ls;
    l1 = createLinkedListReverseOrder({1});
    l2 = createLinkedListReverseOrder({1});
    ls = createLinkedListReverseOrder({2});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({5});
    l2 = createLinkedListReverseOrder({5});
    ls = createLinkedListReverseOrder({1,0});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({7});
    l2 = createLinkedListReverseOrder({5});
    ls = createLinkedListReverseOrder({1,2});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({0});
    l2 = createLinkedListReverseOrder({0});
    ls = createLinkedListReverseOrder({0});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({1,2,3,4,5,6});
    l2 = createLinkedListReverseOrder({1,2,3,4,5,6});
    ls = createLinkedListReverseOrder({2,4,6,9,1,2});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({9,2,3,4,5,6});
    l2 = createLinkedListReverseOrder({9,2,3,4,5,6});
    ls = createLinkedListReverseOrder({1,8,4,6,9,1,2});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({9,9,9,9,9,9});
    l2 = createLinkedListReverseOrder({1});
    ls = createLinkedListReverseOrder({1,0,0,0,0,0,0});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({9,9,9,9,9,9});
    l2 = createLinkedListReverseOrder({9,9});
    ls = createLinkedListReverseOrder({1,0,0,0,0,9,8});
    unitTest(&l1, &l2, &ls);
    l1 = createLinkedListReverseOrder({9,9});
    l2 = createLinkedListReverseOrder({9,9,9,9,9,9});
    ls = createLinkedListReverseOrder({1,0,0,0,0,9,8});
    unitTest(&l1, &l2, &ls);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(Node *head1, Node *head2, Node *expected) {
    ostringstream s;
    Node result = sumLists(head1, head2);
    s << "\n========== test failed! ===========\n";
    s << "Linked list input 1: " << toString(head1) << endl;
    s << "Linked list input 2: " << toString(head2) << endl;
    s << "expected answer: " << toString(expected) << endl;
    s << "your answer: " << toString(&result) << endl;
    s << "===================================\n";
    if ( !isEqual(&result, expected) ){
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
