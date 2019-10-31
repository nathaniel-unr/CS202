#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "proj6.h"
#include <iostream>

class Vehicle {
public:
  /// Default Constructor
  Vehicle();
  /// Parameterized Constructor
  Vehicle(const float *lla);
  /// Copy Constructor
  Vehicle(const Vehicle &v);

  /// Virtual Destructor
  virtual ~Vehicle();

  /// Set LLA
  void SetLLA(const float *lla);
  /// Get LLA
  const float *getLLA() const;

  /// Pure virtual move to LLA Func
  virtual void Move(const float *lla) = 0;

  /// Assign Operator
  Vehicle &operator=(const Vehicle &other);

  /// operator<<
  friend std::ostream &operator<<(std::ostream &stream, const Vehicle &v);

protected:
  float m_lla[LLA_LEN];

private:
  /// Private virtual Serializer
  virtual void serialize(std::ostream &stream) const;
};
#endif