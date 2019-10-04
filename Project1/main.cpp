/**
 * @brief  CS-202 Project 1
 * This project reads in a file specified by the user with 10 names with a max
 * size of 8. It then prints out the unordered data to the console. It then uses
 * bubble sort to sort by length and by alphabetic value, printing the ordered
 * results as it does so.
 */

#include <fstream>
#include <iostream>

const int NUM_ENTRIES = 10;
const int MAX_NAME_SIZE = 8;

/// Prints the entries arg with the order specified
void printWithOrder(const char entries[NUM_ENTRIES][MAX_NAME_SIZE + 1],
                    const int order[NUM_ENTRIES]) {
  for (int i = 0; i < NUM_ENTRIES; i++) {
    std::cout << order[i] << " " << entries[order[i]] << "\n";
  }
}

/// Copies the string source to destination
void myStringCopy(char destination[MAX_NAME_SIZE + 1],
                  const char source[MAX_NAME_SIZE + 1]) {
  for (int i = 0; i < MAX_NAME_SIZE + 1; i++) {
    destination[i] = source[i];
    if (source[i] == 0) {
      break;
    }
  }
}

/// Returns the length of the string
int myStringLength(const char str[MAX_NAME_SIZE + 1]) {
  for (int i = 0; i < MAX_NAME_SIZE + 1; i++) {
    if (str[i] == 0) {
      return i;
    }
  }
}

/// Compares two string lengths, returning 1 if the char in str1 is greater or
/// -1 if str is greater. It returns 0 if both are equal.
int myStringCompare(const char str1[MAX_NAME_SIZE + 1],
                    const char str2[MAX_NAME_SIZE + 1]) {
  for (int i = 0; i < MAX_NAME_SIZE + 1; i++) {
    if (str1[i] == 0 && str2[i] == 0) {
      return 0;
    } else if (str1[i] == 0) {
      return -1;
    } else if (str2[i] == 0) {
      return 1;
    } else if (str1[i] < str2[i]) {
      return -1;
    } else if (str1[i] > str2[i]) {
      return 1;
    }
  }

  return 0;
}

/// Returns true if the length of str1 is greater than the length of str2
bool shouldSwapLength(const char str1[MAX_NAME_SIZE + 1],
                      const char str2[MAX_NAME_SIZE + 1]) {
  int strLen1 = myStringLength(str1);
  int strLen2 = myStringLength(str2);
  return strLen1 > strLen2;
}

/// Returns true if str2 is first alphabetically
bool shouldSwapAlphabetic(const char str1[MAX_NAME_SIZE + 1],
                          const char str2[MAX_NAME_SIZE + 1]) {
  return myStringCompare(str1, str2) == 1;
}

/// Uses bubblesort to sort inputs based on a function passed in, mutating the
/// order arg with the results.
void bubbleSort(const char inputs[NUM_ENTRIES][MAX_NAME_SIZE + 1],
                int order[NUM_ENTRIES],
                bool (*shouldSwap)(const char[], const char[])) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < NUM_ENTRIES - 1; i++) {
      int strLen1 = myStringLength(inputs[order[i]]);
      int strLen2 = myStringLength(inputs[order[i + 1]]);

      if ((*shouldSwap)(inputs[order[i]], inputs[order[i + 1]])) {
        int temp = order[i];
        order[i] = order[i + 1];
        order[i + 1] = temp;
        swapped = true;
      }
    }
  }
}

int main() {
  char names[NUM_ENTRIES][MAX_NAME_SIZE + 1]; // Nul char
  int order[NUM_ENTRIES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  char filename[256]; // How am I supposed to read a filename with no upper
                      // limit and no dynamic memory?
  std::cout << "What is your filename?" << std::endl;
  std::cin >> filename;

  std::fstream inputFile(filename);

  if (!inputFile) {
    std::cout << "Could not open file!" << std::endl;
    return 1;
  }

  for (int i = 0; i < NUM_ENTRIES; i++) {
    inputFile >> names[i];
  }

  std::cout << "\n"
            << "Unsorted Names:"
            << "\n";
  printWithOrder(names, order);
  std::cout << std::endl;

  bubbleSort(names, order, shouldSwapLength);

  std::cout << "\n"
            << "Sort by Length"
            << "\n";
  printWithOrder(names, order);
  std::cout << std::endl;

  bubbleSort(names, order, shouldSwapAlphabetic);

  std::cout << "\n"
            << "Sort by Alphebet"
            << "\n";
  printWithOrder(names, order);
  std::cout << std::endl;

  return 0;
}
