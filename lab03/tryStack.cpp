#include <iostream>
#include <stack>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/stack/stack/

  stack<int> s;
  s.push(5);
  cout << s.top() << endl;
  s.push(7);
  cout << s.top() << endl;
  s.push(3);
  cout << s.top() << endl;
  cout << s.size() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s.size() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.size() << endl;


  // FΙXМΕ: create a stack that holds ints
  // FΙXМΕ: push 5 onto the stack
  // FΙXМΕ: print the top of the stack
  // FΙXМΕ: push 7 onto the stack
  // FΙXМΕ: print the top of the stack
  // FΙXМΕ: push 3 onto the stack
  // FΙXМΕ: print the top of the stack
  // FΙXМΕ: print the size of the stack
  // FΙXМΕ: pop the stack
  // FΙXМΕ: print the top of the stack
  // FΙXМΕ: print the size of the stack
  // FΙXМΕ: pop the stack
  // FΙXМΕ: print the top of the stack
  // FΙXМΕ: pop the stack
  // FΙXМΕ: print the size of the stack


  return 0;
}
