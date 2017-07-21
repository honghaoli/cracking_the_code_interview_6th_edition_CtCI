//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Write a method to shuffle a deck of cards. It must be a perfect shuffle -- in other words, each of the 52! permutations of the deck has to be equally likely. Assume that you are given a random number generator which is perfect.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * The famous Fisher-Yates-Knuth shuffle algorithm
 *        https://en.wikipedia.org/wiki/Fisher–Yates_shuffle
 * Choose one of those variations
 */


default_random_engine generator;

// both lo and hi are inclusive.
int random_range(int lo, int hi) {
  uniform_int_distribution<int> distribution(lo, hi);
  return distribution(generator);
}


template <typename T>
void fyk_shuffle(vector<T> &deck) {
  for (int i = 0; i < deck.size(); ++i) {
    int idx = random_range(i, deck.size() - 1);
    // exchange i and idx.
    T tmp = deck[idx];
    deck[idx] = deck[i];
    deck[i] = tmp;
  }
}

// 2nd method



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test(vector<int> vec, int N) {
    print_vector(vec);
    printf("shuffle %d times:\n", N);
    for (int i = 0; i < N; ++i) {
      fyk_shuffle(vec);
      print_vector(vec);
    }
  }

  void unit_test() {
    test({1,2,3}, 20);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    unit_test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

