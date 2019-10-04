#include <fstream>
#include <iostream>

const int MAX_ENTRIES = 5;

struct RentalCar {
  int year;
  char make[10];
  char model[10];
  float price;
  bool available;
};

/// counts characters in str array until a NULL-character '\0' is found, then it
/// returns that number excluding the '\0' one
/// the return type size_t represents an unsigned integral number large enough
/// to contain the maximum possible number of a storage size that can appear on
/// a target architecture
size_t myStringLength(const char *str) {
  size_t offset = 0;
  while (str[offset] != 0) {
    offset++;
  }
  return offset - 1;
}

/// returns 0 when the C-strings match, i.e. their characters are equal
/// one-by-one until a NULL-character '\0' is found in both strings and at the
/// same position as well returns a value <=-1 if the first character that does
/// not match has a lower value in str1 than in str2 returns a value >=1 if the
/// first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char *str1, const char *str2) {
  for (int i = 0;; i++) {
    if (str1[i] == 0 && str2[i] == 0) {
      return 0;
    }

    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
  }
}

/// copies characters from source to destination array until a NULL-character
/// '\0' is found in source, then it NULL-terminates destination too returns a
/// pointer to the destination array
char *myStringCopy(char *destination, const char *source) {
  int i;
  for (i = 0; source[i] != 0; i++) {
    destination[i] = source[i];
  }
  destination[i] = 0;
  return destination;
}

/// appends the content of source to the destination array
/// this means that the NULL-terminator of destination is overwritten by the
/// first character of source and a NULL-character '\0' is appended at the end
/// of the concatenated Cstring in destination returns a pointer to the
/// destination array
char *myStringCat(char *destination, const char *source) {
  size_t destLen = myStringLength(destination);
  myStringCopy(destination + destLen, source);
  return destination;
}

/// Loads Car Data. Returns true if successful.
bool loadData(char *filename, RentalCar entries[MAX_ENTRIES]) {
  std::ifstream file(filename);

  if (!file) {
    return false;
  }

  for (int i = 0; i < 5; i++) {
    file >> entries[i].year >> entries[i].make >> entries[i].model >>
        entries[i].price >> entries[i].available;
  }

  return true;
}

/// Copy Car data from an array from src to dest
void copyRentalCarArray(const RentalCar src[MAX_ENTRIES],
                        RentalCar dest[MAX_ENTRIES]) {
  for (int i = 0; i < MAX_ENTRIES; i++) {
    dest[i] = src[i];
  }
}

/// Formats Car data
void formatCarData(std::ostream &stream, int pos, const RentalCar *car) {
  stream << "[" << pos << "]: " << car->year << " " << car->make << " "
         << car->model << ", $" << car->price
         << " per day, Available: " << std::boolalpha << car->available << "\n";
}

/// Writes formatted Car Data from an array
void formatCarDataArray(std::ostream &stream, RentalCar entries[MAX_ENTRIES]) {
  for (int i = 0; i < MAX_ENTRIES; i++) {
    formatCarData(stream, i, &entries[i]);
    std::cout << "\n";
  }
  stream << std::endl;
}

/// Serializes Car data so it can be read again
void serializeCarDataArray(std::ostream &stream,
                           RentalCar entries[MAX_ENTRIES]) {
  for (int i = 0; i < MAX_ENTRIES; i++) {
    stream << entries[i].year << " " << entries[i].make << " "
           << entries[i].model << " " << entries[i].price << " "
           << entries[i].available << "\n";
  }
}

/// Swaps two rental cars
void swapRentalCars(RentalCar *car1, RentalCar *car2) {
  RentalCar temp = *car1;
  *car1 = *car2;
  *car2 = temp;
}

/// Performs Bubblesort to order with ascending price
void bubbleSortPrice(RentalCar entries[MAX_ENTRIES]) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < MAX_ENTRIES - 1; i++) {
      if (entries[i].price > entries[i + 1].price) {
        swapRentalCars(&entries[i], &entries[i + 1]);
        swapped = true;
      }
    }
  }
}

struct AppState {
  RentalCar entries[MAX_ENTRIES];
  bool loaded;
  bool exit;

  AppState() : loaded(false), exit(false) {}
};

/// Prints the menu
void printMenu() {
  std::cout << "Menu\n"
            << "1) Load rental car data\n"
            << "2) Print rental car data\n"
            << "3) Write rental car data to file\n"
            << "4) Sort by ascending price\n"
            << "5) Get price estimate\n"
            << "6) Rent a Car\n"
            << "7) Exit\n"
            << "\nEnter your choice: ";
}

