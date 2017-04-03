//
// Created by Honghao Li on 3/29/17.
//

// PROBLEM
// Loop detection
// Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
// EXAMPLE
// Input: A -> B -> C -> D -> E -> F -> C   [ the same C as earlier]
// Output:  C


#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

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
    // for debug, circular list for example
    if (N > 20) {
      s << "..." << " (Too many nodes, just stop here). ";
      return s.str();
    }
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
  if (items.size() == 0)
    throw runtime_error("Cannot create linked list with ZERO items!\n");
  Node *head = nullptr;   // the initialization of nullptr is very important
  for (int i = items.size()-1; i >= 0; i--) {
    head = appendToHead(head, items[i]);
  }
  return *head;
}

Node createLinkedListReverseOrder(vector<int> items) {
  if (items.size() == 0)
    throw runtime_error("Cannot create linked list with ZERO items!\n");
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

Node* getKthNode(Node *head, int k) {
  Node *n = head;
  while (n != nullptr && k > 0) {
    n = n->next;
    k--;
  }
  return n;
}

void linkTheTailToKthNode(Node *head, int k) {
  Node *tail = head;
  while (tail != nullptr && tail->next != nullptr) {
    tail = tail->next;
  }
  tail->next = getKthNode(head, k);
}


////////////////////// Solution ////////////////////////
// The 1st method
// Use hashmap to store all the pointer address while checking if key is in there.
Node* findCircleStartNode1(Node *head) {
  unordered_map<Node*, bool> map;
  Node *n = head;
  while (n != nullptr) {
    if (map.find(n) != map.end()) {
      return n;
    }
    map[n] = true;
    n = n->next;
  }
  // reach the end, nothing found.
  return nullptr;
}


// 2nd method
// Inspired by the textbook.
// Create two pointers with different speed, if there is circle, two pointers will finally collide with each other.
// Here we make slower pointer moves one step and faster pointer moves two steps .
// Suppose the circle has total N nodes, when the slow pointer first time enter the circle, it's position is 0, and the fast pointer is at k position. So the distance between them is k. The next step, fast goes to k+2, while slow at 1. So the new distance would be (k + 1) % N. Eventually it would become 0 at some point, at most N steps.

// But the collision point is not the entrance of the circle. There is a great argument about this in the textbook.
// How to find the start node of circle?
// Suppose there are k "un-loop" nodes at the beginning, and there are N nodes in the loop.
// when slow p is at the start of loop (position 0 in loop), position k in list, the fast p is at position 2k in list, where is position k in the loop. So the distance between them is (N - k).
// So they collide after (N - k) step. then the slow p and the fast p are both at (N - p ) in the loop. They are k nodes away from the start of the loop. Which is the same distance from the start of the list to the start of loop.

// Just to create a new pointer at the start!!!

Node* findCircleStartNode2(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast)
      break;
  }
  // if reach the end, nothing found.
  if (fast == nullptr || fast->next == nullptr)
    return nullptr;
  // else try to find the start of loop
  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
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
    Node l;
//    l = createLinkedList({});
//    linkTheTailToKthNode(&l, 0);
//    unitTest(&l, getKthNode(&l, 0));

    l = createLinkedList({1,2,3,4,5});
    unitTest(&l, nullptr);

    l = createLinkedList({0,1,2,3,4,5,6,7,8,9,10});
    linkTheTailToKthNode(&l, 5);
    unitTest(&l, getKthNode(&l, 5));

    l = createLinkedList({0,1});
    linkTheTailToKthNode(&l, 0);
    unitTest(&l, getKthNode(&l, 0));

    l = createLinkedList({0,1});
    linkTheTailToKthNode(&l, 0);
    unitTest(&l, getKthNode(&l, 0));

    l = createLinkedList({0,1});
    linkTheTailToKthNode(&l, 1);
    unitTest(&l, getKthNode(&l, 1));

    l = createLinkedList({0});
    linkTheTailToKthNode(&l, 0);
    unitTest(&l, getKthNode(&l, 0));

    l = createLinkedList({0,1,2,3,4,5,6,7,8,9,5,6,7,8,9,5,6,7,8,9});
    unitTest(&l, nullptr);

    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(Node *head, Node *expected) {
    ostringstream s;
//    Node *result = findCircleStartNode1(head);
    Node *result = findCircleStartNode2(head);
    s << "\n========== test failed! ===========\n";
    s << "Linked list input 1: " << toString(head) << endl;
    if (expected)
      s << "expected answer: " << expected->item << endl;
    else
      s << "expected answer: nullptr " << endl;
    if (result)
      s << "your answer: " << result->item << endl;
    else
      s << "your answer: nullptr " << endl;
    s << "===================================\n";
    if (result != expected){
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
