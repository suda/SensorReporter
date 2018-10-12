#pragma once
#include "application.h"
#include "sensor.h"

class SensorAnalogPin : public ISensor {
public:
  void begin(uint8_t _pin, String _name);
  Sample getSample();
  uint8_t samplesLeft();

private:
  uint8_t pin;
  String name;
};