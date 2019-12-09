#include "VectorRecursion.h"
#include <fstream>

template <typename T> void print_vec(std::vector<T> &list) {
  for (size_t i = 0; i < list.size(); i++)
    std::cout << list[i] << ' ';
}

const size_t VEC_SIZE = 100;
int main() {
  std::vector<int> vecInt(VEC_SIZE);
  std::ifstream file("RandomData.txt");
  for (size_t i = 0; i < VEC_SIZE; i++)
    file >> vecInt[i];

  std::vector<int> vecIntCpy(vecInt);

  vector_resort(vecInt, vecInt.size());
  vector_research(vecInt, 86, vecInt.begin(), vecInt.end());
  print_vec(vecInt);

  return 0;
}