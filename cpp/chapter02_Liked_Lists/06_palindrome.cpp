//
// Created by Honghao Li on 3/29/17.
//

// PROBLEM
// Implememt a function to check if a linked list is a palindrome.

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
// Create another reversed linkded list, and compare to the original one.
bool isPalindrome(Node *head) {
  Node *reversed = nullptr;
  Node *n = head;
  while (n != nullptr) {
    reversed = appendToHead(reversed, n->item);
    n = n->next;
  }
  //
  return isEqual(reversed, head);
}


// 2nd method
// only one iteration through the linked list
// Every time reaches the node that might be the middle one, create a pointer and move back and compare. If one pointer reach to the head when the iteration reach the end, it's a palindrome.
bool isPalindrome2(Node *head) {
  // not easy to move backwards in this data structure, use a doubly linded list instead.
  return false;
}


// 3rd method
// As stated in the textbook, we can only reverse the first half and compare with the 2nd half. Use two pointers, slow / fast to determine the middle point.
// Textbook answer use STACK, which can be implemented using linked list. So I'll stick to linked list here.
bool isPalindrome3(Node *head) {
  Node *reversed = nullptr;
  Node *slow = head;
  Node *fast = head;
  // we should carefully consider odd / even cases
  // For example ||| even linked list:  0 -> 1 -> nullptr;      odd linked list: 0 -> 1 -> 2 -> nullptr;
  //                   faster pointer:            here                                    here
  //                   slower pointer:      here                                    here
  //   reversed linked list should be:  0 -> nullptr;                            0 -> 1 -> nullptr;
  while (fast != nullptr && fast->next != nullptr) {
    reversed = appendToHead(reversed, slow->item);
    fast = fast->next->next;
    slow = slow->next;
  }
  if (fast != nullptr) {
    reversed = appendToHead(reversed, slow->item);   // I append the middle item into the reversed list.
//    slow = slow->next;     // One can also move slow forward one step to skip the middle point as shown in the textbook answer.
  }


  // compare with 2nd half
  while (slow != nullptr) {
    if (reversed == nullptr)
      return false;
    if (slow->item != reversed->item)
      return false;
    slow = slow->next;
    reversed = reversed->next;
  }
  return true;
}




// 4th method
// Recursive Approach in the text book;
// recursive call would takes extra space and the algorithm itself is not more effecient.





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
    Node l;
    l = createLinkedListReverseOrder({1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,1,1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,2,1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,3,3,1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,2});
    unitTest(&l, false);
    l = createLinkedListReverseOrder({4,4,4,4,4,4,4,4,4,4,4,4});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({4,4,4,4,4,4,4,4,4,4,4});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1});
    unitTest(&l, true);
    l = createLinkedListReverseOrder({1,2,3,4,5,4,3,2});
    unitTest(&l, false);
    l = createLinkedListReverseOrder({1,2,3,4,5,4,3,2,1,0});
    unitTest(&l, false);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(Node *head, bool palindrome) {
    ostringstream s;
//    bool result = isPalindrome(head);
    bool result = isPalindrome3(head);
    s << "\n========== test failed! ===========\n";
    s << "Linked list input 1: " << toString(head) << endl;
    s << "expected answer: " << (palindrome ? "Yes" : "No") << endl;
    s << "your answer: " << (result ? "Yes" : "No") << endl;
    s << "===================================\n";
    if (result != palindrome){
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
