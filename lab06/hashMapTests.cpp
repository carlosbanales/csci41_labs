#include <string>
#include "testing.h"
#include "hashMap.h"
#include <iostream>
using namespace std;

void hashMapTest1();
void hashMapTest2();
void hashMapTest3();
void hashMapTest4();

int main() {
  hashMapTest1();
  hashMapTest2();
  hashMapTest3();
  hashMapTest4();
  // FΙXМΕ: add two more tests

  return 0;
}

void hashMapTest1() {
  HashMap<int, double> table(5);
  bool is_correct = true;

  table.insert(5, 3.14);
  table.insert(6, 5.67);
  if (table.search(5) == nullptr || *table.search(5) != 3.14) is_correct = false;
  if (table.search(6) == nullptr || *table.search(6) != 5.67) is_correct = false;
  if (table.search(10) != nullptr) is_correct = false;

  assertTrue(is_correct, "HashMap<int, double> test");
}

void hashMapTest2() {
  // make sure all the proper hash functions got made
  HashMap<int, int> tInt(42);
  HashMap<char, int> tChar(42);
  HashMap<double, int> tDouble(42);
  HashMap<string, int> tString(42);

  bool is_correct = true;

  // ensure that there will be collisions
  for (int i = 0; i < 128; i++) {
    tInt.insert(i, i+1);
    tChar.insert(static_cast<char>(i), i+1);
    tDouble.insert(static_cast<double>(i), i+1);
    tString.insert(to_string(i), i+1);
  }

  // search for what we inserted
  for (int i = 0; i < 128; i++) {
    if (tInt.search(i) == nullptr || *tInt.search(i) != i+1) is_correct = false;
    if (tChar.search(static_cast<char>(i)) == nullptr || *tChar.search(static_cast<char>(i)) != i+1) is_correct = false;
    if (tDouble.search(static_cast<double>(i)) == nullptr || *tDouble.search(static_cast<double>(i)) != i+1) is_correct = false;
    if (tString.search(to_string(i)) == nullptr || *tString.search(to_string(i)) != i+1) is_correct = false;
  }

  assertTrue(is_correct, "HashMap comprehensive test");
}

void hashMapTest3() {
  HashMap<int, int> table(5);
  bool pass = true;

  table.insert(1, 10);
  table.insert(1, 99);

  int *p = table.search(1);
  if (p == nullptr || *p != 99)
    pass = false;

  assertTrue(pass, "Testing key update");
}

void hashMapTest4() {
  HashMap<string, string> table(10);
  bool pass = true;

  table.insert("bus", "yellow");
  table.insert("barn", "red");

  if (table.search("bus") == nullptr || *table.search("bus") != "yellow")
    pass = false;

  if (table.search("barn") == nullptr || *table.search("barn") != "red")
    pass = false;
  
  if (table.search("water") != nullptr)
    pass = false;

  assertTrue(pass, "Testings strings");
}

