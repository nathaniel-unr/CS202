#include "MyString.h"
#include <cstring>

MyString::MyString() : m_buffer(NULL), m_size(0) {}

MyString::MyString(const char *str) : m_buffer(NULL), m_size(0) {
  buffer_allocate(strlen(str) + 1);
  strcpy(m_buffer, str);
  m_buffer[m_size - 1] = 0;
}

MyString::MyString(const MyString &other) : m_buffer(NULL), m_size(0) {
  buffer_allocate(other.m_size);
  for (size_t i = 0; i < m_size; i++)
    m_buffer[i] = other.m_buffer[i];
}

MyString::~MyString() { buffer_deallocate(); }

size_t MyString::size() const { return m_size; }

size_t MyString::length() const { return m_size - 1; }

const char *MyString::c_str() const { return m_buffer; }

bool MyString::operator==(const MyString &other) const {
  return strcmp(m_buffer, other.m_buffer) == 0;
}

MyString &MyString::operator=(const MyString &other) {
  buffer_allocate(other.m_size);
  for (size_t i = 0; i < m_size; i++)
    m_buffer[i] = other.m_buffer[i];
  return *this;
}

MyString MyString::operator+(const MyString &other_myStr) const {
  MyString ret;
  ret.buffer_allocate(m_size + other_myStr.m_size - 1);
  strcpy(ret.m_buffer, m_buffer);
  strcat(ret.m_buffer, other_myStr.m_buffer);
  return ret;
}

char &MyString::operator[](size_t index) { return m_buffer[index]; }

const char &MyString::operator[](size_t index) const { return m_buffer[index]; }

std::ostream &operator<<(std::ostream &os, const MyString &myStr) {
  os << myStr.m_buffer;
  return os;
}

void MyString::buffer_deallocate() {
  delete[] m_buffer;
  m_buffer = NULL;
  m_size = 0;
}

void MyString::buffer_allocate(size_t size) {
  try {
    char *new_buf = new char[size];
    if (m_buffer)
      buffer_deallocate();
    m_buffer = new_buf;
    m_size = size;
  } catch (std::bad_alloc &e) {
    // Ignore alloc, maintain last valid buffer
  }
}