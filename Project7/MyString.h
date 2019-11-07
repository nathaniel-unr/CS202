#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

class MyString {
public:
  /// Default Constructor, sets up empty string. Does not allocate.
  MyString();
  /// Parameterized Constructor for cstring. Copies to buffer.
  MyString(const char *str);
  /// Copy Constructor. Copies value of other
  MyString(const MyString &other);
  /// Destructor, deallocates buffer
  ~MyString();
  /// Returns the size of the buffer, with the nul terminator
  size_t size() const;
  /// Returns the size of the buffer, without the nul terminator
  size_t length() const;
  /// Returns the cstring representation of the string
  const char *c_str() const;
  /// Equality overload
  bool operator==(const MyString &other) const;
  /// Assignment overload. copies the value of one string to the other. Both
  /// strings remain valid.
  MyString &operator=(const MyString &other);
  /// Addition Overload, concatenates the buffer of 2 strings
  MyString operator+(const MyString &other_myStr) const;
  /// mutable index
  char &operator[](size_t index);
  /// immuatble index
  const char &operator[](size_t index) const;
  /// write string to stream
  friend std::ostream &operator<<(std::ostream &os, const MyString &myStr);

private:
  /// Deallcoates buffer
  void buffer_deallocate();
  /// Allocates buffer
  void buffer_allocate(size_t size);
  char *m_buffer;
  size_t m_size;
};
#endif