//
// Created by Honghao Li on 3/29/17.
//

#include <iostream>
#include <sstream>

using namespace std;


// pixel is 4 bytes, so use int array[N][N]

////////////////////// Solution ////////////////////////

// The 1st method
// rotate change 4 points, (i, j) -> (N-j, i) -> (N-i, N-j) -> (j, N-i) -> (i, j)
void rotate1(int **matrix, int N) {
  if (N == 0)
    return;
  if (sizeof(matrix) / sizeof(int) != N || sizeof(*matrix) / sizeof(int) != N) {
    printf("size of matrix: %d, size of int: %d, N: %d\n", sizeof(matrix), sizeof(int), N);
    throw runtime_error("The input matrix is not N !!!");
  }
  int temp;
  int range = N / 2;   // if N is odd, then all i < (N-1)/2 should rotate, if N is even, the (N-1)/2 needs no rotation.
  for (int i = 0; i < range; ++i) {
    for (int j = 0; j < range; ++j) {
      // rotate 4 points counter-clockwise
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][N-1-i];
      matrix[j][N-1-i] = matrix[N-1-i][N-1-j];
      matrix[N-1-i][N-1-j] = matrix[N-1-j][i];
      matrix[N-1-j][i] = temp;
    }
  }
}


// 2nd method

// 3rd method





////////////////////// Test ////////////////////////
class Test {

 public:

  Test(void (*test_func)(int**, int)) {
    func = test_func;
    basicTests();
  }

 private:
  int num_fail = 0;
  void (*func)(int**, int);

  void basicTests() {
    // customize your own tests here
    const int N = 2;

    int **m1 = new int* [N];
    for (int i = 0; i < N; ++i)
      m1[i] = new int[N];
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    int **m2 = new int* [N];
    for (int i = 0; i < N; ++i)
      m2[i] = new int[N];
    m2[0][0] = 2;
    m2[0][1] = 4;
    m2[1][0] = 1;
    m2[1][1] = 3;

    unitTest(m1, N, m2);

    for (int i = 0; i < N; ++i)
      delete [] m1[i];
    delete m1;
    for (int i = 0; i < N; ++i)
      delete [] m2[i];
    delete m2;
    //
    if (num_fail == 0) {
      printf("Test passed!\n");
    } else {
      printf("\nTotal fail cases: %d\n", num_fail);
    }
  }

  void unitTest(int** m, int N, int** expected) {
    printf("input matrix: %s\n", convertMatrixToString(m, N).c_str());
    func(m, N);
    if (!isMatrixEqual(m, expected, N)) {
      printf("\n========== test failed! ===========\n");
//      printf("input string 1: %s\n", convertMatrixToString(m, N).c_str());
      printf("expected answer: %s\n", convertMatrixToString(expected, N).c_str());
      printf("your answer: %s\n", convertMatrixToString(m, N).c_str());
      printf("===================================\n");
      num_fail++;
    }
  }

  bool isMatrixEqual(int** m1, int** m2, int N) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (m1[i][j] != m2[i][j])
          return false;
      }
    }
    return true;
  }

  string convertMatrixToString(int** m, int N) {
    ostringstream s;
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        s << " ";
        s << m[i][j];
      }
    }
    return s.str();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test(rotate1);  // change the method you want to test here.
  return 0;
}