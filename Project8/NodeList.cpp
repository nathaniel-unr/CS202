/**

 * @brief NodeList Implementation
 *
 * @author Nathaniel Daniel
 *
 */
#include "NodeList.h"

/// Default Construtor
NodeList::NodeList() : m_head(NULL) {}
/// Parameterized constructor
NodeList::NodeList(size_t count, const DataType &value) {
  m_head = new Node(value);
  Node *cur = m_head;
  for (size_t i = 1; i < count; i++) {
    cur->m_next = new Node(value);
    cur = cur->m_next;
  }
}
/// Copy constructor
NodeList::NodeList(const NodeList &other) {
  m_head = new Node(*other.m_head);
  for (Node *cur = m_head, *other_cur = other.m_head->m_next; other_cur != NULL;
       other_cur = other_cur->m_next, cur = cur->m_next) {
    cur->m_next = new Node(*other_cur);
  }
}
/// Destructor
NodeList::~NodeList() { clear(); }

/// Assign operator
NodeList &NodeList::operator=(const NodeList &rhs) {
  m_head = new Node(*rhs.m_head);
  for (Node *cur = m_head, *other_cur = rhs.m_head->m_next; other_cur != NULL;
       other_cur = other_cur->m_next, cur = cur->m_next) {
    cur->m_next = new Node(*other_cur);
  }
  return *this;
}

/// Get first element
Node *NodeList::front() { return m_head == NULL ? NULL : m_head; }
/// Get last element
Node *NodeList::back() {
  Node *cur, *prev;
  for (cur = m_head, prev = NULL; cur != NULL; prev = cur, cur = cur->m_next) {
  }
  return prev;
}

/// Find element
Node *NodeList::find(const DataType &target, Node *&previous,
                     const Node *start) {
  previous = NULL;
  Node *cur, *prev;
  for (cur = start == NULL ? m_head : const_cast<Node *>(start), prev = NULL;
       cur != NULL; prev = cur, cur = cur->m_next) {
    if (cur->m_data == target) {
      previous = prev;
      return cur;
    }
  }
  return NULL;
}

/// Insert after element
Node *NodeList::insertAfter(const DataType &target, const DataType &value) {
  Node *prev = NULL;
  Node *node_target = find(target, prev);
  if (node_target == NULL) {
    return NULL;
  }
  Node *new_node = new Node(value);
  new_node->m_next = node_target->m_next;
  node_target->m_next = new_node;
  return new_node;
}

/// Insert before element
Node *NodeList::insertBefore(const DataType &target, const DataType &value) {
  Node *prev = NULL;
  Node *node_target = find(target, prev);
  if (node_target == NULL) {
    return NULL;
  }
  Node *new_node = new Node(value);
  if (prev) {
    new_node->m_next = prev->m_next;
    prev->m_next = new_node;
  } else {
    new_node->m_next = m_head->m_next;
    m_head->m_next = new_node;
  }
  return new_node;
}

/// Erase element
Node *NodeList::erase(const DataType &target) {
  Node *prev = NULL;
  Node *node_target = find(target, prev);
  if (node_target == NULL)
    return NULL;

  Node *ret = NULL;
  if (prev == NULL) {
    m_head = node_target->m_next;
    ret = m_head;
  } else {
    prev->m_next = node_target->m_next;
    ret = prev;
  }
  delete node_target;

  return ret;
}

/// Element access operator
DataType &NodeList::operator[](size_t position) {
  Node *cur = m_head;
  for (size_t i = 0; i < position; i++, cur = cur->m_next) {
  }
  return cur->m_data;
}

/// Const element access operator
const DataType &NodeList::operator[](size_t position) const {
  Node *cur = m_head;
  for (size_t i = 0; i < position; i++, cur = cur->m_next) {
  }
  return cur->m_data;
}

/// Get size
size_t NodeList::size() const {
  size_t count = 0;
  for (Node *cur = m_head; cur != NULL; cur = cur->m_next, count++) {
  }
  return count;
}

/// Checks if empty
bool NodeList::empty() const { return m_head == NULL; }

/// Clears storage
void NodeList::clear() {
  for (Node *next = NULL, *cur = m_head; cur != NULL; cur = next) {
    next = cur->m_next;
    delete cur;
  }
  m_head = NULL;
}

/// Display
std::ostream &operator<<(std::ostream &os, const NodeList &nodeList) {
  for (Node *cur = nodeList.m_head; cur != NULL; cur = cur->m_next) {
    std::cout << cur->data();
  }
  return os;
}