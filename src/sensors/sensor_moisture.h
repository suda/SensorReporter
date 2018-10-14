#pragma once
#include "application.h"
#include "sensor.h"

class SensorMoisture : public ISensor
{
public:
  /*
    @param _analogPin ADC pin to get the value from
    @param _enablePin any pin connected Vcc pin of the sensor
  */
  void begin(uint8_t _analogPin, uint8_t _enablePin);
  Sample getSample();
  uint8_t samplesLeft();

private:
  uint8_t analogPin;
  uint8_t enablePin;
};