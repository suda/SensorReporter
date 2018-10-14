
<h1 align="center">
	<br>
	<img height="300" alt="dvsync" src="media/SensorReporter.png">
	<br>
	<br>
	<br>
</h1>

> `SensorReporter` is the quickest way to fetch and publish data from IoT sensors.

<hr />

# Installation & configuration

`SensorReporter` is an Arduino Library but was only tested with [Particle ecosystem](https://docs.particle.io/guide/tools-and-features/libraries/).

**Note:** if you tested it with any other platforms, please create a PR with instructions to let everyone know!

1. Using the [Web IDE](https://docs.particle.io/guide/getting-started/build/photon/#using-libraries), [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#using-community-libraries) or the [CLI](https://docs.particle.io/guide/tools-and-features/cli/photon/#using-libraries) add the `SensorReporter` to your project.
2. Create a [`sr-config.h` file](#sr-configh-file) and configure all connected sensors and reporters
3. In your main file, Include and instantiate `SensorReporter`:
    ```c
    #include "sensor_reporter.h"
    SensorReporter sensorReporter;
    ```
4. In `setup()` function initalize all sensors and reporters:
    ```c
    void setup()
    {
        sensorReporter.begin();
    }
    ```
5. In `loop()` function request a report:
    ```c
    void loop()
    {
        sensorReporter.loop();
    }
    ```
6. If you're using external library, add it to the `library.properties` file as well

# Supported sensors & reporters

**Note:** if you want to implement additional sensors or reporters, please submit a PR!

### Sensors 

* Analog input using built in ADC
* HTU21D temperature & humidity sensor via [SparkFun_HTU21D_Breakout_Arduino_Library](https://github.com/sparkfun/SparkFun_HTU21D_Breakout_Arduino_Library)

### Reporters

* Printing to serial port in `NAME=VALUE` format
* Publishing [Particle events](https://docs.particle.io/reference/firmware/photon/#particle-publish-)

# `sr-config.h` file

This header file is used to configure the `SensorReporter`. To disable a sensor or reporter, comment out the relevant lines. Here's a reference file:

```js
// ***** GENERAL SETTINGS *****
 
// All sample names will be prefixed with this string
#define SAMPLE_PREFIX "home_"
// How many miliseconds wait before next report
#define REPORTING_INTERVAL 10000

// ***** SENSORS *****

// First built-in ADC pin (in the future, you'll be able to pull more pins)
#define SENSOR_ANALOG_PIN_1 A0
// Name to report this pin as
#define SENSOR_ANALOG_PIN_1_NAME "soil"

// HTU21D temperature and humidity sensor
#define SENSOR_HTU21D

// ***** REPORTERS *****

// Serial port reporter
#define REPORTER_SERIAL_BAUDRATE 9600

// Particle event reporter
#define REPORTER_PARTICLE
```

# Implementing new reporters or sensors

0. Take a peek at [`src/sensors`](src/sensors) and [`src/reporters`](src/reporters) directories
1. Create a class that inherits `ISensor` or `IReporter` and implements all virtual methods
1. In `sensor_reporter.cpp`:
    * add declarations of your classes in the beginning
    * in the `begin()` function:
        * initialize your class
        * add it to collector with `collector.addSensor()` or `collector.addReporter()`

Once it's working, please create a PR so more people can use it :) [All contributions (no matter if small or big) are always welcome!](https://contributionswelcome.org/)


# Attributions
* Thermometer, Wind & Drops icons by Luis Rodrigues from the Noun Project
* Serial Port icon by Dalpat Prajapati from the Noun Project
