#include "Car.h"

Car::Car() { std::cout << "Car: Default-ctor\n"; }
Car::Car(const float *lla) : Vehicle(lla) {
  m_throttle = 0;
  std::cout << "Car: Parametrized-ctor\n";
}
Car::Car(const Car &c) : Vehicle(c.m_lla), m_throttle(c.m_throttle) {
  std::cout << "Car: Copy-ctor\n";
}

Car::~Car() { std::cout << "Car: Dtor\n"; }

int Car::getThrottle() const { return m_throttle; }
void Car::setThrottle(int throttle) { m_throttle = throttle; }
void Car::drive(int throttle) { setThrottle(throttle); }

void Car::Move(const float *lla) {
  std::cout << "Car: DRIVE to destination, with throttle @ 75\n";
  drive(75);
  SetLLA(lla);
}

void Car::serialize(std::ostream &stream) {
  stream << "Car:Throttle: " << m_throttle << " @[" << m_lla[0] << ", "
         << m_lla[1] << ", " << m_lla[2] << "]";
}

Car &Car::operator=(const Car &c) {
  m_throttle = c.m_throttle;
  SetLLA(c.m_lla);
  std::cout << "Car: Assignment\n";
  return *this;
}