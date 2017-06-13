//
// Created by Honghao Li on 4/22/17.
//

// Problem
// Given a boolean expression consisting of the symbols 0 (false), 1 (true), &(AND), | (OR), and ^ (XOR), and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result. The expression should be fully parenthesized (e.g., (0) ^ (1) ) but not extraneously (e.g., (((0)) ^ (1)) ).
// EXAMPLE
// countEval( "1^0|0|1", false) -> 2
// countEval( "0&0&0&1^1|0", true) -> 10




#include <cstdio>
#include <iostream>
#include <vector>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * Note:
 * We should consider (0) ^ (1) also as extraneously parenthesized too, if we use (0 ^ 1) here, the result does not change.
 * Plus, this is more convenient because now each operator has exactly one parenthesis.
 * Then we could convert the problem to: the sequence of applying those operators, notice that different seuqnces may have identical parathesis result.
 * So we could focus on the last operator, which means the last parenthesis.
 * Then recursively find all the possible results for both side of this operator.
 */
/*  Examples:
 * one operator 0 ^ 0 has only one possible parenthesis, thus one possible result.
 * two operator 0 ^ 0 ^ 0 has two possible parenthesis, thus two possible result, with each of these two operator to be the last applied operator.
 * three operator 0 ^ 0 | 0 & 0 has: 2 (^ as last) + 1 (| as last) + 2 (& as last) = 5;
 * four operator 0 ^ 0 | 0 & 0 ^ 0 has: 5 (^ as last) + 1 * 2 (| as last) + 2 * 1 (& as last) + 5 (^ as last) = 14;
 * five operator 0 ^ 0 | 0 & 0 ^ 0 | 0 has: 14 + 1*5 + 2*2 + 5*1 + 14 = 42
 * recursion....
 */

bool char_to_bool(char c) {
  if (c == '0')
    return false;
  if (c == '1')
    return true;
  cerr << "wrong char to bool!\n" << flush;
  return false;
}

bool apply_operator(char c, bool b1, bool b2) {
  if (c == '^')
    return b1 ^ b2;
  if (c == '|')
    return b1 | b2;
  if (c == '&')
    return b1 & b2;
  cerr << "wrong char to operator!\n" << flush;
  return false;
}

// all possible results from the expression.
vector<bool> all_possible(string &expr, size_t start, size_t end, vector<vector<vector<bool>>> &mem) {

  // dynamical programming, test this is much faster.
  if (mem[start][end].size() != 0)
    return mem[start][end];

  vector<bool> all;

  // assume the expr is valid expression.
  if (end - start == 0) {   // no operator, only one bool
    all.push_back(char_to_bool(expr[start]));
    return all;
  }

  if (end - start == 2) {   // exactly one operator
    bool b1 = char_to_bool(expr[start]);
    bool b2 = char_to_bool(expr[start + 2]);
    all.push_back(apply_operator(expr[start + 1], b1, b2));
    return all;
  }

  // recursion
  for (int i = start + 1; i < end; i += 2) {  // iterator all operators
    auto left = all_possible(expr, start, i - 1, mem);
    auto right = all_possible(expr, i + 1, end, mem);
    for (bool bl : left) {
      for (bool br : right) {
        all.push_back(apply_operator(expr[i], bl, br));
      }
    }
  }

  // dynamical programming store
  mem[start][end] = all;
  return all;
}

vector<bool> all_possible(string &expr) {
  vector<vector<vector<bool>>> mem;
  for (int i = 0; i < expr.size(); ++i) {
    mem.push_back(vector<vector<bool>>());
    for (int j = 0; j < expr.size(); ++j) {
      mem[i].push_back(vector<bool>());
    }
  }
  return all_possible(expr, 0, expr.size()-1, mem);
}


bool is_valid(string &expr) {
  if (expr.size() % 2 != 1)
    return false;

  // valid expression should have 0 or 1 at even index (start 0) and | ^ & at odd index.
  for (int i = 0; i < expr.size(); ++i) {
    if ( i % 2 == 0) {
      if (expr[i] != '0' && expr[i] != '1')
        return false;
    } else {
      if (expr[i] != '^' && expr[i] != '|' && expr[i] != '&')
        return false;
    }
  }

  //
  return true;
}

int num_paren(string &expr, bool result) {
  if (!is_valid(expr)) {
    cerr << "Wrong expression! " << expr << endl << flush;
    return 0;
  }
  vector<bool> all = all_possible(expr);
  printf("all possible ways to add parenthesis for string %s, is %ld.\n", expr.c_str(), all.size());
//  print_vector(all);
  int count = 0;
  for (auto r : all) {
    if (r == result)
      count++;
  }
  return count;
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

  void test(string &expr, bool result) {
    int n = num_paren(expr, result);
    printf("%d ways to evaluate string %s to %s.\n\n", n, expr.c_str(), result? "true" : "false" );
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    string expr;

    expr = "1^0";
    test(expr, false);
    expr = "1^0";
    test(expr, true);
    expr = "1^0|0|1";
    test(expr, false);
    expr = "0&0&0&1^1|0";
    test(expr, true);
    expr = "0&0&0&0&0&0&0&0&0&0&0&0&0&0&0";
    test(expr, true);
    expr = "1&1&1&1&1&1&0&1&1&1&1&1&1&1&1";
    test(expr, true);
    expr = "1&1&1&1&1&1&1&1&1&1&1&1&1&1&0";
    test(expr, true);
    expr = "1&1&1&1&1&1&1&1&1&1&1&1&1&1&1";
    test(expr, true);
    expr = "1&1&1&1&1&1&1&1&1&1&1&1&1&1&1&1&1&1";
    test(expr, true);

  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}
