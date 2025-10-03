#include <iostream>
#include "vec.h"
#include "testing.h"
using namespace std;

void testVecCopyConstructor();
void testVecCopyAssignment();
void testEmptyCopy();
void testAssign();
void testOutsideBounds();
void testEmptyVec();

int main() {
  testVecCopyConstructor();
  testVecCopyAssignment();
  testEmptyCopy();
  testAssign();
  testOutsideBounds();
  testEmptyVec();


  // FΙXМΕ: Add 4 more tests

  return 0;
}

void testVecCopyConstructor() {
  Vec v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  Vec v2(v1);
  v1.push_back(4);
  v1.push_back(5);
  v2.push_back(-4);
  v2.push_back(-5);

  assertTrue(v1.at(0) == v2.at(0) &&
             v1.at(1) == v2.at(1) &&
             v1.at(2) == v2.at(2) &&
             v1.at(3) == 4 &&
             v2.at(3) == -4 &&
             v1.at(4) == 5 &&
             v2.at(4) == -5,
             "copy constructor");
}

void testVecCopyAssignment() {
  Vec v1, v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(3);
  v2.push_back(4);

  v2 = v1;

  v2.push_back(5);
  v1.push_back(3);

  assertTrue(v2.at(0) == 1 &&
             v2.at(1) == 2 &&
             v2.at(2) == 5 &&
             v1.at(0) == 1 &&
             v1.at(1) == 2 &&
             v1.at(2) == 3 &&
             v2.size() == 3 &&
             v1.size() == 3,
             "copy assignment operator");
}

void testEmptyVec() {
  Vec v;

  assertTrue(v.size() == 0, "testing empty vector");
}

void testOutsideBounds() {
  Vec v;

  v.push_back(1);
  bool error = false;
  try {
    v.at(5);
  } catch (std::out_of_range&) {
    error = true;
  }

  assertTrue(error, "testing at() outof bounds");
}


void testEmptyCopy() {
  Vec v1;
  Vec v2(v1);

  assertTrue(v2.size() == 0, "testing copy on empty vector");
}

void testAssign() {
  Vec v;

  v.push_back(11);
  v.push_back(22);

  v = v;

  assertTrue(
      v.size() == 2 && v.at(0) == 11 && v.at(1) == 22,
      "Testing assigning object to itself"
      );
}

