#include <iostream>
#include <queue>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/queue/priority_queue/

  //  Another name for a priority queue is a "heap"
    
  // FΙXМΕ: create a priority queue that holds ints
  priority_queue<int> heap;
  // FΙXМΕ: push {1, -2, 3, -4, ..., 49, -50} onto the priority queue,
  // in that order

  for (int i = 1; i < 51; i++) {
    if ((i % 2) == 0)
      heap.push(-i);
    else
      heap.push(i);
  }
  // FΙXМΕ: in a loop, do the following while the priority queue isn't
  //        empty:
  //          1. print the top of the priority queue
  //          2. pop the priority queue
  
  while (!heap.empty()) {
    cout << heap.top() << endl;
    heap.pop();
  }

  return 0;
}
