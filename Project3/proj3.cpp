/**
    CS-202, proj3.cpp
    Purpose: The purpose of this program is to load data from a file of car
   agencies into an array of agencies, print out the loaded data, estimate the
   cost for a car that the user selects, locate and print out the data for the
   most expensive car, print out the data for available cars to a file, and
   exit.

    @author Nathaniel Daniel
*/
#include <fstream>
#include <iostream>

const int NUM_AGENCIES = 3;
const int CARS_PER_AGENCY = 5;
const int ZIP_CODE_SIZE = 5;

// counts characters in str array until a NULL-character '\0' is found, then it
// returns that number excluding the '\0'one the return type size_t represents
// an unsigned integral number large enough to contain the maximum possible
// number of a storage size that can appear on a target architecture
size_t myStringLength(const char *str) {
  size_t i;
  for (i = 0; *(str + i) != 0; i++) {
  }
  return i;
}

// returns 0 when the C-strings match, i.e. their characters are equal
// one-by-one until a NULL-character '\0' is found in both strings and at the
// same position as well returns a value <=-1 if the first character that does
// not match has a lower value in str1 than in str2 returns a value >=1 if the
// first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char *str1, const char *str2) {
  for (int i = 0;; i++) {
    char str1Val = *(str1 + i);
    char str2Val = *(str2 + i);
    if (str1Val == 0 && str2Val == 0) {
      return 0;
    }

    if (str1Val != str2Val) {
      return str1Val - str2Val;
    }
  }
}

// copies characters from source to destination array until a NULL-character
// '\0' is found in source, then it NULL-terminates destination too returns a
// pointer to the destination array
char *myStringCopy(char *destination, const char *source) {
  int i;
  for (i = 0; *(source + i) != 0; i++) {
    *(destination + i) = *(source + i);
  }
  *(destination + i) = 0;
  return destination;
}

// appends the content of source to the destination array
// this means that the NULL-terminator of destination is overwritten by the
// first character of source and a NULL-character '\0' is appended at the end of
// the concatenated Cstring in destination returns a pointer to the destination
// array
char *myStringCat(char *destination, const char *source) {
  size_t size = myStringLength(destination);
  myStringCopy(destination + size, source);
  return destination;
}

class RentalCar {
public:
  /// Zero argument constructor
  RentalCar() : m_year(0), m_price(0.0), m_available(false) {}

  /// Parameterized constructor for all member variables
  RentalCar(int year, char *make, char *model, float price,
            bool available = false)
      : m_year(year), m_price(price), m_available(available) {
    myStringCopy(m_make, make);
    myStringCopy(m_model, model);
  }

  /// Gets the car's year
  int getYear() { return m_year; }
  /// Sets the car's year
  void setYear(int year) { m_year = year; }

  /// Sets the car's make
  void getMake(char *buffer) { myStringCopy(buffer, m_make); }
  /// Gets the car's make
  void setMake(const char *buffer) { myStringCopy(m_model, buffer); }

  /// Gets the car's model
  void getModel(char *buffer) { myStringCopy(buffer, m_model); }
  /// Sets the car's model
  void setModel(const char *buffer) { myStringCopy(m_model, buffer); }

  /// Gets the car's price
  float getPrice() { return m_price; }
  /// Sets the car's price
  void setPrice(float price) { m_price = price; }

  /// Sets the car's availability
  bool getAvailable() { return m_available; }
  /// Gets whether the car is available
  void setAvailable(bool available) { m_available = available; }

  /// Prints data to a stream
  void print(std::ostream &stream) {
    stream << m_year << " " << m_make << " " << m_model << ", " << m_price
           << " per day, Available: " << std::boolalpha << m_available << "\n";
  }

  /// Loads data from a stream
  void load(std::ifstream &stream) {
    stream >> m_year >> m_make >> m_model >> m_price >> m_available;
  }

  /// Caculates the estimated cost for this car for a number of days
  float estimateCost(int days) { return static_cast<float>(days) * m_price; }

private:
  int m_year;
  char m_make[256];
  char m_model[256];
  float m_price;
  bool m_available;
};

struct RentalAgency {
  char name[256];
  int zipcode[ZIP_CODE_SIZE];
  RentalCar inventory[CARS_PER_AGENCY];
};

/// Loads data from a stream with multiple agencies and cars
void loadMultiAgencyData(std::ifstream &stream, RentalAgency *agencyPtr) {
  for (int i = 0; i < NUM_AGENCIES; i++, agencyPtr++) {
    int zipcode = 0;
    stream >> agencyPtr->name >> zipcode;

    int *zipPtr = &agencyPtr->zipcode[ZIP_CODE_SIZE - 1];
    for (int j = 0; j < ZIP_CODE_SIZE; j++, zipPtr--) {
      *zipPtr = zipcode % 10;
      zipcode /= 10;
    }
    RentalCar *carPtr = agencyPtr->inventory;
    for (int j = 0; j < CARS_PER_AGENCY; j++, carPtr++) {
      carPtr->load(stream);
    }
  }
}

