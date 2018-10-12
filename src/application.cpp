// When debugging Wifi seems to have issues connecting, so disable it
#if defined(USE_SWD_JTAG)
#include "application.h"
SYSTEM_MODE(MANUAL);
#endif

#define SAMPLE_PREFIX "office_"
#define REPORTING_INTERVAL 10000

#define SENSOR_ANALOG_PIN_1 A0
#define SENSOR_ANALOG_PIN_1_NAME "soil"
#define SENSOR_HTU21D

#define REPORTER_SERIAL_BAUDRATE 9600

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

void setup()
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
}

void loop()
{
    collector.collect();
    collector.report();
    delay(REPORTING_INTERVAL);
}