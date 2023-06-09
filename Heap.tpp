#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath> // for floor()

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor((values.size() - 1) / 2);
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
  values.push_back(value);  // Insert value at the end

  int child_index = values.size() - 1;
  int parent_index = floor((child_index - 1) / 2);

  // Fix the heap property by swapping with parents until the correct position is found
  while (child_index > 0 && values[child_index] < values[parent_index]) {
    std::swap(values[child_index], values[parent_index]);
    child_index = parent_index;
    parent_index = floor((child_index - 1) / 2);
  }
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  for (int i = 0; i < values.size(); i++) {
    if (values[i] == value) {
      values[i] = values.back();
      values.pop_back();
      heapify(i);
      break;
    }
  }
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  if (values.empty())
    throw std::runtime_error("Heap is empty");

  return values[0];
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is the smallest value there
  if (left_child_index < values.size() &&
      values[left_child_index] < values[index_of_smallest]) {
// make this index the current smallest
index_of_smallest = left_child_index;
}

// check if right child exists and if exists, is the smallest value there
if (right_child_index < values.size() &&
values[right_child_index] < values[index_of_smallest]) {
// make this index the current smallest
index_of_smallest = right_child_index;
}

// if parent is not the smallest, swap with the smallest child
if (index_of_smallest != parent_index) {
std::swap(values[parent_index], values[index_of_smallest]);

// heapify the swapped index - it may need to move
// further down the 'tree'
heapify(index_of_smallest);

}
}

#endif