class App {
public:
  /// Default constructor
  App() : m_loaded(false), m_exit(false) {}
  /// Runs the app
  void run() {
    while (!m_exit) {
      printMenu();
      std::cout << "What would you like to do?" << std::endl;
      int choice = readChoice();
      std::cout << std::endl;

      if (choice == -1) {
        std::cout << "Invalid Input\n";
      } else if (choice < 1 || choice > 6) {
        std::cout << "Unknown Option " << choice << "\n";
      }

      switch (choice) {
      case 1:
        loadData();
        break;
      case 6:
        exit();
        break;
      default:
        if (!m_loaded) {
          std::cout << "No data loaded\n";
        } else {
          switch (choice) {
          case 2:
            printData();
            break;
          case 3:
            estimateCost();
            break;
          case 4:
            getMostExpensive();
            break;
          case 5:
            saveAvailable();
            break;
          }
        }
        break;
      }

      std::cout << std::endl;
    }
  }

private:
  RentalAgency m_agencies[NUM_AGENCIES];
  bool m_loaded;
  bool m_exit;
  /// Loads car data
  void loadData() {
    char filename[256];
    std::cout << "What is the filename?" << std::endl;
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file) {
      std::cout << "Failed to load file \"" << filename << "\"\n";
      return;
    }
    loadMultiAgencyData(file, m_agencies);
    m_loaded = true;
    std::cout << "Loaded data\n";
  }
  /// Prints all car data
  void printData() {
    RentalAgency *agencyPtr = m_agencies;
    for (int i = 0; i < NUM_AGENCIES; i++, agencyPtr++) {
      std::cout << agencyPtr->name << " ";

      int *zipPtr = agencyPtr->zipcode;
      for (int i = 0; i < ZIP_CODE_SIZE; i++, zipPtr++) {
        std::cout << *zipPtr;
      }
      std::cout << "\n";

      RentalCar *carPtr = agencyPtr->inventory;
      for (int i = 0; i < CARS_PER_AGENCY; i++, carPtr++) {
        carPtr->print(std::cout);
      }

      std::cout << "\n";
    }
  }
  /// Asks the user for a car, then calculates the estimated price for a certain
  /// number of days
  void estimateCost() {
    RentalAgency *agencyPtr = m_agencies;
    std::cout << "Agencies" << std::endl;
    for (int i = 0; i < NUM_AGENCIES; i++, agencyPtr++) {
      std::cout << i + 1 << ") " << agencyPtr->name << "\n";
    }
    std::cout << std::endl;

    std::cout << "What agency do you want?" << std::endl;
    int choice = readChoice();
    std::cout << std::endl;

    if (choice == -1) {
      std::cout << "Invalid Choice\n";
      return;
    } else if (choice < 1 || choice > NUM_AGENCIES) {
      std::cout << "Invalid Option: " << choice << std::endl;
      return;
    }

    agencyPtr = m_agencies + choice - 1;

    std::cout << "Cars" << std::endl;
    RentalCar *carPtr = agencyPtr->inventory;
    for (int i = 0; i < CARS_PER_AGENCY; i++, carPtr++) {
      std::cout << i + 1 << ") ";
      carPtr->print(std::cout);
    }
    std::cout << std::endl;

    std::cout << "What car do you want?" << std::endl;
    choice = readChoice();
    std::cout << std::endl;

    if (choice == -1) {
      std::cout << "Invalid Choice\n";
      return;
    } else if (choice < 1 || choice > CARS_PER_AGENCY) {
      std::cout << "Invalid Option: " << choice << std::endl;
      return;
    }

    carPtr = agencyPtr->inventory + choice - 1;

    std::cout << "How many days do you want to rent it for?" << std::endl;
    int days = readPositiveInt();
    std::cout << std::endl;

    if (choice == -1) {
      std::cout << "Invalid Choice\n";
      return;
    }

    std::cout << "Estimated Cost: " << days * carPtr->getPrice() << "\n";
  }
  /// Prints the most expensive car
  void getMostExpensive() {
    RentalAgency *agencyPtr = m_agencies;
    RentalCar *top = agencyPtr->inventory;
    for (int i = 0; i < NUM_AGENCIES; i++, agencyPtr++) {
      RentalCar *carPtr = agencyPtr->inventory;
      for (int j = 0; j < CARS_PER_AGENCY; j++, carPtr++) {
        if (carPtr->getPrice() > top->getPrice()) {
          top = carPtr;
        }
      }
    }

    std::cout << "Most Expensive Car\n";
    top->print(std::cout);
    std::cout << "\n";
  }
  /// Saves all available cars to a user specified file
  void saveAvailable() {
    char filename[256];
    std::cout << "What is the filename?" << std::endl;
    std::cin >> filename;
    std::ofstream file(filename);

    if (!file) {
      std::cout << "Failed to open file!\n";
      return;
    }

    RentalAgency *agencyPtr = m_agencies;
    for (int i = 0; i < NUM_AGENCIES; i++, agencyPtr++) {
      RentalCar *carPtr = agencyPtr->inventory;
      for (int j = 0; j < CARS_PER_AGENCY; j++, carPtr++) {
        if (carPtr->getAvailable()) {
          carPtr->print(file);
        }
      }
    }

    std::cout << "Saved available\n";
  }
  /// Exits the app
  void exit() {
    std::cout << "Exiting...\n";
    m_exit = true;
  }
  /// Prints the menu
  void printMenu() {
    std::cout << "Menu\n"
              << "1) Load Data\n"
              << "2) Print Data\n"
              << "3) Estimate Cost\n"
              << "4) Get Most Expensive\n"
              << "5) Save Available\n"
              << "6) Exit\n"
              << std::endl;
  }

  /// Reads a positive int from cin
  int readPositiveInt() {
    int data;
    std::cin >> data;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(256, '\n');
      return -1;
    }

    return data;
  }
  /// Reads a positive one digit number from cin
  int readChoice() {
    char inputChar;
    std::cin >> inputChar;

    if (!isdigit(inputChar)) {
      std::cin.ignore(256, '\n');
      return -1;
    }

    return inputChar - '0';
  }
};

/// Entry
int main() {
  App app;
  app.run();
  return 0;
}