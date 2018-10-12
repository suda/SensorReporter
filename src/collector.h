#pragma once
#include "application.h"
#include "sensors/sensor.h"
#include "reporters/reporter.h"

#define MAX_SENSORS 4
#define MAX_REPORTERS 2
#define MAX_SAMPLES 10

class Collector
{
  public:
    void begin(String prefix);
    void addSensor(ISensor *_sensor);
    void addReporter(IReporter *_reporter);
    void collect();
    void report();

  private:
    void addSample(Sample _sample);
    String prefix;
    ISensor *sensors[MAX_SENSORS];
    uint8_t sensorCount;
    IReporter *reporters[MAX_REPORTERS];
    uint8_t reporterCount;
    Sample samples[MAX_SAMPLES];
    uint8_t sampleCount;
};