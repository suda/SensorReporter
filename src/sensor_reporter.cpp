#include "sensor_reporter.h"

#include "collector.h"
Collector collector;

#if defined(SENSOR_ANALOG_PIN_1)
#include "sensors/sensor_analog_pin.h"
SensorAnalogPin sensorAnalogPin1;
#endif

#if defined(SENSOR_HTU21D)
#include "sensors/sensor_htu21d.h"
SensorHtu21D sensorHtu21D;
#endif

#if defined(REPORTER_SERIAL_BAUDRATE)
#include "reporters/reporter_serial.h"
ReporterSerial reporterSerial;
#endif

#if defined(REPORTER_PARTICLE)
#include "reporters/reporter_particle.h"
ReporterParticle reporterParticle;
#endif

void SensorReporter::begin()
{
    collector.begin(SAMPLE_PREFIX);

#if defined(SENSOR_ANALOG_PIN_1)
    sensorAnalogPin1.begin(SENSOR_ANALOG_PIN_1, SENSOR_ANALOG_PIN_1_NAME);
    collector.addSensor(&sensorAnalogPin1);
#endif

#if defined(SENSOR_HTU21D)
    sensorHtu21D.begin();
    collector.addSensor(&sensorHtu21D);
#endif

#if defined(REPORTER_SERIAL_BAUDRATE)
    reporterSerial.begin(REPORTER_SERIAL_BAUDRATE);
    collector.addReporter(&reporterSerial);
#endif

#if defined(REPORTER_PARTICLE)
    collector.addReporter(&reporterParticle);
#endif
}

void SensorReporter::loop()
{
    collector.collect();
    collector.report();
    delay(REPORTING_INTERVAL);
}