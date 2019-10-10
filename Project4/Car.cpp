#include "Car.h"

Car::Car()
    : m_year(0), m_sensor_cnt(0), m_baseprice(0.0), m_finalprice(0.0),
      m_available(true) {
  myStringCopy(m_make, "");
  myStringCopy(m_model, "");
  myStringCopy(m_owner, "");
}

Car::Car(char *make, char *model, int year, float baseprice, Sensor *sensors,
         int sensor_cnt)
    : m_year(year), m_baseprice(baseprice) {
  myStringCopy(m_make, make);
  myStringCopy(m_model, model);
  setSensors(sensors, sensor_cnt);
  myStringCopy(m_owner, "");
}

Car::Car(const Car &car)
    : m_year(car.m_year), m_baseprice(car.m_baseprice),
      m_finalprice(car.m_finalprice), m_available(car.m_available) {
  myStringCopy(m_make, car.m_make);
  myStringCopy(m_model, car.m_model);
  myStringCopy(m_owner, car.m_owner);
  setSensors(car.m_sensors, car.m_sensor_cnt);
}

const char *Car::getMake(char *dest) const { return m_make; }

const char *Car::getModel(char *dest) const { return m_model; }

int Car::getYear() const { return m_year; };

const Sensor *Car::getSensors() const { return m_sensors; }

int Car::getSensorCnt() const { return m_sensor_cnt; }

float Car::getBaseprice() const { return m_baseprice; }

float Car::getFinalprice() const { return m_finalprice; }

bool Car::getAvailable() const { return m_available; }

void Car::setMake(char *make) { myStringCopy(m_make, make); }

void Car::setModel(char *model) { myStringCopy(m_model, model); }

void Car::setYear(int year) { m_year = year; }

void Car::setSensors(const Sensor *sensors, int sensor_cnt) {
  for (int i = 0; i != sensor_cnt; i++) {
    *(m_sensors + i) = *(sensors + i);
  }
  m_sensor_cnt = sensor_cnt;
}

void Car::setBaseprice(float baseprice) { m_baseprice = baseprice; }

void Car::setFinalprice(float finalprice) { m_finalprice = finalprice; }

void Car::setAvailable(bool available) { m_available = available; }

void Car::setOwner(char *owner) { myStringCopy(m_owner, owner); }

void Car::updatePrice() {
  float price = m_baseprice;
  for (int i = 0; i != m_sensor_cnt; i++) {
    price += (m_sensors + i)->getExtraCost();
  }
  m_finalprice = price;
}

void Car::print(std::ostream &stream) const {
  stream << m_year << " " << m_make << " " << m_model
         << "    \tBase: " << m_baseprice << "\t";
  if (m_sensor_cnt > 0) {
    stream << "With {";
    for (int i = 0; i != m_sensor_cnt; i++) {
      stream << (m_sensors + i)->getType();
      if (i != m_sensor_cnt - 1) {
        stream << " ";
      }
    }
    stream << "}: " << m_finalprice;
  } else {
    stream << "\t\t\t";
  }

  stream << "\t\tAvailable: " << std::boolalpha << m_available << "\n";
}

float Car::estimateCost(int days) const { return m_finalprice * days; }

Car &Car::operator+(const Sensor &sensor) {
  if (m_sensor_cnt < SENSOR_NUM) {
    *(m_sensors + m_sensor_cnt) = sensor;
    m_sensor_cnt++;
  }
  updatePrice();
  return *this;
}

Car &Car::operator+(const char *owner) {
  myStringCopy(m_owner, owner);
  m_available = false;
  updatePrice();
  return *this;
}

std::istream &operator>>(std::istream &stream, Car &car) {
  char input[STR_MAX];
  stream >> car.m_year >> car.m_make >> car.m_model >> car.m_baseprice >> input;

  int i = 0;
  trimStart(input, input, '{');
  bool end = trimEnd(input, input, '}');

  if (myStringLength(input) != 0) {
    *(car.m_sensors + i) = Sensor(input);
    i++;
  }

  while (!end) {
    stream >> input;
    end = trimEnd(input, input, '}');
    *(car.m_sensors + i) = Sensor(input);
    i++;
  }

  stream >> car.m_available;
  if (stream.peek() == ' ') {
    stream >> car.m_owner;
  }

  car.m_sensor_cnt = i;
  car.updatePrice();

  return stream;
}