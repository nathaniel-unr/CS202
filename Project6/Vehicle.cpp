#include "Vehicle.h"

Vehicle::Vehicle() { std::cout << "Vehicle: Default-ctor\n"; }
Vehicle::Vehicle(const float *lla) {
  SetLLA(lla);
  std::cout << "Vehicle: Parametrized-ctor\n";
}
Vehicle::Vehicle(const Vehicle &v) {
  SetLLA(v.m_lla);
  std::cout << "Vehicle: Copy-ctor\n";
}
Vehicle::~Vehicle() { std::cout << "Vehicle: Dtor\n"; }

void Vehicle::SetLLA(const float *lla) {
  for (int i = 0; i < LLA_LEN; i++)
    m_lla[i] = lla[i];
}

const float *Vehicle::getLLA() const { return m_lla; }

Vehicle &Vehicle::operator=(const Vehicle &other) {
  SetLLA(other.m_lla);
  std::cout << "Vehicle: Assignment\n";
  return *this;
}

void Vehicle::serialize(std::ostream &stream) const {
  stream << "Vehicle@ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2]
         << "]";
}

std::ostream &operator<<(std::ostream &stream, const Vehicle &v) {
  v.serialize(stream);
  return stream;
}