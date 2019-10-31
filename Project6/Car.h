#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"

class Car : public Vehicle {
public:
  /// Default Constructor
  Car();
  /// Parameterized Constructor
  Car(const float *lla);
  /// Copy Constructor
  Car(const Car &c);
  /// Virtual Destructor
  virtual ~Car();

  /// Get m_throttle
  int getThrottle() const;
  /// Set m_throttle
  void setThrottle(int throttle);

  /// Drive by setting throttle
  void drive(int throttle);

  /// Move to lla
  virtual void Move(const float *lla);

  /// Assignment Operator
  Car &operator=(const Car &c);

private:
  int m_throttle;
  /// Virtual Data Serializer
  virtual void serialize(std::ostream &stream);
};
#endif