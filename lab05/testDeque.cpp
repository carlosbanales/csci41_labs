#include <iostream>
#include "Deque.h"
#include "testing.h"
#include <type_traits>

using namespace std;

void testDeque1();
void testDeque2();
void testDeque3();

int main() {
  testDeque1();
  testDeque2();
  testDeque3();
  // FΙXМΕ: add 2 more test cases

  return 0;
}

void testDeque1() {
  Deque<int> d;
  bool is_correct = true;

  if (d.size() != 0) is_correct = false;
  d.push_back(5);
  d.push_front(3);
  if (d.size() != 2) is_correct = false;
  if (d.peek_front() != 3) is_correct = false;
  if (d.peek_back() != 5) is_correct = false;
  d.pop_front();
  d.pop_back();
  if (!d.empty()) is_correct = false;

  assertTrue(is_correct, "general Deque<int> operations");
}

void testDeque2() {
  Deque<int> d;
  bool error = false;

  try {
    d.pop_front();
  }
  catch (const std::out_of_range&) {
    error = true;
  }

  assertTrue(error, "Check if pop_front() throws an error when list is empty");
}

void testDeque3() {
  Deque<int> d;
  bool error = false;

  try {
    d.pop_back();
  }
  catch (const std::out_of_range&) {
    error  = true;
  }

  assertTrue(error, "Check if pop_back() throws an error when the list is empty");
}
