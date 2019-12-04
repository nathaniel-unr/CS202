#ifndef NODESTACK_H_
#define NODESTACK_H_
template <typename T> class Node {
  template <typename U> friend class NodeStack;

public:
  Node() : m_next(NULL) {}

  Node(const T &data, Node<T> *next = NULL) : m_next(next) { m_data = data; }
  T &data() { return m_data; }
  const T &data() const { return m_data; }

private:
  Node *m_next;
  T m_data;
};

template <typename T> class NodeStack {
  template <typename U>
  friend std::ostream &operator<<(std::ostream &os,
                                  const NodeStack<U> &nodeStack) {
    nodeStack.serialize(os);
    return os;
  }

public:
  NodeStack() : m_top(NULL) {}
  NodeStack(size_t count, const T &value) : m_top(NULL) {
    for (size_t i = 0; i < count; i++)
      push(value);
  }
  NodeStack(const NodeStack &other) : m_top(NULL) {
    if (other.m_top) {
      Node<T> *new_cur = new Node<T>(other.m_top->m_data);
      m_top = new_cur;
      for (Node<T> *cur = other.m_top->m_next; cur != NULL;
           cur = cur->m_next, new_cur = new_cur->m_next) {
        new_cur->m_next = new Node<T>(cur->m_data);
      }
    }
  }

  ~NodeStack() {
    while (m_top != NULL)
      pop();
  }

  NodeStack &operator=(const NodeStack &rhs) {
    clear();
    if (rhs.m_top) {
      Node<T> *new_cur = new Node<T>(rhs.m_top->m_data);
      m_top = new_cur;
      for (Node<T> *cur = rhs.m_top->m_next; cur != NULL;
           cur = cur->m_next, new_cur = new_cur->m_next) {
        new_cur->m_next = new Node<T>(cur->m_data);
      }
    }
    return *this;
  }

  T &top() { return m_top->data(); }
  const T &top() const { return m_top->data(); }

  void push(const T &value) {
    if (m_top != NULL) {
      Node<T> *old_top = m_top;
      m_top = new Node<T>(value);
      m_top->m_next = old_top;
    } else {
      m_top = new Node<T>(value);
    }
  }

  void pop() {
    if (m_top) {
      Node<T> *old = m_top;
      m_top = m_top->m_next;
      delete old;
    }
  }

  size_t size() const {
    size_t count = 0;
    for (Node<T> *cur = m_top; cur != NULL; cur = cur->m_next)
      count++;
    return count;
  }
  bool empty() const { return m_top == NULL; }
  bool full() const { return false; }

  void clear() {
    while (!empty())
      pop();
  }

  void serialize(std::ostream &os) const {
    for (Node<T> *cur = m_top; cur != NULL; cur = cur->m_next)
      os << cur->m_data;
  }

private:
  Node<T> *m_top;
};
#endif