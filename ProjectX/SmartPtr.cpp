#include "SmartPtr.h"

SmartPtr::SmartPtr() {
  m_ptr = new DataType;
  m_refcount = new size_t(1);
  std::cout << "SmartPtr Default Constructor for new allocation, RefCount="
            << *m_refcount << "\n";
}

SmartPtr::SmartPtr(DataType *data) : m_ptr(data) {
  m_refcount = new size_t(data != NULL);
  std::cout << "SmartPtr Parametrized Constructor from data pointer, RefCount="
            << *m_refcount << "\n";
}

SmartPtr::SmartPtr(const SmartPtr &other) {
  from_smart_ptr(other);
  std::cout << "SmartPtr Copy Constructor, RefCount=" << *m_refcount << "\n";
}

SmartPtr::~SmartPtr() { dec_ref(true); }

SmartPtr &SmartPtr::operator=(const SmartPtr &rhs) {
  dec_ref();
  from_smart_ptr(rhs);

  std::cout << "SmartPtr Copy Assignment, RefCount=" << *m_refcount << "\n";
  return *this;
}

DataType &SmartPtr::operator*() { return *m_ptr; }
DataType *SmartPtr::operator->() { return m_ptr; }

void SmartPtr::dec_ref(bool is_destructor) {
  if (m_refcount && *m_refcount != 0)
    (*m_refcount)--;

  if (is_destructor) {
    std::cout << "SmartPtr Destrcutor, RefCount=" << *m_refcount << "\n";
  }

  if (*m_refcount == 0) {
    delete m_refcount;
    delete m_ptr;
  }
}

void SmartPtr::inc_ref() {
  if (m_refcount && *m_refcount != 0)
    (*m_refcount)++;
}

void SmartPtr::from_smart_ptr(const SmartPtr &smart_ptr) {
  m_ptr = smart_ptr.m_ptr;
  if (smart_ptr.m_ptr) {
    m_refcount = smart_ptr.m_refcount;
    (*m_refcount)++;
  } else {
    m_refcount = new size_t(0);
  }
}