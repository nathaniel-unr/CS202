/**

 * @brief Arraylist Implementation
 *
 * @author Nathaniel Daniel
 *
 */

#include "ArrayList.h"
/// Default constructor
ArrayList::ArrayList() : m_array(NULL), m_size(0), m_maxsize(0) {}

/// Parameterized constructor
ArrayList::ArrayList(size_t count, const DataType &value)
    : m_size(count), m_maxsize(count) {
  m_array = new DataType[count];
  for (size_t i = 0; i < count; i++)
    m_array[i] = value;
}

/// Copy constructor
ArrayList::ArrayList(const ArrayList &other)
    : m_size(other.m_size), m_maxsize(other.m_maxsize) {
  m_array = new DataType[m_maxsize];
  for (size_t i = 0; i < m_size; i++)
    m_array[i] = other.m_array[i];
}

/// Destructor
ArrayList::~ArrayList() {
  if (m_array)
    delete m_array;
}

/// Assign operator
ArrayList &ArrayList::operator=(const ArrayList &rhs) {
  if (m_array)
    delete m_array;
  m_size = rhs.m_size;
  m_maxsize = rhs.m_maxsize;
  m_array = new DataType[m_maxsize];
  for (size_t i = 0; i < m_size; i++)
    m_array[i] = rhs.m_array[i];
  return *this;
}

/// Get first element
DataType *ArrayList::front() { return m_array == NULL ? NULL : &m_array[0]; }

/// Get last element
DataType *ArrayList::back() {
  return m_array == NULL ? NULL : &m_array[m_size - 1];
}

/// Find element
DataType *ArrayList::find(const DataType &target, DataType *&previous,
                          const DataType *start) {
  if (m_array == NULL) {
    previous = NULL;
    return NULL;
  }
  DataType *base = start == NULL ? &m_array[0] : const_cast<DataType *>(start);
  for (size_t i = 0; i < m_size; i++) {
    if (base[i] == target) {
      if (i > 1) {
        previous = &base[i - 1];
      }
      return &base[i];
    }
  }

  previous = NULL;
  return NULL;
}

/// Insert after element
DataType *ArrayList::insertAfter(const DataType &target,
                                 const DataType &value) {
  resize(m_size + 1);
  DataType *prev_node = NULL;
  DataType *node = find(target, prev_node);
  DataType *start = this->front();
  DataType *back = this->back();
  if (node == NULL || back == NULL || start == NULL)
    return NULL;

  DataType swap_in = value;
  for (int i = 1; &node[i] <= back + 1; i++) {
    DataType temp = node[i];
    node[i] = swap_in;
    swap_in = temp;
  }
  m_size++;
  return node + 1;
}

/// Insert before element
DataType *ArrayList::insertBefore(const DataType &target,
                                  const DataType &value) {
  resize(m_size + 1);
  DataType *prev_node = NULL;
  DataType *node = find(target, prev_node);
  DataType *start = this->front();
  DataType *back = this->back();
  if (node == NULL || back == NULL || start == NULL)
    return NULL;

  DataType swap_in = value;
  for (int i = 0; &node[i] <= back; i++) {
    DataType temp = node[i];
    node[i] = swap_in;
    swap_in = temp;
  }
  m_size++;
  return node;
}

/// Erase element
DataType *ArrayList::erase(const DataType &target) {
  DataType *prev_node = NULL;
  DataType *node = find(target, prev_node);
  DataType *start = this->front();
  DataType *back = this->back();
  if (node == NULL || back == NULL || start == NULL)
    return NULL;

  for (int i = 0; &node[i] < back; i++) {
    node[i] = node[i + 1];
  };
  m_size--;

  if (back == node) {
    return NULL;
  } else {
    return node;
  }
}

/// Array Access operator
DataType &ArrayList::operator[](size_t position) { return m_array[position]; }
/// Get size
size_t ArrayList::size() const { return m_size; }
/// Checks if empty
bool ArrayList::empty() const { return m_size == 0; }
/// Clears Array
void ArrayList::clear() { m_size = 0; }

/// Reallocs storage
void ArrayList::resize(size_t count) {
  DataType *new_arr = new DataType[count];

  size_t copy_num = count > m_size ? m_size : count;
  for (size_t i = 0; i < copy_num; i++)
    new_arr[i] = m_array[i];

  m_size = copy_num;
  m_maxsize = count;
  delete m_array;
  m_array = new_arr;
}

/// Display
std::ostream &operator<<(std::ostream &os, const ArrayList &arrayList) {
  for (size_t i = 0; i < arrayList.size(); i++)
    os << arrayList.m_array[i];
  return os;
}