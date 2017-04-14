//
// Created by Honghao Li on 4/5/17.
//


// Problem
// An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would perfer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, dequeueCat. You may use the built-in LinkedList data structure.

#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;


template<typename T>
class MyQueue {

 public:

  bool isEmpty() { return first == nullptr; }

  void enqueue(T item) {
    Node *oldlast = last;
    last = new Node(item);
    if (isEmpty()) {
      first = last;
    } else {
      oldlast->next = last;
    }
    num++;
    // debug
    if (debug_mode)
      print();
  }

  T dequeue() {
    if (isEmpty())
      throw out_of_range("The stack is empty.\n");
    Node p = *first;
    first = first->next;
    num--;
    // debug
    if (debug_mode)
      print();
    return p.item;
  }

  T peek() {
    if (isEmpty())
      throw out_of_range("The stack is empty.\n");
    return first->item;
  }

  inline int size() { return num; }

  string toString() {
    ostringstream s;
    Node *n = first;
    while (n != nullptr) {
      s << n->item << " <- ";
      n = n->next;
    }
    s << "nullptr" << " (total: " << num << " nodes)";
    return s.str();
  }

  void print() {
    cout << toString() << endl << flush;
  }

 private:

  struct Node {
    Node() = default;
    Node(T item) : item(item) {}
    T item;
    Node *next = nullptr;
  };

  Node *first = nullptr;
  Node *last = nullptr;
  int num = 0;

  bool debug_mode = false;

};

// 1st method
// we could keep both cat and dog in a single queue, but it would be unefficient when get the dog or cat by searching the first one.

// 2nd method
// as in text book, we could use two separate queue for cat and dog.

//
enum AnimalType {dog, cat};

struct Animal {
  Animal() = default;
  Animal(string name) : name(name) {}
  string name = "";
  int order = 0;
  AnimalType type;
};

ostream& operator<<(ostream& os, const Animal& a)
{
  os << a.name << a.order;
  return os;
}


struct Dog : Animal {
  Dog(string _name) {
    name = _name;
    type = AnimalType::dog;
  }
};

struct Cat : Animal {
  Cat(string _name) {
    name = _name;
    type = AnimalType::cat;
  }
};

//
class AnimalQueue {
 public:

  void enqueue(Animal a) {
    a.order = order++;
    if (a.type == AnimalType::dog)
      dogs.enqueue(a);
    else if (a.type == AnimalType::cat)
      cats.enqueue(a);
    // debug
    if (debug_mode)
      print();
  }

  Animal dequeueAny() {
    Animal a;
    if (dogs.size() == 0)
      a = cats.dequeue();
    else if (cats.size() == 0)
      a = dogs.dequeue();
    else {
      a = dogs.peek().order < cats.peek().order ? dogs.dequeue() : cats.dequeue();
    }
    // debug
    if (debug_mode)
      print();
    return a;
  }

  Animal dequeueDog() {
    Animal a = dogs.dequeue();
    // debug
    if (debug_mode)
      print();
    return a;
  }

  Animal dequeueCat() {
    Animal a = cats.dequeue();
    // debug
    if (debug_mode)
      print();
    return a;
  }

  void print() {
    printf("===========================\n");
    printf("Dogs: ");
    dogs.print();
    printf("Cats: ");
    cats.print();
    printf("===========================\n");
  }

 private:
  int order = 0;
  MyQueue<Animal> dogs;
  MyQueue<Animal> cats;

  bool debug_mode = true;

};



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
    AnimalQueue animals;
    animals.enqueue(Dog("d"));
    animals.enqueue(Cat("c"));
    animals.enqueue(Dog("dd"));
    animals.enqueue(Dog("ddd"));
    animals.enqueue(Dog("aaa"));
    animals.enqueue(Dog("abcd"));
    animals.enqueue(Dog("poop"));
    animals.enqueue(Dog("mnkn"));
    animals.enqueue(Cat("ccc"));
    animals.enqueue(Cat("mene"));
    animals.enqueue(Cat("ieie"));
    animals.enqueue(Cat("zncb"));
    animals.enqueue(Cat("retd"));
    animals.enqueue(Cat("shjd"));
    animals.dequeueAny();
    animals.dequeueAny();
    animals.dequeueDog();
    animals.dequeueDog();
    animals.dequeueCat();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

