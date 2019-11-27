#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

#include "DataType.h"
#include <iostream>

/// Max Array size
const size_t ARRAY_MAX = 1000;

/// Array based queue
class ArrayQueue {
  /// Stream operator
  friend std::ostream &operator<<(std::ostream &os,
                                  const ArrayQueue &arrayQueue);

public:
  /// Default constructor
  ArrayQueue();
  /// Parameterized constructor
  ArrayQueue(size_t count, const DataType &value);
  /// Assign operator
  ArrayQueue &operator=(const ArrayQueue &rhs);
  /// Front element
  DataType &front();
  /// Const front element
  const DataType &front() const;
  /// Back element
  DataType &back();
  /// Const back element
  const DataType &back() const;
  /// Push element at back of queue
  void push(const DataType &value);
  /// Remove elemnt from front
  void pop();
  /// Get size
  size_t size() const;
  /// Checks if empty
  bool empty() const;
  /// Checks if full
  bool full() const;
  /// Empties array
  void clear();
  /// Serializes data
  void serialize(std::ostream &os) const;

private:
  DataType m_array[ARRAY_MAX];
  size_t m_front;
  size_t m_back;
  size_t m_size;
};
#endif