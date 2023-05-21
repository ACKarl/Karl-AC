#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath> 

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  

  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};



template <typename T>
Heap<T>::Heap() {}



template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
 
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

 
  int initial_parent_index = floor((values.size() - 1) / 2);
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}



template <typename T>
void Heap<T>::insert(T value) {
  values.push_back(value);  

  int child_index = values.size() - 1;
  int parent_index = floor((child_index - 1) / 2);

  while (child_index > 0 && values[child_index] < values[parent_index]) {
    std::swap(values[child_index], values[parent_index]);
    child_index = parent_index;
    parent_index = floor((child_index - 1) / 2);
  }
}



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



template <typename T>
T Heap<T>::getMin() {
  if (values.empty())
    throw std::runtime_error("Heap is empty");

  return values[0];
}



template <typename T>
void Heap<T>::heapify(int parent_index) {

  if (parent_index < 0 || parent_index >= values.size()) return;


  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;


  int index_of_smallest = parent_index;


  if (left_child_index < values.size() &&
      values[left_child_index] < values[index_of_smallest]) {

index_of_smallest = left_child_index;
}


if (right_child_index < values.size() &&
values[right_child_index] < values[index_of_smallest]) {

index_of_smallest = right_child_index;
}


if (index_of_smallest != parent_index) {
std::swap(values[parent_index], values[index_of_smallest]);


heapify(index_of_smallest);

}
}

#endif
