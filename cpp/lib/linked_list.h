//
// Created by Honghao Li on 3/29/17.
//

#ifndef CTCI_6TH_LINKED_LIST_H
#define CTCI_6TH_LINKED_LIST_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

template <typename T> class LinkedList {

 public:

  // problem 01
  void removeDups();
  // problem 01
//  Node* findKthToLast(int k);
  std::string findKthToLastToString(int k);




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
    s << "nullptr" << " (total: " << N << ")";
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

  // forward declaration for use in Iterator.
  struct Node {
    Node() = default;
    Node(T item) : item(item) {}

    Node *next = nullptr;
    T item;
  };

  // Iterator implementation makes life easier " for (auto &l : linked_list) "
  // there are many reference, one could be: http://stackoverflow.com/a/28926968/4140007
  class Iterator {
   public:
    Iterator() = default;
    Iterator(const Node *pNode) noexcept : current_node(pNode) {}

    Iterator& operator=(Node *pNode) {
      this->current_node = pNode;
      return *this;
    }

    // prefix ++ overload
    Iterator& operator++() {
      if (current_node)
        current_node = current_node->next;
      return *this;
    }

    // postfix ++ overload ignored here

    bool operator!=(const Iterator& iterator) {
      return current_node != iterator.current_node;
    }

    // dereference operator
    const T& operator*() const {
      return current_node->item;
    }

   private:
    const Node * current_node;
  };

  // now implement begin and end
  Iterator begin() const {
    return Iterator(head);
  }
  Iterator end() const {
    return Iterator(nullptr);
  }

 private:

  Node *head = nullptr;  // the first node
  int N = 0;  // number of items

};


#endif //CTCI_6TH_LINKED_LIST_H
