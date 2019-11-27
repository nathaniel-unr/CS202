#include "ArrayQueue.h"

int min(int a, int b) {
  if (a > b) {
    return b;
  } else {
    return a;
  }
}

ArrayQueue::ArrayQueue() : m_front(0), m_back(0), m_size(0) {}
ArrayQueue::ArrayQueue(size_t count, const DataType &value)
    : m_front(0), m_back(count - 1), m_size(min(count, ARRAY_MAX)) {
  for (size_t i = 0; i < m_size; i++)
    m_array[i] = value;
}

DataType &ArrayQueue::front() { return m_array[m_front]; }
const DataType &ArrayQueue::front() const { return m_array[m_front]; }
DataType &ArrayQueue::back() { return m_array[m_back]; }
const DataType &ArrayQueue::back() const { return m_array[m_back]; }
void ArrayQueue::push(const DataType &value) {
  if (full())
    return;

  m_back = (m_back + 1) % ARRAY_MAX;
  m_array[m_back] = value;
  m_size++;
}
void ArrayQueue::pop() {
  if (empty())
    return;

  m_front = (m_front + 1) % ARRAY_MAX;
  m_size--;
}

size_t ArrayQueue::size() const { return m_size; }
bool ArrayQueue::empty() const { return m_size == 0; }
bool ArrayQueue::full() const { return m_size == ARRAY_MAX; }

void ArrayQueue::clear() {
  m_front = 0;
  m_back = 0;
  m_size = 0;
}

void ArrayQueue::serialize(std::ostream &os) const {
  for (size_t i = 0; i < m_size; i++)
    os << m_array[(m_front + i) % ARRAY_MAX];
}

std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue) {
  arrayQueue.serialize(os);
  return os;
}
