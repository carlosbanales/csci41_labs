#ifndef DEQUE_H
#define DEQUE_H

#include <list>
#include <stdexcept>

// a deque using a std::list

template <class T>
class Deque {
public:
  void push_front(const T& item);
  void push_back(const T& item);
  void pop_front();
  void pop_back();
  T& peek_front(); // gets the front element
  T& peek_back();  // gets the back element
  bool empty() const;
  int size() const;
private:
  std::list<T> l;
};

// FΙXМΕ: implement the member functions (implement them below)
// Remember that we can't use a .cpp file for templates

// here's everything except the body of the push_front function
template <class T>
void Deque<T>::push_front(const T& item) {
  l.push_front(item);
}

template <class T>
void Deque<T>::push_back(const T& item) {
  l.push_back(item);
}

template <class T>
void Deque<T>::pop_front() {
  if (l.empty())
    throw std::out_of_range(" ");
  l.pop_front();
}

template <class T>
void Deque<T>::pop_back() {
  if (l.empty())
    throw std::out_of_range(" ");
  l.pop_back();
}

template <class T>
T& Deque<T>::peek_front() {
  if (l.empty())
    throw std::out_of_range(" ");
  return l.front();
}

template <class T>
T& Deque<T>::peek_back() {
  if (l.empty())
    throw std::out_of_range(" ");
  return l.back();
}

template <class T>
bool Deque<T>::empty() const{
  return l.empty();
}

template <class T>
int Deque<T>::size() const {
  return l.size();
}

// add in the rest



#endif /* DEQUE_H */
