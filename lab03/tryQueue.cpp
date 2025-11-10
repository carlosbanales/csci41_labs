#include <iostream>
#include <queue>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/queue/queue/


  // FΙXМΕ: create a queue that holds doubles
  queue<double> q;
  // FΙXМΕ: push 2.4 onto the queue
  q.push(2.4);
  // FΙXМΕ: print the front of the queue
  cout << q.front() << endl;
  // FΙXМΕ: push 7.5 onto the queue
  q.push(7.5);
  // FΙXМΕ: print the front of the queue
  cout << q.front() << endl;
  // FΙXМΕ: push 3.14 onto the queue
  q.push(3.14);
  // FΙXМΕ: print the front of the queue
  cout << q.front() << endl;
  // FΙXМΕ: print the size of the queue
  cout << q.size() << endl;
  // FΙXМΕ: pop the queue
  q.pop();
  // FΙXМΕ: print the front of the queue
  cout << q.front() << endl;
  // FΙXМΕ: print the size of the queue
  cout << q.size() << endl;
  // FΙXМΕ: pop the queue
  q.pop();
  // FΙXМΕ: print the front of the queue
  cout << q.front() << endl;
  // FΙXМΕ: pop the queue
  q.pop();
  // FΙXМΕ: print the size of the queue
  cout << q.size() << endl;


  return 0;
}
