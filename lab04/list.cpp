#include "list.h"

List::List() {
  // FΙXМΕ: implement the constructor
  // make list initially empty
  first = nullptr;
  last = nullptr;
}

// FΙXМΕ: implement List's getFirst method to get the first element
const Node* List::getFirst() {
  return first;
}
// FΙXМΕ: implement List's getLast method to get the last element
const Node* List::getLast() {
  return last;
}

void List::push_front(Point2D data) {
  // FΙXМΕ: implement this method to add a new Node at the front of the list
  // Watch out for the special case when the list is initially empty!
  Node* node = new Node{data, first};
  first = node;

  if (last == nullptr)
    last = node;
}

void List::push_back(Point2D data) {
  // FΙXМΕ: implement this method to add a new Node at the end of the list
  // Watch out for the special case when the list is initially empty!
  Node* node = new Node{data, nullptr};
  if (first == nullptr) {
    first = node;
    last = node;
  }
  else {
    last->next = node;
    last = node;
  }
}

void List::pop_front() {
  // FΙXМΕ: implement this method to remove the Node at the front of the list
  // Watch out for the case where you remove the only Node in the list!
  if (first == nullptr)
    return;

  Node* del = first->next;
  delete first;
  first = del;

  if (first == nullptr)
    last = nullptr;
}

void List::pop_back() {
  // FΙXМΕ: implement this method to remove the Node at the back of the list
  // Watch out for the case where you remove the only Node in the list!
  if (first == nullptr)
    return;

  if (first == last) {
    delete first;
    first = nullptr;
    last = nullptr;
    return;
  }
  
  Node* prev = first;
  while (prev->next != last) {
    prev = prev->next;
  }

  delete last;
  last = prev;
  last->next = nullptr;
}

int List::size() {
  // FΙXМΕ: implement this method to return the number of Nodes in the list
  int len = 0;

  for (Node* curr = first; curr != nullptr; curr = curr->next)
    len++;

  return len;
}

List::~List() {
  // FΙXМΕ: implement the destructor--it should delete every Node in the list
  while (first != nullptr) {
    Node* after = first->next;
    delete first;
    first = after;
  }
  last = nullptr;
}

List& List::operator=(const List& other) {
  // FΙXМΕ: implement the copy assignment operator
  if (this == &other)
    return *this;

   while (first != nullptr) {
    Node* after = first->next;
    delete first;
    first = after;
  }
  last = nullptr;

  for (const Node* curr = other.first; curr != nullptr; curr = curr->next)
    this->push_back(curr->data);

  return *this;
}


List::List(const List& other) {
  // FΙXМΕ: implement the copy constructor
  first = nullptr;
  last = nullptr;

  for (const Node* curr = other.first; curr != nullptr; curr = curr->next)
    this->push_back(curr->data);
}
