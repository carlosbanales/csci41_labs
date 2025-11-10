#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/list/list/

  // FΙXМΕ: create a list that holds strings
  list<string> l;
  // FΙXМΕ: push "cat" onto the end of the list
  l.push_back("cat");
  // FΙXМΕ: push "dog" onto the front of the list
  l.push_front("dog");
  // FΙXМΕ: push "bird" onto the end of the list
  l.push_back("bird");
  // FΙXМΕ: push "horse" onto the front of the list
  l.push_front("horse");
  // FΙXМΕ: print the size of the list
  cout << l.size() << endl;
  // FΙXМΕ: iterate through the list from beginning to end (look up
  //        how to use .begin() and .end()) and print out each
  //        element's value

  for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
    cout << *i << endl;
  }

  return 0;
}
