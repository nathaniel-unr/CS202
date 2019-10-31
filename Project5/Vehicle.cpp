#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(++s_idgen) {
  for (int i = 0; i < LLA_LEN; i++)
    m_lla[i] = 0;

  std::cout << "Vehicle #" << m_vin << ": Default-ctor\n";
}

Vehicle::Vehicle(int vin, const float *lla)
    : m_vin(vin <= s_idgen ? ++s_idgen : vin) {
  setLLA(lla);

  std::cout << "Vehicle #" << vin << ": Parametrized-ctor\n";
}

Vehicle::Vehicle(const Vehicle &v) : m_vin(++s_idgen) {
  setLLA(v.m_lla);
  std::cout << "Vehicle #" << m_vin << ": Copy-ctor\n";
}

Vehicle::~Vehicle() { std::cout << "Vehicle #" << m_vin << ": Dtor\n"; }

void Vehicle::move(const float *lla) {
  setLLA(lla);

  std::cout << "Vehicle #" << m_vin << ": CANNOT MOVE -I DON'T KNOW HOW\n";
}

Vehicle &Vehicle::operator=(const Vehicle &rhs) {
  std::cout << "Vehicle #" << m_vin << ": Assignment\n";
  setLLA(rhs.m_lla);
  return *this;
}

int Vehicle::getVin() const { return m_vin; }
const float *Vehicle::getLLA() const { return m_lla; }
void Vehicle::setLLA(const float *lla) {
  for (int i = 0; i < LLA_LEN; i++)
    m_lla[i] = lla[i];
}

std::ostream &operator<<(std::ostream &stream, const Vehicle &v) {
  stream << "Vehicle #" << v.m_vin << " @ "
         << "[" << v.m_lla[0] << ", " << v.m_lla[1] << ", " << v.m_lla[2]
         << "]\n";
  return stream;
}

int Vehicle::getIdgen() { return s_idgen; }