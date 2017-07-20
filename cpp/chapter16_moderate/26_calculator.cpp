//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given an arithmetic equation consisting of positive integers, +, -, * and / (no parentheses), compute the result.
 * EXAMPLE:
 *    INPUT:    2*3+5/6*3+15
 *    OUTPUT:   23.5
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * The book solution:
 * Two stacks for operand and operator, choose the right time to collapse.
 */
enum Operator {
  UNKNOWN, ADD, SUBTRACT, MULTIPLY, DIVIDE, END
};

vector<char> operators {'?', '+', '-', '*', '/', 'E'};
void print_vector(vector<Operator> &vec) {
  for (auto i : vec) {
    std::cout << operators[i] << ", ";
  }
  std::cout << std::endl;
}

bool charIsDigit(char &c) {
  // assume AScii
  // '0' ~ '7' = 60 ~ 67, '8‘ = 70, '9' = 71.
  if (c >= 48 && c <= 57)
    return true;

//  printf("Not digits %c\n", c);
  return false;
}

int parse_next_number(string &input, int &offset) {
  string s = "";
  while (offset < input.size() && charIsDigit(input[offset])) {
    s += input[offset];
    offset++;
  }

  if (s == "") {
    printf("Error! Empty number string read.\n");
    return numeric_limits<int>::quiet_NaN();
  }
  return stoi(s);
}

Operator parse_next_operator(string &input, int &offset) {
  Operator op = END;
  // boundary check
  if (offset >= input.size())
    return op;

  char &c = input[offset];
  if (c == '+') {
    op = ADD;
  } else if (c == '-') {
    op = SUBTRACT;
  } else if (c == '*') {
    op = MULTIPLY;
  } else if (c == '/') {
    op = DIVIDE;
  } else {
    printf("Wrong operator!!! %c\n", c);
    op = UNKNOWN;
  }
  offset++;
  return op;
}

bool hasLowerPriority(Operator &op, Operator &op_prev) {
  if (op == ADD || op == SUBTRACT)
    return true;
  else if (op_prev == MULTIPLY || op_prev == DIVIDE)
    return true;
  return false;
}

void collapse_stacks(vector<double> &nums, vector<Operator> &ops) {
  // boundary check
  if (nums.size() < 2 || ops.size() < 1) {
    printf("Error! try to calculate when less than 2 numbers or less than 1 operator.\n");
    exit(EXIT_FAILURE);
  }

  double num2 = nums.back();
  nums.pop_back();
  double num1 = nums.back();
  nums.pop_back();
  Operator op = ops.back();
  ops.pop_back();

  if (op == ADD) {
    nums.push_back(num1 + num2);
  } else if (op == SUBTRACT) {
    nums.push_back(num1 - num2);
  } else if (op == MULTIPLY) {
    nums.push_back(num1 * num2);
  } else if (op == DIVIDE) {
    nums.push_back(num1 / num2);
  }
}

double calculator(string &input) {
  // boundary check
  if (input.size() == 0)
    return numeric_limits<double>::quiet_NaN();

  // two stack for operator and operand.
  vector<double> nums;  // must use double in case of divide.
  vector<Operator> ops;
  int offset = 0;
  int num;
  Operator op;
  while (offset < input.size()) {
    num = parse_next_number(input, offset);
    // insanity check
    if (num == numeric_limits<int>::quiet_NaN())
      return numeric_limits<double>::quiet_NaN();
    nums.push_back(static_cast<double>(num));

    op = parse_next_operator(input, offset);
    // insanity check
    if (op == UNKNOWN)
      return numeric_limits<double>::quiet_NaN();

    // NOTE: be careful here, easy to make mistakes!
    // continue to collapse when new op has lower priority!
    while (ops.size() > 0 && hasLowerPriority(op, ops.back())) {
      collapse_stacks(nums, ops);
    }
    ops.push_back(op);
  }


  // end, collapse all.
  if (ops.back() == END) {
    ops.pop_back();
    while (nums.size() >= 2 && ops.size() >= 1) {
      collapse_stacks(nums, ops);
    }
  }

//  print_vector(nums);
//  print_vector(ops);
  return nums.back();
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

  void test(string input) {
    cout << endl;
    cout << input << " = " << calculator(input) << endl;
  }

  void unit_test() {
    test("2*3+5/6*3+15");
    test("");
    test("1+*");
    test("*2");
    test("2^2");
    test("100");
    test("1+1");
    test("2-6-7*8/2+5");
    test("1+2*3-4/5+6-7*2/2*2/2+3*2/2");
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

