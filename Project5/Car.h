#ifndef Car_H_
#define Car_H_

#include "Vehicle.h"
#include <cstring>

class Car : public Vehicle {
public:
  Car();
  Car(const char *plates, int vin, const float *lla);
  Car(const Car &car);
  ~Car();

  Car &operator=(const Car &rhs);

  const char *getPlates() const;
  void setPlates(const char *plates);
  int getThrottle() const;

  void drive(int throttle);
  void move(const float *lla);

  friend std::ostream &operator<<(std::ostream &stream, const Car &c);

private:
  char m_plates[256];
  int m_throttle;
};
#endif