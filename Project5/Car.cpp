#include "Car.h"

Car::Car() : m_throttle(0) {
  std::cout << "Car #" << m_vin << ": Default-ctor\n";
}

Car::Car(const char *plates, int vin, const float *lla) : Vehicle(vin, lla) {
  strcpy(m_plates, plates);
  std::cout << "Car #" << m_vin << ": Parametrized-ctor\n";
}

Car::Car(const Car &car) : m_throttle(car.m_throttle) {
  strcpy(m_plates, car.m_plates);
}

Car::~Car() { std::cout << "Car #" << m_vin << ": Dtor\n"; }

Car &Car::operator=(const Car &rhs) {
  std::cout << "Car #" << m_vin << ": Assignment\n";
  m_throttle = rhs.m_throttle;
  setPlates(rhs.m_plates);
  setLLA(rhs.m_lla);
  return *this;
}

const char *Car::getPlates() const { return m_plates; }
void Car::setPlates(const char *plates) { strcpy(m_plates, plates); }
int Car::getThrottle() const { return m_throttle; }

void Car::drive(int throttle) { m_throttle = throttle; }
void Car::move(const float *lla) {
  std::cout << "Car #" << m_vin
            << ": DRIVE to destination, with throttle @ 75\n";
  drive(75);
  setLLA(lla);
}

std::ostream &operator<<(std::ostream &stream, const Car &c) {
  stream << "Car #" << c.m_vin << " Plates " << c.m_plates << " @ "
         << "[" << c.m_lla[0] << ", " << c.m_lla[1] << ", " << c.m_lla[2]
         << "]\n";
  return stream;
}