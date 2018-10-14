/*
    This example reports HTU21D temperature and humidity sensor
    to serial port and publishes Particle event.
 */
#define SAMPLE_PREFIX "outside_"
#define REPORTING_INTERVAL 10000

// #define SENSOR_ANALOG_PIN_1 A0
// #define SENSOR_ANALOG_PIN_1_NAME "soil"
#define SENSOR_HTU21D

#define REPORTER_SERIAL_BAUDRATE 9600
#define REPORTER_PARTICLE