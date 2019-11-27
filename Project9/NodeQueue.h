#ifndef _NODE_QUEUE_H_
#define _NODE_QUEUE_H_
#include "DataType.h"
#include <iostream>

// Forward declaration
class NodeQueue;

/// Liinked List Node
class Node {
  friend class NodeQueue;
  friend std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue);

public:
  /// Default Constructor
  Node() : m_next(NULL) {}
  /// Parameterized Constructor
  Node(const DataType &data, Node *next = NULL) : m_next(next), m_data(data) {}
  /// Copy constructor
  Node(const Node &other) : m_next(other.m_next), m_data(other.m_data) {}

  /// Data
  DataType &data() { return m_data; }
  /// const data
  const DataType &data() const { return m_data; }

private:
  Node *m_next;
  DataType m_data;
};

/// Linked list backed queue
class NodeQueue {
  /// Stream
  friend std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue);

public:
  /// Default constructor
  NodeQueue();
  /// Parameterized Constructor
  NodeQueue(size_t size, const DataType &value);
  /// Copy Constructor
  NodeQueue(const NodeQueue &other);
  /// Destructor
  ~NodeQueue();
  /// Assign Operator
  NodeQueue &operator=(const NodeQueue &rhs);
  /// Get front element
  DataType &front();
  /// Get const front element
  const DataType &front() const;
  /// Get back element
  DataType &back();
  /// Const back element
  const DataType &back() const;
  /// Push data to back
  void push(const DataType &value);
  /// Pop data from front
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
  Node *m_front;
  Node *m_back;
};
#endif