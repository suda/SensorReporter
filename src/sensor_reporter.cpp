#include "sensor_reporter.h"

#include "collector.h"
Collector collector;

/*************************************
 * SENSOR DECLARATION                *
 *************************************/

#if defined(SENSOR_ANALOG_PIN_1)
#include "sensors/sensor_analog_pin.h"
SensorAnalogPin sensorAnalogPin1;
#endif

#if defined(SENSOR_MOISTURE_ANALOG_PIN)
#include "sensors/sensor_moisture.h"
SensorMoisture sensorMoisture;
#endif

#if defined(SENSOR_HTU21D)
#include "sensors/sensor_htu21d.h"
SensorHtu21D sensorHtu21D;
#endif

#if defined(SENSOR_PMS3003)
#include "sensors/sensor_pms3003.h"
SensorPMS3003 sensorPMS3003;
#endif

/*************************************
 * REPORTER DECLARATION              *
 *************************************/

#if defined(REPORTER_SERIAL_BAUDRATE)
#include "reporters/reporter_serial.h"
ReporterSerial reporterSerial;
#endif

#if defined(REPORTER_PARTICLE)
#include "reporters/reporter_particle.h"
ReporterParticle reporterParticle;
#endif

/*************************************
 * BEGIN FUNCTION                    *
 *************************************/

void SensorReporter::begin()
{
    collector.begin(SAMPLE_PREFIX);

#if defined(SENSOR_ANALOG_PIN_1)
    sensorAnalogPin1.begin(SENSOR_ANALOG_PIN_1, SENSOR_ANALOG_PIN_1_NAME);
    collector.addSensor(&sensorAnalogPin1);
#endif

#if defined(SENSOR_MOISTURE_ANALOG_PIN)
    sensorMoisture.begin(SENSOR_MOISTURE_ANALOG_PIN, SENSOR_MOISTURE_ENABLE_PIN);
    collector.addSensor(&sensorMoisture);
#endif

#if defined(SENSOR_HTU21D)
    sensorHtu21D.begin();
    collector.addSensor(&sensorHtu21D);
#endif

#if defined(SENSOR_PMS3003)
    sensorPMS3003.begin();
    collector.addSensor(&sensorPMS3003);
#endif

#if defined(REPORTER_SERIAL_BAUDRATE)
    reporterSerial.begin(REPORTER_SERIAL_BAUDRATE);
    collector.addReporter(&reporterSerial);
#endif

#if defined(REPORTER_PARTICLE)
    collector.addReporter(&reporterParticle);
#endif
}

/*************************************
 * LOOP FUNCTION                     *
 *************************************/

void SensorReporter::loop()
{
    collector.collect();
    collector.report();
    delay(REPORTING_INTERVAL);
}