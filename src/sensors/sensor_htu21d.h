#pragma once
#include "application.h"
#include "sensor.h"
#include <SparkFunHTU21D.h>

class SensorHtu21D : public ISensor {
public:
  void begin();
  Sample getSample();
  uint8_t samplesLeft();

private:
  HTU21D htu;
};