#include "Agency.h"
#include "Car.h"
#include "Sensor.h"

#include "proj4.h"

size_t myStringLength(const char *str) {
  size_t i;
  for (i = 0; *(str + i) != 0; i++) {
  }
  return i;
}

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

char *myStringCopy(char *destination, const char *source) {
  int i;
  for (i = 0; *(source + i) != 0; i++) {
    *(destination + i) = *(source + i);
  }
  *(destination + i) = 0;
  return destination;
}

char *myStringCat(char *destination, const char *source) {
  size_t size = myStringLength(destination);
  myStringCopy(destination + size, source);
  return destination;
}

bool trimStart(const char *str, char *dest, char c) {
  if (*str == c) {
    str++;
    myStringCopy(dest, str);
    return true;
  } else {
    myStringCopy(dest, str);
    return false;
  }
}

bool trimEnd(const char *str, char *dest, char c) {
  myStringCopy(dest, str);
  size_t len = myStringLength(dest);
  if (*(dest + len - 1) == c) {
    *(dest + len - 1) = 0;
    return true;
  } else {
    return false;
  }
}

class App {
public:
  /// Default Constructor
  App() : m_loaded(false), m_exit(false) {}
  /// Runs App
  void run() {
    while (!m_exit) {
      printMenu();
      std::cout << "What would you like to do?" << std::endl;
      int choice = readChoice();
      std::cout << std::endl;

      if (choice == -1) {
        std::cout << "Invalid Input\n";
      } else if (choice < 1 || choice > 5) {
        std::cout << "Unknown Option " << choice << "\n";
      } else {
        switch (choice) {
        case 1:
          loadData();
          break;
        case 5:
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
              printNumSensors();
              break;
            case 4:
              rentExpensiveCar();
              break;
            }
            break;
          }
        }
      }
      std::cout << std::endl;
    }
  }

private:
  /// Reads a positive one digit number from cin
  int readChoice() {
    char inputChar;
    std::cin >> inputChar;

    if (!isdigit(inputChar)) {
      std::cin.ignore(STR_MAX, '\n');
      return -1;
    }

    return inputChar - '0';
  }
  /// Prints the menu
  void printMenu() {
    std::cout << "Menu\n"
              << "1) Load Data\n"
              << "2) Print Data\n"
              << "3) Print Num Sensors\n"
              << "4) Rent Expensive Car\n"
              << "5) Exit\n"
              << std::endl;
  }

  /// Loads car data
  void loadData() {
    char filename[STR_MAX];
    std::cout << "What is the filename?" << std::endl;
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file) {
      std::cout << "\nFailed to load file \"" << filename << "\"\n";
      return;
    }

    Sensor::resetCameraCnt();
    Sensor::resetGpsCnt();
    Sensor::resetLidarCnt();
    Sensor::resetRadarCnt();

    m_agency.readAllData(file);

    m_loaded = true;
    std::cout << "\nLoaded data\n";
  }

  /// Prints all car data
  void printData() {
    m_agency.printAllData(std::cout);
    std::cout << "\n";
  }

  /// Print the number of sensors installed on the fleet
  void printNumSensors() {
    std::cout << "Sensors\n"
              << "GPS: " << Sensor::getGpsCnt() << "\n"
              << "Camera: " << Sensor::getCameraCnt() << "\n"
              << "Lidar: " << Sensor::getLidarCnt() << "\n"
              << "Radar: " << Sensor::getRadarCnt() << "\n";
  }

  /// Try to rent the most expensive Car
  void rentExpensiveCar() {
    Car *expensive = &m_agency[0];
    for (int i = 0; i < CAR_NUM; i++) {
      if ((m_agency[i].getAvailable() &&
           m_agency[i].getFinalprice() > expensive->getFinalprice()) ||
          (!expensive->getAvailable() && m_agency[i].getAvailable())) {
        expensive = &m_agency[i];
      }
    }

    if (!expensive->getAvailable()) {
      std::cout << "No Available Cars!\n";
      return;
    }

    std::cout << "Most Expensive Car\n";
    expensive->print(std::cout);
    std::cout << "\n"
              << "Do you want to rent this car? (y/n)" << std::endl;
    char input[STR_MAX];
    std::cin >> input;
    std::cout << std::endl;
    if (input[0] == 'y' || input[0] == 'Y') {
      std::cout << "\n"
                << "What is your name?" << std::endl;
      std::cin >> input;
      std::cout << std::endl;

      std::cout << "Renting Car...\n";
      expensive->setAvailable(false);
      expensive->setOwner(input);
    } else {
      std::cout << "Aborting...\n";
    }
  }

  /// Exits the app
  void exit() {
    std::cout << "Exiting...\n";
    m_exit = true;
  }

  Agency m_agency;
  bool m_loaded;
  bool m_exit;
};

/// Entry
int main() {
  App app;
  app.run();
  return 0;
}