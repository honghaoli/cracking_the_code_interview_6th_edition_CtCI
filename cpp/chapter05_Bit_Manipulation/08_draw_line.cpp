//
// Created by Honghao Li on 5/28/17.
//

// PROBLEM
// A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (x1, y) to (x2, y).
// The method signature should look something like:
// drawLine(byte[] screen, int width, int x1, int x2, int y)



#include <cstdio>
#include <iostream>
#include <bitset>
#include <limits>
#include <iomanip>
#include <vector>

using namespace std;


//////////////////////// Solutions ///////////////////////////////

// 1st method
// Assume the screen (0, 0) is at left top corner, x and y start from 0.
// Assume draw new line does not erase the screen.
// assume x1 and x2 are both included
typedef unsigned char byte;
const int BYTE = sizeof(byte);
void draw_line(vector<byte> &screen, int width, int x1, int x2, int y) {
  if (width % BYTE != 0)
    throw "Width is not divisible by 8!!!\n";
  if (x1 > x2 || x1 >= width || x2 >= width)
    throw "Incorrect parameters!!!\n";
  //
  int char_start = x1 / BYTE + y * (width / BYTE);
  int byte_start = x1 % BYTE;
  int char_end = x2 / BYTE + y * (width / BYTE);
  int byte_end = x2 % BYTE;
  // start byte
  byte mask_start = ~((1 << byte_start) - 1);  // like 00001111
  screen[char_start] |= mask_start;   // OR allows previous content not erased
  // end byte
  byte mask_end = ~(1 << (byte_end + 1));  // like 1111000
  screen[char_end] |= mask_end;   // OR allows previous content not erased
  // middle bytes
  for (int i = char_start + 1; i < char_end; ++i) {
    screen[i] = 0b11111111;   // fill full    // or use 0xFF as in the book
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

  void draw_screen(vector<byte> &screen, int width) {
    for (int i = 0; i < screen.size(); ++i) {
      if (i % (width / BYTE) == 0)  // change line
        cout << endl;
      cout << bitset<BYTE>(screen[i]);
    }
  }
  void test_blank() {
    vector<byte> screen;
    int width = 32;
    int height = 5;
    for (int i = 0; i < width / BYTE * height; ++i) {
      screen.push_back(byte(0b00000000));
    }
    draw_screen(screen, width);
  }

  void test(int x1, int x2, int y) {
    printf("\n\ntest x1 = %d, x2 = %d, y = %d", x1, x2, y);
    vector<byte> screen;
    int width = 32;
    int height = 5;
    for (int i = 0; i < width / BYTE * height; ++i) {
      screen.push_back(byte(0b00000000));
    }
    draw_line(screen, width, x1, x2, y);
    draw_screen(screen, width);
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    printf("size of unsigned char: %d\n", sizeof(unsigned char));
    // customize your own tests here

    // blank
    test_blank();
    //
    test(0, 0, 0);
    test(0, 31, 0);
    test(31, 31, 0);
    test(3, 12, 0);
    test(9, 30, 4);
    test(9, 10, 2);


  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

