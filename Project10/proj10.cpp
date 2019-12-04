#include "ArrayStack.h"
#include "NodeStack.h"

/// Generic Tests
template <typename T> void test() {
  T default_stack;
  std::cout << "Default Stack: " << std::endl;
  std::cout << default_stack << std::endl;

  T parameterized(10, 1);
  std::cout << "Parameterized Stack: " << std::endl;
  std::cout << parameterized << std::endl;

  T parameterized_copy(parameterized);
  std::cout << "Parameterized Stack Copy: " << std::endl;
  std::cout << parameterized_copy << std::endl;

  T parameterized_assign = parameterized;
  std::cout << "Parameterized Stack Assign: " << std::endl;
  std::cout << parameterized_assign << std::endl;

  std::cout << "First Element Parameterized: " << std::endl;
  std::cout << parameterized.top() << std::endl;

  std::cout << "Push Parameterized: " << std::endl;
  parameterized.push(2);
  std::cout << parameterized << std::endl;

  std::cout << "Pop Parameterized: " << std::endl;
  parameterized.pop();
  std::cout << parameterized << std::endl;

  std::cout << "Parameterized Size: " << std::endl;
  std::cout << parameterized.size() << std::endl;

  std::cout << "Is Empty: " << std::endl;
  std::cout << std::boolalpha << parameterized.empty() << std::endl;

  std::cout << "Is Full: " << std::endl;
  std::cout << std::boolalpha << parameterized.full() << std::endl;

  std::cout << "Clear Parameterized: " << std::endl;
  parameterized.clear();
  std::cout << parameterized << std::endl;
}

typedef ArrayStack<int> ArrayStackInt;
typedef NodeStack<int> NodeStackInt;

///Entry
int main() {
  std::cout << "Array Stack Tests" << std::endl;
  test<ArrayStackInt>();

  std::cout << "Node Stack Tests" << std::endl;
  test<NodeStackInt>();
  return 0;
}