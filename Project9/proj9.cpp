#include "ArrayQueue.h"
#include "NodeQueue.h"

/// Generic Test Suite
template <typename T> void test() {
  T default_queue;
  std::cout << "Default Queue: \n" << default_queue << std::endl;

  T parameterized_queue(11, DataType(1, 2.0));
  std::cout << "Parameterized Queue: \n" << parameterized_queue << std::endl;

  T copy_param(parameterized_queue);
  std::cout << "Copy Parameterized Queue: \n" << copy_param << std::endl;

  T assign_param(parameterized_queue);
  std::cout << "Assign Parameterized: \n" << assign_param << std::endl;

  std::cout << "Front Parameterized: \n"
            << parameterized_queue.front() << std::endl;

  std::cout << "Back Parameterized: \n"
            << parameterized_queue.back() << std::endl;

  parameterized_queue.push(DataType(2, 3.0));
  std::cout << "Push Parameterized: \n" << parameterized_queue << std::endl;

  parameterized_queue.pop();
  std::cout << "Pop Parameterized: \n" << parameterized_queue << std::endl;

  std::cout << "Parameterized Size: \n"
            << parameterized_queue.size() << std::endl;

  std::cout << "Is Parameterized Empty: \n"
            << std::boolalpha << parameterized_queue.empty() << std::endl;
  std::cout << "Is Default Empty: \n"
            << std::boolalpha << default_queue.empty() << std::endl;
  std::cout << "Is Parameterized Full: \n"
            << parameterized_queue.full() << std::endl;
  parameterized_queue.clear();
  std::cout << "Cleared Parameterized: \n" << parameterized_queue << std::endl;
}

/// Entry
int main() {
  std::cout << "ArrayQueue Tests: " << std::endl;
  test<ArrayQueue>();
  std::cout << "NodeQueue Tests: " << std::endl;
  test<NodeQueue>();
  return 0;
}