#ifndef CAR_H_
#define CAR_H_

#include "Sensor.h"
#include "proj4.h"

class Car {
public:
  /// Default Constructor
  Car();

  /// Parametrized Constructor
  Car(char *make, char *model, int year, float baseprice, Sensor *sensors,
      int sensor_cnt);

  /// Copy Constructor
  Car(const Car &car);

  /// Get Make
  const char *getMake(char *dest) const;

  /// Get Model
  const char *getModel(char *dest) const;

  /// Get Year
  int getYear() const;

  /// Get Sensor Array
  const Sensor *getSensors() const;

  /// Get Sensor Count
  int getSensorCnt() const;

  /// Get base price
  float getBaseprice() const;

  /// Get final price
  float getFinalprice() const;

  /// Get availablity
  bool getAvailable() const;

  /// Get Owner
  const char *getOwner() const { return m_owner; }

  /// Set Make
  void setMake(char *make);

  /// Set Model
  void setModel(char *model);

  /// Set Year
  void setYear(int year);

  /// Set Sensors
  void setSensors(const Sensor *sensors, int sensor_cnt);

  /// Set Base Price
  void setBaseprice(float baseprice);

  /// Set final price
  void setFinalprice(float finalprice);

  /// Set availablity
  void setAvailable(bool available);

  /// Set Owner
  void setOwner(char *owner);

  /// Recalculate price
  void updatePrice();

  /// Print data
  void print(std::ostream &stream) const;

  /// Estimate cost
  float estimateCost(int days) const;

  /// Add sensor to car
  Car &operator+(const Sensor &sensor);

  /// Add Owner to car
  Car &operator+(const char *owner);

  /// Load from istream
  friend std::istream &operator>>(std::istream &stream, Car &car);

private:
  char m_make[STR_MAX];
  char m_model[STR_MAX];
  int m_year;
  Sensor m_sensors[SENSOR_NUM];
  int m_sensor_cnt;
  float m_baseprice;
  float m_finalprice;
  bool m_available;
  char m_owner[STR_MAX];
};

#endif