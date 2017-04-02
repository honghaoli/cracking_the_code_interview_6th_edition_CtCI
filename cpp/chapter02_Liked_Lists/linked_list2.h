//
// Created by Honghao Li on 3/29/17.
//

// A better version only for solving the problems in the textbook
// So everything is public :)

#ifndef CTCI_6TH_LINKED_LIST_H
#define CTCI_6TH_LINKED_LIST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

template <typename T>
struct Node {
  Node() = default;
  Node(T item) : item(item) {}

  Node *next = nullptr;
  T item;

};

template <typename T> class LinkedList {

 public:
  // problem 3
  void removeKthNodeFromLinkedList(int k);

  LinkedList() = default;
  LinkedList(std::vector<T> items) {
    for (int i = items.size()-1; i >= 0; i--) {
      this->appendToHead(items[i]);
    }
  }

  bool isEmpty() { return head == nullptr; }

  void appendToTail(T item) {
    Node<T> *end = new Node<int>(item);
    Node<T> *n = head;
    while (n->next != nullptr) {
      n = n->next;
    }
    n->next = end;
  }

  void appendToHead(T item) {
    Node<T> *n = new Node<int>(item);
    n->next = head;
    head = n;
  }

  // delete only first found item node
  bool deleteNode(T item) {
    Node<T> *n = head;
    if (n->item == item) {
      head = head->next;
      delete n;
      return true;
    }

    while (n->next != nullptr) {
      if (n->next->item == item) {
        Node<T> *tmp = n->next;
        n->next = n->next->next;
        delete tmp;
        return true;
      }
      n = n->next;
    }
    return false;   // item not found
  }

  // debug
  void print() {
    printf("%s\n", toString().c_str());
  }

  std::string toString() {
    using namespace std;
    ostringstream s;
    Node<T> *n = head;
    int N = 0;
    while (n != nullptr) {
      s << n->item << " -> ";
      n = n->next;
      N++;
    }
    s << "nullptr" << " (total: " << N << ")";
    return s.str();
  }

  bool isEqual(LinkedList<T> l) {
    Node<T> *n = head;
    Node<T> *nl = l.head;
    while (n != nullptr) {
      if (nl == nullptr)
        return false;
      if (n->item != nl->item)
        return false;
      n = n->next;
      nl = nl->next;
    }
    return true;
  }

  Node<T> *head = nullptr;  // the first node

};


#endif //CTCI_6TH_LINKED_LIST_H
