#include <iostream>
#include "vec.h"
#include "testing.h"
using namespace std;

void testVec1();
void testVec2();
void testVec3();
void testVec4();
void testVec5();
void testVec6();
void testVec7();
void testVec8();

int main() {
  testVec1();
  testVec2();
  testVec3();
  testVec4();
  testVec5();
  testVec6();
  testVec7();
  testVec8();

  // FΙXМΕ: Add 4 more tests
  // That is, call assertTrue EXACTLY 4 more times

  return 0;
}

void testVec1() {
  Vec v;
  assertTrue(v.size() == 0, "empty Vec");
}

void testVec2() {
  Vec v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  assertTrue(v.size() == 3 &&
             v.at(0) == 3 &&
             v.at(1) == 2 &&
             v.at(2) == 1,
             "Vec {3, 2, 1}");
}

void testVec3() {
  Vec v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.sort();
  assertTrue(v.size() == 3 &&
             v.at(0) == 1 &&
             v.at(1) == 2 &&
             v.at(2) == 3,
             "Sorting Vec {3, 2, 1}");
}

void testVec4() {
  Vec v;

  // insert 32 to 0
  for (int i = 32; i >= 0; i--) {
    v.push_back(i);
  }

  // sort
  v.sort();

  // check correctly sorted and that all the elements exist where they
  // should
  bool is_correct = true;
  if (v.size() != 33)
    is_correct = false;
  for (int i = 0; i <= 32; i++) {
    if (v.at(i) != i)
      is_correct = false;
  }

  // check modifiability using .at()
  v.at(2)++;
  if (v.at(2) != 3)
    is_correct = false;

  assertTrue(is_correct, "comprehensive large Vec test");
}

void testVec5() {
  Vec v;

  v.push_back(2);
  v.push_back(4);
  v.push_back(6);

  bool error = false;
  try {
    v.at(3);
  }
  catch(std::out_of_range&) {
    error = true;  
  }

  assertTrue(error, "Checking out of bounds");
}

void testVec6() {
  Vec v;
  v.push_back(7);
  bool error = false;
  try {
    v.at(-1);
  }
  catch(std::out_of_range&) {
    error = true;
  }
  assertTrue(error, "Checking Negative index");
}

void testVec7() {
    Vec v;

    v.push_back(-2);
    v.push_back(0);
    v.push_back(2);
    v.sort();

    bool correct = v.at(0) == -2 && v.at(1) == 0 && v.at(2) == 2;
    
    assertTrue(correct, "Sorting with neg ints");
}

void testVec8() {
    Vec v;

    for(int i = 0; i < 5; i++)
      v.push_back(i);

    v.sort();
    bool sorted = true;
    for(int i = 0; i < 5; i++) {
        if(v.at(i) != i)
          sorted = false;
    }

    assertTrue(sorted, "Checking vec thats alreday sorted");
}

