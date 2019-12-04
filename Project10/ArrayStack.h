#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
#include <iostream>
const size_t MAX_STACKSIZE = 1000;

template <typename T> class ArrayStack {
  template <typename U>
  friend std::ostream &operator<<(std::ostream &os,
                                  const ArrayStack<U> &arrayStack) {
    arrayStack.serialize(os);
    return os;
  }

public:
  ArrayStack() : m_top(0) {}
  ArrayStack(size_t count, const T &value) : m_top(count) {
    for (size_t i = 0; i < m_top; i++)
      m_container[i] = value;
  }
  ArrayStack(const ArrayStack &other) : m_top(other.m_top) {
    for (size_t i = 0; i < m_top; i++)
      m_container[i] = other.m_container[i];
  }
  ~ArrayStack() {}
  ArrayStack &operator=(const ArrayStack &rhs) {
    m_top = rhs.m_top;
    for (size_t i = 0; i < rhs; i++)
      m_container[i] = m_container[i];
  }
  T &top() { return m_container[m_top - 1]; }
  const T &top() const { return m_container[m_top - 1]; }
  void push(const T &value) {
    m_container[m_top] = value;
    m_top++;
  }
  void pop() { m_top--; }
  size_t size() const { return m_top; }
  bool empty() const { return m_top == 0; }
  bool full() const { return m_top == MAX_STACKSIZE; }
  void clear() { m_top = 0; }
  void serialize(std::ostream &os) const {
    for (size_t i = m_top; i > 1; i--)
      os << m_container[i - 1];
  }

private:
  T m_container[MAX_STACKSIZE];
  size_t m_top;
};
#endif