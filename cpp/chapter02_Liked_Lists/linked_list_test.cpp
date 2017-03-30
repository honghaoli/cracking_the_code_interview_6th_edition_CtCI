//
// Created by Honghao Li on 3/30/17.
//

#include <cstdio>
#include "linked_list.h"

int main() {
  LinkedList<int> llist = LinkedList<int>();
  llist.print();
  llist.appendToHead(1);
  llist.print();
  llist.appendToHead(2);
  llist.print();
  llist.appendToHead(3);
  llist.print();
  llist.appendToHead(4);
  llist.print();
  llist.appendToHead(5);
  llist.print();
  printf("size of list: %d\n", llist.size());
  llist.appendToTail(6);
  llist.print();
  llist.appendToTail(7);
  llist.print();
  llist.appendToTail(8);
  llist.print();
  llist.appendToTail(9);
  llist.print();
  printf("size of list: %d\n", llist.size());
  llist.deleteNode(3);
  llist.print();
  printf("size of list: %d\n", llist.size());
  llist.deleteNode(100);
  llist.print();
  llist.appendToHead(10);
  llist.appendToTail(10);
  llist.print();
  llist.deleteNode(10);
  llist.print();
  llist.deleteNode(10);
  llist.print();
  printf("size of list: %d\n", llist.size());
  llist.deleteNode(10);
  llist.print();
  /// new tests
  llist = LinkedList<int>(std::vector<int> {0, 1, 2, 3, 4, 5});
  printf("size of list: %d\n", llist.size());
  llist.print();
  llist.deleteNode(1);
  llist.print();
}
