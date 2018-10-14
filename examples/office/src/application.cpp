// When debugging Wifi seems to have issues connecting, so disable it
#if defined(USE_SWD_JTAG)
#include "application.h"
SYSTEM_MODE(MANUAL);
#endif

// Step 1: Include and instantiate SensorReporter
#include "sensor_reporter.h"
SensorReporter sensorReporter;

void setup()
{
    // Step 2: Initalize all sensors and reporters
    sensorReporter.begin();
}

void loop()
{
    // Step 3: Keep reporting
    sensorReporter.loop();
}