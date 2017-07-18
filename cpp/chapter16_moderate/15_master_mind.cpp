//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Master Mind: The Game of Master Mind is played as follows:
 * The computer has four slots, and each slot will contain a ball that is red (R), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (slot #1,2,3,4 are red,green,green,blue).
 * You, the user, are trying to guess the solution. You might, for example, guess YRGB.
 * When you guess the correct color for the correct slot, you get a "hit". If you guess a color that exists but is in the wrong slot, you get "pseudo-hit". Note that a slot that is a hit can never count as a pseudo-hit.
 * For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudo-hit. Write a method that, given a guess and a solution, returns the number of hits and pseduo-hits.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * array of integers for 4 colors.
 * one array for solution, one for guess.
 * First check how many correct color numbers.
 * Then walk through for "hit", minus this "hit" we get "pseudo-hit".
 */
pair<int, int> find_hits(string &solution, string &guess) {
  // boundary check
  if (solution.size() != 4 || guess.size() != 4) {
    cout << "Wrong size of solution or guess!!!" << endl;
    return make_pair(-1, -1);
  }

  int hit = 0;
  vector<int> num_solution = vector<int>(4, 0);
  vector<int> num_guess = vector<int>(4, 0);
  for (int i = 0; i < 4; ++i) {
    char &s = solution[i];
    char &g = guess[i];
    if (g == s)
      hit++;
      // or continue here, skip the rest code if hit,
      // in that way, we don't need to subtract hit, the psuedo-hit is correct.

    if (s == 'R')
      num_solution[0]++;
    else if (s == 'Y')
      num_solution[1]++;
    else if (s == 'G')
      num_solution[2]++;
    else if (s == 'B')
      num_solution[3]++;
    else {
      cout << "Wrong input color " << s << " in solution!" << endl;
      return make_pair(-1, -1);
    }

    if (g == 'R')
      num_guess[0]++;
    else if (g == 'Y')
      num_guess[1]++;
    else if (g == 'G')
      num_guess[2]++;
    else if (g == 'B')
      num_guess[3]++;
    else {
      cout << "Wrong input color " << s << " in guess!" << endl;
      return make_pair(-1, -1);
    }
  }

  // count psuedo hit
  int psuedo = 0;
  for (int i = 0; i < 4; ++i) {
    psuedo += min(num_solution[i], num_guess[i]);
  }
  psuedo -= hit;

  return make_pair(hit, psuedo);
};

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

  void test(string solution, string guess) {
    auto result = find_hits(solution, guess);
    cout << endl
         << "solution: " << solution << endl
         << "guess: " << guess << endl
         << "hits: " << result.first << ", psuedo-hits: " << result.second << endl;
  }

  void unit_test() {
    test("RGBY", "GGRR");
    test("RRRR", "GGGG");
    test("RRRR", "RRRR");
    test("RGBY", "RGBY");
    test("RRGG", "GGRR");
    test("R", "GGRR");
    test("GGRO", "GGRR");
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

