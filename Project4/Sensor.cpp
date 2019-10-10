#include "Sensor.h"

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

bool operator==(const Sensor &a, const Sensor &b) {
  return myStringCompare(a.m_type, b.m_type) == 0;
}

Sensor::Sensor() : m_extracost(0.0) { myStringCopy(m_type, "none"); }

Sensor::Sensor(char *type) {
  myStringCopy(m_type, type);
  calcPrice();
}

Sensor::Sensor(const Sensor &sensor) {
  myStringCopy(m_type, sensor.m_type);
  calcPrice();
}

void Sensor::calcPrice() {
  if (myStringCompare(m_type, "gps") == 0) {
    m_extracost = 5.0;
    gps_cnt++;
  } else if (myStringCompare(m_type, "camera") == 0) {
    m_extracost = 10.0;
    camera_cnt++;
  } else if (myStringCompare(m_type, "lidar") == 0) {
    m_extracost = 15.0;
    lidar_cnt++;
  } else if (myStringCompare(m_type, "radar") == 0) {
    m_extracost = 20.0;
    radar_cnt++;
  } else if (myStringCompare(m_type, "none") == 0) {
    m_extracost = 0.0;
  } else {
    m_extracost = 0.0;
  }
}

const char *Sensor::getType() const { return m_type; }

float Sensor::getExtraCost() const { return m_extracost; }

void Sensor::setType(const char *type) { myStringCopy(m_type, type); }

int Sensor::getGpsCnt() { return gps_cnt; }

void Sensor::resetGpsCnt() { gps_cnt = 0; }

int Sensor::getCameraCnt() { return camera_cnt; }

void Sensor::resetCameraCnt() { camera_cnt = 0; }

int Sensor::getLidarCnt() { return lidar_cnt; }

void Sensor::resetLidarCnt() { lidar_cnt = 0; }

int Sensor::getRadarCnt() { return radar_cnt; }

void Sensor::resetRadarCnt() { radar_cnt = 0; }