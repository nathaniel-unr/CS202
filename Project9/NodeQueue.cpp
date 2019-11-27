#include "NodeQueue.h"

NodeQueue::NodeQueue() : m_front(NULL), m_back(NULL) {}
NodeQueue::NodeQueue(size_t size, const DataType &value) {
  m_front = new Node(value);

  Node *last = m_front;
  for (size_t i = 1; i < size; i++) {
    last->m_next = new Node(value);
    last = last->m_next;
  }
  m_back = last;
}

NodeQueue::NodeQueue(const NodeQueue &other) {
  if (other.m_front == NULL) {
    m_front = NULL;
    m_back = NULL;
  }

  m_front = new Node(*other.m_front);
  Node *cur = m_front;
  for (Node *other_cur = other.m_front->m_next; other_cur != NULL;
       other_cur = other_cur->m_next, cur = cur->m_next) {
    cur->m_next = new Node(*other_cur);
  }
  m_back = cur;
}

NodeQueue::~NodeQueue() { clear(); }

NodeQueue &NodeQueue::operator=(const NodeQueue &rhs) {
  clear();

  if (rhs.m_front == NULL) {
    m_front = NULL;
    m_back = NULL;
  }

  m_front = new Node(*rhs.m_front);
  for (Node *cur = m_front, *other_cur = rhs.m_front->m_next; other_cur != NULL;
       other_cur = other_cur->m_next, cur = cur->m_next) {
    cur->m_next = new Node(*other_cur);
  }

  return *this;
}

DataType &NodeQueue::front() { return m_front->data(); }
const DataType &NodeQueue::front() const { return m_front->data(); }
DataType &NodeQueue::back() { return m_back->data(); }
const DataType &NodeQueue::back() const { return m_back->data(); }

void NodeQueue::push(const DataType &value) {
  Node *new_node = new Node(value);
  if (m_back == NULL) {
    m_back = new_node;
    m_front = new_node;
  } else {
    m_back->m_next = new_node;
    m_back = new_node;
  }
}

void NodeQueue::pop() {
  if (m_front) {
    Node *next = m_front->m_next;
    delete m_front;
    m_front = next;
    if (m_front == NULL)
      m_back = NULL;
  }
}

size_t NodeQueue::size() const {
  size_t count = 0;
  for (Node *m_cur = m_front; m_cur != NULL; m_cur = m_cur->m_next)
    count++;
  return count;
}

bool NodeQueue::empty() const { return size() == 0; }
bool NodeQueue::full() const { return false; }

void NodeQueue::clear() {
  for (Node *next, *m_cur = m_front; m_cur != NULL; m_cur = next) {
    next = m_cur->m_next;
    delete m_cur;
  }
  m_front = NULL;
  m_back = NULL;
}

void NodeQueue::serialize(std::ostream &os) const {
  for (Node *m_cur = m_front; m_cur != NULL; m_cur = m_cur->m_next)
    os << m_cur->data();
}

std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue) {
  nodeQueue.serialize(os);
  return os;
}