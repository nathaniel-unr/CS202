#ifndef VECTOR_RECURSION_H_
#define VECTOR_RECURSION_H_
#include <iostream>
#include <vector>

template <typename T> void vector_resort(std::vector<T> &list, size_t end) {
  if (end == 1)
    return;
  for (size_t i = 0; i < end - 1; i++) {
    if (list[i] > list[i + 1]) {
      T temp = list[i];
      list[i] = list[i + 1];
      list[i + 1] = temp;
    }
  }
  vector_resort(list, end - 1);
}

template <typename T>
typename std::vector<T>::iterator
vector_research(std::vector<T> &list, const T &target,
                typename std::vector<T>::iterator start,
                typename std::vector<T>::iterator end) {
  if (start + 1 == end || start == end) {
    if (*start == target) {
      return start;
    } else {
      return list.end();
    }
  }

  typename std::vector<T>::iterator mid = start + ((end - start) / 2);
  if (target >= *mid) {
    return vector_research(list, target, mid, end);
  } else {
    return vector_research(list, target, start, mid);
  }
}
#endif