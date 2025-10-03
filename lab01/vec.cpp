#include "vec.h"
#include <stdexcept>
#include <algorithm>

Vec::Vec() {
  numItems = 0;
  capacity = 1;
  arr = new int[capacity];

    // FΙXМΕ: implement this method
  // make arr a size 1 array to start with
  // so, capacity is 1 because the array can hold 1 thing
  // there's nothing in the Vec yet so the numItems is 0
}

// doubles the array capacity
void Vec::resize() {
  int newCapacity = capacity * 2;
  capacity = capacity * 2;
  int *newArr = new int[newCapacity];

  std::copy(arr, arr + numItems, newArr);
  delete[] arr;
  arr = newArr;
  capacity = newCapacity;


  // FΙXМΕ: implement this method

  // Double the current capacity. This means we need to make a new
  // array on the heap and copy all the existing stuff into it.

  // remember to delete[] the old array and increase the capacity
  // memeber variable appropriately!
}

void Vec::push_back(int x) {
  if (numItems >= capacity) {
    resize();
  }
  arr[numItems] = x;
  numItems++;

  // FΙXМΕ: implement this method
  // If we have enough space, just add to the next available location.
  // If not, use the resize function to double the space and then add 
  // to the next available location.
}

// return the number of items in the Vec
int Vec::size() const {
  // FΙXМΕ: implement this method
  return numItems;
}

// return the element at index i
// (it's a reference so that it can potentially be changed)
int& Vec::at(int i) {
  // FΙXМΕ: implement this method
  if (i < 0 || i >= numItems)
    throw std::out_of_range("");
  return arr[i];
}

void Vec::sort() {
  std::sort(arr, arr + numItems);
}
