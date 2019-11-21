/**

 * @brief Testing driver for project 8
 *
 * @author Nathaniel Daniel
 *
 */

#include "ArrayList.h"
#include "NodeList.h"

/// Generic Testing
template <class T> void test_generic() {
  T def;
  std::cout << "Default: " << def << std::endl;

  T parameterized(3, DataType(4, 5.0));
  std::cout << "Parameterized: " << parameterized << std::endl;

  T copy_parameterized(parameterized);
  std::cout << "Copy Parameterized: " << copy_parameterized << std::endl;

  std::cout << "Size: " << parameterized.size() << std::endl;
  std::cout << "Empty: " << std::boolalpha << parameterized.empty()
            << std::endl;
  std::cout << "Access: " << parameterized[1] << std::endl;
  parameterized.clear();
  std::cout << "Clear: " << parameterized << std::endl;
}

/// ArrayList specific Testing
void test_array_list() {
  ArrayList parameterized(3, DataType(4, 5.0));
  DataType *param_front = parameterized.front();
  std::cout << "Good front: " << std::boolalpha << (param_front != NULL)
            << std::endl;

  DataType target(4, 5.0);
  DataType *previous = NULL;
  DataType *result = parameterized.find(target, previous);
  std::cout << "Good search: " << std::boolalpha << (result != NULL)
            << std::endl;
  parameterized.insertAfter(DataType(*result), DataType(3, 5.0));
  std::cout << "insertAfter, New Parameterized: " << parameterized << std::endl;

  parameterized.erase(*parameterized.front());
  std::cout << "erase, New Parameterized: " << parameterized << std::endl;

  DataType result_cpy = *parameterized.find(DataType(3, 5.0), previous);
  parameterized.insertBefore(result_cpy, DataType(2, 5.0));
  std::cout << "insertBefore, New Parameterized: " << parameterized
            << std::endl;
}

/// NodeList Specific testing
void test_node_list() {
  NodeList parameterized(3, DataType(4, 5.0));
  Node *param_front = parameterized.front();
  std::cout << "Good front: " << std::boolalpha << (param_front != NULL)
            << std::endl;

  DataType target(4, 5.0);
  Node *previous = NULL;
  Node *result = parameterized.find(target, previous);
  std::cout << "Good search: " << std::boolalpha << (result != NULL)
            << std::endl;
  parameterized.insertAfter(result->data(), DataType(3, 5.0));
  std::cout << "insertAfter, New Parameterized: " << parameterized << std::endl;

  parameterized.erase(parameterized.front()->data());
  std::cout << "erase, New Parameterized: " << parameterized << std::endl;

  DataType result_cpy = parameterized.find(DataType(3, 5.0), previous)->data();
  parameterized.insertBefore(result_cpy, DataType(2, 5.0));
  std::cout << "insertBefore, New Parameterized: " << parameterized
            << std::endl;
}

/// Entry
int main() {
  std::cout << "Generic ArrayList Tests: " << std::endl;
  test_generic<ArrayList>();
  std::cout << "Specific ArrayList Tests: " << std::endl;
  test_array_list();
  std::cout << "Generic NodeList Tests: " << std::endl;
  test_generic<NodeList>();
  std::cout << "OK";
  std::cout << "Specific NodeList Tests: " << std::endl;
  test_node_list();

  return 0;
}