#ifndef SENSOR_H_
#define SENSOR_H_

#include "proj4.h"

class Sensor {
public:
  /// Default Constructor
  Sensor();

  /// Parametrized Constructor
  Sensor(char *type);

  /// Copy Constructor
  Sensor(const Sensor &sensor);

  /// Update price based on sensor type
  void calcPrice();

  /// Get Sensor Type
  const char *getType() const;

  /// Get Sensor Cost
  float getExtraCost() const;

  /// Set Sensor Type
  void setType(const char *type);

  /// Set Sensor Type
  void setExtraCost(float cost) { m_extracost = cost; }

  /// Get GPS Count
  static int getGpsCnt();

  /// Reset GPS Count
  static void resetGpsCnt();

  /// Get Camera Count
  static int getCameraCnt();

  /// Reset Camera Count
  static void resetCameraCnt();

  /// Reset Lidar Count
  static int getLidarCnt();

  /// Reset Lidar Count
  static void resetLidarCnt();

  /// Reset Radar Count
  static int getRadarCnt();

  /// Reset Radar Count
  static void resetRadarCnt();

  /// Comparison Operator
  friend bool operator==(const Sensor &a, const Sensor &b);

private:
  char m_type[STR_MAX];
  float m_extracost;
  // Static
  static int gps_cnt;
  static int camera_cnt;
  static int lidar_cnt;
  static int radar_cnt;
};
#endif