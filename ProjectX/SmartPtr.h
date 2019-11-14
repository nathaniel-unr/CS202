#ifndef SMART_PTR_H_
#define SMART_PTR_H_

#include "DataType.h"

class SmartPtr {
public:
  /// Default Constructor
  SmartPtr();
  /// Parametrized Constructor
  SmartPtr(DataType *data);
  /// Copy Constructor
  SmartPtr(const SmartPtr &other);

  /// Destructor
  ~SmartPtr();

  /// Assign Operator
  SmartPtr &operator=(const SmartPtr &rhs);
  /// Dereference operator
  DataType &operator*();
  /// Arrow Operator
  DataType *operator->();

private:
  size_t *m_refcount;
  DataType *m_ptr;
  /// Decrements ref count, deallocates if needed, paramter is wheter this cis
  /// called from a destructor
  void dec_ref(bool is_destructor = false);
  /// Increment Ref Count
  void inc_ref();
  /// Generic private copy constructor
  void from_smart_ptr(const SmartPtr &ptr);
};
#endif