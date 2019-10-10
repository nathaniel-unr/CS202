#include "Agency.h"

Agency::Agency() : m_zipcode(0) { myStringCopy(m_name, ""); }

Agency::Agency(char *name, int zip) : m_zipcode(zip) {
  myStringCopy(m_name, name);
}

const char *Agency::getName() const { return m_name; }

const int Agency::getZipcode() const { return m_zipcode; }

const Car *Agency::getInventory() const { return m_inventory; }

void Agency::setName(char *name) { myStringCopy(m_name, name); }

void Agency::setInventory(const Car *car) {
  for (int i = 0; i != CAR_NUM; i++) {
    *(m_inventory + i) = *(car + i);
  }
}

void Agency::readAllData(std::istream &stream) {
  stream >> m_name >> const_cast<int &>(m_zipcode);
  for (int i = 0; i < CAR_NUM; i++) {
    stream >> *(m_inventory + i);
  }
}

void Agency::printAllData(std::ostream &stream) const {
  stream << m_name << " " << m_zipcode << "\n";
  for (int i = 0; i < CAR_NUM; i++) {
    (m_inventory + i)->print(stream);
  }
}

void Agency::printAvailableCars(std::ostream &stream) {
  stream << m_name << " " << m_zipcode << "\n";
  for (int i = 0; i < CAR_NUM; i++) {
    Car *carPtr = (m_inventory + i);
    if (carPtr->getAvailable()) {
      carPtr->print(stream);
    }
  }
}

Car &Agency::operator[](int i) { return *(m_inventory + i); }