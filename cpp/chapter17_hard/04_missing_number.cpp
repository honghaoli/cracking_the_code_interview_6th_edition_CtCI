//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * An array A contains all the integers from 0 to n, except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is "fetch the jth bit of A[i]", which takes constant time. Write code to find the missing integer. Can you do it in O(n) time?
 */

/*
 * The book solution argues the above method (including the sum algorithm in 17.19) is ~ O( n log n) since the nbits ~ log n, not fixed, e.g., 32.
 * It provide a  n + n/2 + n/4 + ...  ~ O(n)
 */



#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * This problem is similar to problem 17.19 (hard:  missing two)
 * We could use the same method there,  ~ O( 32 * n) ~ O(n)
 *
 * On the other hand, we could find all the missing bit, and reconstruct the missing integer.
 */
/*
 * From 0 to n, the number of 1s in each bit is
 *        ( ....  bit3, bit2, bit1)
 *  or    ( ....  bit2, bit1, bit0)
 *                       0000:    0
 *                       0001:    1
 *                       0010:    2
 *                       0011:    3
 *                       0100:    4
 *                       0101:    5
 *                       0110:    6
 *                       0111:    7
 *                       1000:    8
 *                       ...
 * start
 *  0     bit1:    (n+1)/2
 *  1     bit2:    (n+1)/4 * 2 + max( (n+1)%4 - 2, 0)
 *  2     bit3:    (n+1)/8 * 4 + max( (n+1)%8 - 4, 0)
 *           .
 *           .
 *           .
 * k-1    bitk:    (n+1) / 2^k * 2^(k-1) + max( (n+1) % 2^k - 2^(k-1), 0)
 */

// the jth bit of A[i]. j starts from 0
bool get_bit(vector<int> &input, int i, int j) {
  int &a = input[i];
  return (a >> j) & 1;
}

int convert_bits_to_int(vector<int> &nbits) {
  int result = 0;
  for (int i = nbits.size() - 1; i >= 0; --i) {
    result <<= 1;
    result |= nbits[i];
  }
  return result;
}

int find_missing(vector<int> &input) {
  const int N_BIT = sizeof(int) * 8;
  const int n = input.size();

  // statistics on number of 1s in each bit
  vector<int> nbits(N_BIT, 0);
  for (int i = 0; i < input.size(); ++i) {
    for (int j = 0; j < N_BIT; ++j) {
      if (get_bit(input, i, j))
        nbits[j]++;
    }
  }

  vector<int> nbits_miss(N_BIT, 0);

  // compare with perfect
  int r = 1;
  for (int k = 0; k < N_BIT - 1; ++k) {
    int num = (n + 1) / (2 * r) * r + max( (n + 1) % (2 * r) - r, 0);
//    cout << num << "  ";
    if (num > nbits[k])
      nbits_miss[k] = 1;
    // exceed max
    if ( (n + 1) < (2 * r) )
      break;
    r *= 2;
  }
//  cout << endl;

//  print_vector(nbits);
//  print_vector(nbits_miss);

  return convert_bits_to_int(nbits_miss);
}





/*
 * The book solution argues the above method (including the sum algorithm in 17.19) is ~ O( n log n) since the nbits ~ log n, not fixed, e.g., 32.
 * It provide a  n + n/2 + n/4 + ...  ~ O(n)
 */


// 2nd method
/*
 * The book solution
 * TODO: to implement it later.
 */



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;


  void test(int N, int miss) {
    printf("\n");
    vector<int> input;
    for (int i = 0; i <= N; ++i) {
      if (i != miss) {
        input.push_back(i);
      }
    }
//    print_vector(input);
    printf("missing %d, calculated %d\n", miss, find_missing(input));
  }

  void unit_test() {
    test(1, 0);
    test(3, 1);
    test(10, 1);
    test(100, 9);
    test(100, 99);
    test(100, 50);
    test(100, 0);
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

