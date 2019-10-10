#ifndef AGENCY_H_
#define AGENCY_H_

#include "Car.h"

class Agency {
public:
  /// Default Constructor
  Agency();

  /// Parametrized Constructor
  Agency(char *name, int zip);

  /// Get Name
  const char *getName() const;

  /// Get Zipcode
  const int getZipcode() const;

  /// Gets Inventory
  const Car *getInventory() const;

  /// Sets Name
  void setName(char *name);

  /// Sets Inventory State
  void setInventory(const Car *car);

  /// Reads data from a stream
  void readAllData(std::istream &stream);

  /// Print all car data
  void printAllData(std::ostream &stream) const;

  /// Prints available cars
  void printAvailableCars(std::ostream &stream);

  /// Access Cars
  Car &operator[](int i);

private:
  char m_name[STR_MAX];
  const int m_zipcode;
  Car m_inventory[CAR_NUM];
};

#endif
