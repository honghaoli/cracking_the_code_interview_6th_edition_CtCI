//
// Created by Honghao Li on 3/29/17.
//

#ifndef CTCI_6TH_LINKED_LIST_H
#define CTCI_6TH_LINKED_LIST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

template <class T>

class LinkedList {

 public:

  void removeDups();

  LinkedList() = default;
  LinkedList(std::vector<T> items) {
    for (int i = items.size()-1; i >= 0; i--) {
      this->appendToHead(items[i]);
    }
  }

  bool isEmpty() { return head == nullptr; }
  int size() { return N; }

  void appendToTail(T item) {
    Node *end = new Node(item);
    Node *n = head;
    while (n->next != nullptr) {
      n = n->next;
    }
    n->next = end;
    N++;
  }

  void appendToHead(T item) {
    Node *n = new Node(item);
    n->next = head;
    head = n;
    N++;
  }

  // delete only first found item node
  bool deleteNode(T item) {
    Node *n = head;
    if (n->item == item) {
      head = head->next;
      delete n;
      N--;
      return true;
    }

    while (n->next != nullptr) {
      if (n->next->item == item) {
        Node *tmp = n->next;
        n->next = n->next->next;
        delete tmp;
        N--;
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
    Node *n = head;
    while (n != nullptr) {
      s << n->item << " -> ";
      n = n->next;
    }
    s << "nullptr";
    return s.str();
  }

  bool isEqual(LinkedList<T> l) {
    if (size() != l.size())
      return false;
    Node *n = head;
    Node *nl = l.head;
    while (n != nullptr) {
      if (n->item != nl->item)
        return false;
      n = n->next;
      nl = nl->next;
    }
    return true;
  }


 private:

  struct Node {
    Node(T item) : item(item) {}
    Node *next = nullptr;
    T item;
  };

  Node *head = nullptr;  // the first node
  int N = 0;  // number of items

};


#endif //CTCI_6TH_LINKED_LIST_H
