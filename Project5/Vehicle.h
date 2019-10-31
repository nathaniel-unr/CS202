#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "proj5.h"
#include <iostream>

class Vehicle {
public:
  Vehicle();
  Vehicle(int vin, const float *lla);
  Vehicle(const Vehicle &v);
  ~Vehicle();

  Vehicle &operator=(const Vehicle &rhs);

  void move(const float *lla);
  int getVin() const;
  const float *getLLA() const;
  void setLLA(const float *lla);

  friend std::ostream &operator<<(std::ostream &stream, const Vehicle &v);
  static int getIdgen();

protected:
  float m_lla[LLA_LEN];
  const int m_vin;

private:
  static int s_idgen;
};
#endif