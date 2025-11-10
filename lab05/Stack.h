#ifndef STACK_H
#define STACK_H

#include "Deque.h"

// we'll make a Stack class using our Deque class

template <class T>
class Stack {
public:
  void push(const T& item);
  // for pop, you will also return a copy of the value you pop

  T pop();
  // "peek" means "top"--I think it's a silly name, but we might as well 
  // be consistent with your textbook
  T& peek(); 
  bool empty() const;
  int size() const;
private:
  Deque<T> d;
};

template <class T>
void Stack<T>::push(const T& item) {
  d.push_back(item);
}

template <class T>
T Stack<T>::pop() {
  if (d.empty())
    throw std::underflow_error(" ");
  T value = d.peek_back();
  d.pop_back();
  return value;
}

template <class T>
T& Stack<T>::peek() {
  if (d.empty())
    throw std::underflow_error(" ");
  return d.peek_back();
}

template <class T>
bool Stack<T>::empty() const {
  return d.empty();
}

template <class T>
int Stack<T>::size() const {
  return d.size();
}

// FΙXМΕ: implement the member functions


#endif /* STACK_H */