/// Prompts the user for a filename
void promptFilename(char filename[]) {
  std::cout << "What is the filename?" << std::endl;
  std::cin >> filename;
}

/// Tries to read a positive int from cin, returns <= -1 if it fails
int readPositiveInt() {
  char inputChar;
  std::cin >> inputChar;

  if (!isdigit(inputChar)) {
    std::cin.ignore(256, '\n');
    return -1;
  }

  return inputChar - '0';
}

/// Execute command 1 from the menu (Load rental car data)
void loadRentalCarDataCli(AppState *state) {
  char filename[256];
  promptFilename(filename);
  if (!loadData(filename, state->entries)) {
    std::cout << "Failed to load data\n";
    return;
  }

  std::cout << "Sucessfully loaded data\n";
  state->loaded = true;
}

/// Execute Command 2 from the menu (Print rental car data)
void printRentalCarDataCli(AppState *state) {
  std::cout << "Rental Cars: \n";
  formatCarDataArray(std::cout, state->entries);
}

/// Execute Command 3 from the menu (Write rental car data to file)
void saveRentalCarDataCli(AppState *state) {
  char filename[256];
  promptFilename(filename);

  std::ofstream outfile(filename);
  if (!outfile) {
    std::cout << "Failed to open file.\n";
    return;
  }

  serializeCarDataArray(outfile, state->entries);
  std::cout << "Wrote data to file\n";
}

/// Execute Command 4 from the menu (Write rental car data to file)
void sortByAscendingPriceCli(AppState *state) {
  std::cout << "Sorting by ascending price...\n";
  bubbleSortPrice(state->entries);
}

/// Execute Command 5 from the menu (Write rental car data to file)
void getPriceEstimateCli(AppState *state) {
  std::cout << "How many days do you want to rent a car?" << std::endl;
  int days = readPositiveInt();

  if (days < 0) {
    std::cout << "Invalid Input\n";
    return;
  }

  RentalCar entriesCopy[MAX_ENTRIES];
  copyRentalCarArray(state->entries, entriesCopy);
  bubbleSortPrice(entriesCopy);

  std::cout << std::endl;
  for (int i = 0; i < MAX_ENTRIES; i++) {
    if (entriesCopy[i].available) {
      std::cout << "[" << i << "]: " << entriesCopy[i].make << " "
                << entriesCopy[i].model << ", Total Cost: $"
                << entriesCopy[i].price * days << "\n\n";
    }
  }
}

/// Execute option 6 from the menu (Write rental car data to file)
void rentACarCli(AppState *state) {
  std::cout << "What is the index of the car you want to rent?" << std::endl;
  int index = readPositiveInt();

  if (index < 0 || index >= MAX_ENTRIES) {
    std::cout << "Invalid Input\n";
    return;
  }

  std::cout << "How many days do you want to rent that car?" << std::endl;
  int days = readPositiveInt();

  if (index < 0) {
    std::cout << "Invalid Input\n";
    return;
  }

  if (!state->entries[index].available) {
    std::cout << "That car is not available!\n";
    return;
  }

  state->entries[index].available = true;
  std::cout << "You are now renting the " << state->entries[index].year << " "
            << state->entries[index].make << " " << state->entries[index].model
            << " for $" << state->entries[index].price * days << "\n";
}

/// Execute Command 7 from the menu (Write rental car data to file)
void exitCli(AppState *state) {
  std::cout << "Exiting...\n";
  state->exit = true;
}

/// Entry
int main() {
  AppState state;

  while (!state.exit) {
    printMenu();

    int choice = readPositiveInt();
    std::cout << '\n';

    switch (choice) {
    case -1:
      std::cout << "Invalid Choice\n";
      break;
    case 1:
      loadRentalCarDataCli(&state);
      break;
    case 7:
      exitCli(&state);
      break;
    default:
      if (state.loaded && choice <= 6 && choice >= 2) {
        switch (choice) {
        case 2:
          printRentalCarDataCli(&state);
          break;
        case 3:
          saveRentalCarDataCli(&state);
          break;
        case 4:
          sortByAscendingPriceCli(&state);
          break;
        case 5:
          getPriceEstimateCli(&state);
          break;
        case 6:
          rentACarCli(&state);
          break;
        }
      } else if (choice > 6 || choice < 2) {
        std::cout << "Invalid Choice: " << choice << "\n";
      } else {
        std::cout << "No Car Data loaded\n";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
