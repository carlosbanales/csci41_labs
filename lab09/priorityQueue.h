#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>

template <class T>
class PriorityQueue {
 public:
  void push(const T& x);
  T pop();
  const T& peek() const;
  bool isEmpty() const;
  int getLength() const;

 private:
  int leftChildIndex(int index) const;
  int rightChildIndex(int index) const;
  int parentIndex(int index) const;

  // the underlying "array" that holds the heap nodes
  std::vector<T> heapArray;
};

// FΙXМΕ: calculate the left child index, given a node's index
template <class T>
int PriorityQueue<T>::leftChildIndex(int index) const {
  return 2 * index + 1;
}

// FΙXМΕ: calculate the right child index, given a node's index
template <class T>
int PriorityQueue<T>::rightChildIndex(int index) const {
  return 2 * index + 2;
}

// FΙXМΕ: calculate the parent index, given a node's index
template <class T>
int PriorityQueue<T>::parentIndex(int index) const {
  return (index - 1) / 2;
}

// FΙXМΕ: implement the push method to add a new node into the heap

template <class T>
void PriorityQueue<T>::push(const T& x) {
  heapArray.push_back(x);

  int index = static_cast<int>(heapArray.size()) - 1;

  while (index > 0) {
    int pIndex = parentIndex(index);

    if (heapArray[index] < heapArray[pIndex]) {
      T temp = heapArray[index];
      heapArray[index] = heapArray[pIndex];
      heapArray[pIndex] = temp;

      index = pIndex;
    }
    else {
      break;
    }
  }
}

// FΙXМΕ: implement the remove method
// Remove the min element, and also return a copy of it
template <class T>
T PriorityQueue<T>::pop() {
  // replace the root with the bottommost, rightmost node
  // we will return the node you just "popped" at the very end of this method
  if (heapArray.size() == 1) {
    T result = heapArray[0];
    heapArray.pop_back();
    return result;
  }

  T result = heapArray[0];
  heapArray[0] = heapArray.back();

  // remove the bottommost, rightmost node
  heapArray.pop_back();

  // bubble the new root down to where it needs to be
  int index = 0;
  int size = static_cast<int>(heapArray.size());

  while (true) {
    int left = leftChildIndex(index);
    int right = rightChildIndex(index);
    int smallest = index;

    if (left < size && heapArray[left] < heapArray[smallest]) {
      smallest = left;
    }
    if (right < size && heapArray[right] < heapArray[smallest]) {
      smallest = right;
    }

    if (smallest == index) {
      break;
    }

    T temp = heapArray[index];
    heapArray[index] = heapArray[smallest];
    heapArray[smallest] = temp;

    index = smallest;
  }

  // return a copy of the value you removed
  return result;
}

// FΙXМΕ: implement the peek method to return a reference to the current min
template <class T>
const T& PriorityQueue<T>::peek() const {
  return heapArray[0];
}

// FΙXМΕ: implement the isEmpty method to return whether the heap is empty
template <class T>
bool PriorityQueue<T>::isEmpty() const {
  return heapArray.empty();
}

// FΙXМΕ: implement the getLength method to get the size of the heap
template <class T>
int PriorityQueue<T>::getLength() const {
  return static_cast<int>(heapArray.size());
}

// The following is not a method--you'll *use* the PriorityQueue class
// FΙXМΕ: sort the input vector (from smallest to biggest) using a
// PriorityQueue<T>
template <class T>
std::vector<T> heapSort(const std::vector<T>& v) {
  PriorityQueue<T> pq;

  // push all elements inn the heap
  for (const T& item : v) {
    pq.push(item);
  }

  // pop them out in sorted order
  std::vector<T> result;
  result.reserve(v.size());

  while (!pq.isEmpty()) {
    result.push_back(pq.pop());
  }

  return result;
}

#endif /* HEAP_H */
