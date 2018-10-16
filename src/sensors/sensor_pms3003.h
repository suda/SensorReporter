#pragma once
#include "application.h"
#include "sensor.h"
#include <PMS3003.h>

class SensorPMS3003 : public ISensor {
public:
  void begin();
  Sample getSample();
  uint8_t samplesLeft();

private:
  PMS3003 pms;
  PM pm;
};