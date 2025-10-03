#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "box.h"

void assertTrue(bool b, string description) {
  if (!b) {
    cout << "FAILED: " + description << endl;
  } else {
    cout << "PASSED: " + description << endl;
  }
}

void runBoxTestEmpty();
void runBoxTestSize1();
void runBoxTestSize3();
void runBoxTestSetBoxChar();
void runBoxTestIncDec();
void runBoxTestNegSize();
void runBoxTestSize20();
void runBoxTestSize100();
void runBoxTestNegOffset();
void runBoxTestMultipleOffsets();
//void runBoxTest

int main() {
  runBoxTestEmpty();
  runBoxTestSize1();
  runBoxTestSize3();
  runBoxTestSetBoxChar();
  runBoxTestIncDec();
  runBoxTestSize20();
  runBoxTestSize100();
  runBoxTestNegSize();
  runBoxTestNegOffset();
  runBoxTestMultipleOffsets();
  // FΙXМΕ: implement 6 more tests
  // That is, call assertTrue EXACTLY 6 more times

  return 0;
}

void runBoxTestMultipleOffsets() {
  Box b(1);
  b += 3;
  b -= 2;
  b += 1;
  assertTrue(b.getWidth() == 3, "Multiple offsets");
}

void runBoxTestNegOffset() {
  Box b(5, '#');
  b += -3;
  assertTrue(b.getWidth() == 2, "Increase by Neg");
  b -= -4;
  assertTrue(b.getWidth() == 6, "Decrease by Neg");
}

void runBoxTestSize100() {
  Box b(100, '$');
  stringstream ss;
  ss << b;

  string referenceRow(100, '$');
  string reference = "";
  for (int i = 0; i < 100; i++) {
    reference += referenceRow + '\n';
  }

  assertTrue(b.getWidth() == 100 && b.getBoxChar() == '$' && ss.str() == reference,
              "Size 100 box");
}

void runBoxTestSize20() {
  Box b(20, '$');
  stringstream ss;
  ss << b;

  string referenceRow(20, '$');
  string reference = "";
  for (int i = 0; i < 20; i++) {
    reference += referenceRow + '\n';
  }

  assertTrue(b.getWidth() == 20 && b.getBoxChar() == '$' && ss.str() == reference,
              "Size 20 box");
}

void runBoxTestNegSize() {
  Box b(-1, '*');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 0 && b.getBoxChar() == '*' && ss.str() == "",
              "Neg Number"); 
}

void runBoxTestEmpty() {
  Box b;
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 0 && b.getBoxChar() == '*' && ss.str() == "",
              "empty box");
}

void runBoxTestSize1() {
  Box b(1, '$');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 1 && b.getBoxChar() == '$' && ss.str() == "$\n",
             "size 1 box");
}

void runBoxTestSize3() {
  Box b(3, '%');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 3 && b.getBoxChar() == '%' &&
                 ss.str() == "%%%\n%%%\n%%%\n",
             "size 3 box");
}

void runBoxTestSetBoxChar() {
  Box b(1, '$');
  b.setBoxChar('%');
  stringstream ss;
  ss << b;
  assertTrue(b.getWidth() == 1 && b.getBoxChar() == '%' && ss.str() == "%\n",
             "setBoxChar");
}

void runBoxTestIncDec() {
  Box b(1);
  bool isCorrect = true;
  // try to make the width 3
  b += 2;
  isCorrect = isCorrect && b.getWidth() == 3;
  stringstream ss;
  ss << b;
  isCorrect = isCorrect && ss.str() == "***\n***\n***\n";
  // clear out ss
  ss.str("");
  ss.clear();
  // try to make the width 1 again
  b -= 2;
  isCorrect = isCorrect && b.getWidth() == 1;
  ss << b;
  isCorrect = isCorrect && ss.str() == "*\n";
  assertTrue(isCorrect, "inc/dec");
}
