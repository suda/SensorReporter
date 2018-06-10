#include <SparkFunHTU21D.h>
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#include <ArduinoJson.h>

#include "rgb_signal.h"
#include "sample_reporter.h"
#include "sample_manager.h"
#include "temperature_reporter.h"
#include "humidity_reporter.h"

#define BUFFER_SIZE 200

byte homeAssistantIp[] = {10, 0, 0, 31};
int homeAssistantPort = 8123;
String sensorLocation = String("Outside");

RGBSignal rgbSignal;
SampleManager sampleManager;
TemperatureReporter temperatureReporter;
HumidityReporter humidityReporter;

HTU21D htu;

TCPClient client;

int strLen;

void setup() {
  Serial.begin(9600);

  rgbSignal.begin();

  htu.begin();
  temperatureReporter.begin(htu);
  sampleManager.addReporter(temperatureReporter);
  humidityReporter.begin(htu);
  // sampleManager.addReporter(humidityReporter);
}

void reportSensor(char *name, float value, char *unit) {
  String sName = String(name);
  String sValue = String(value, 2);

  // Print on serial
  Serial.print(name);
  Serial.print(": ");
  Serial.print(value);
  Serial.println(unit);

  // Publish Particle event
  String eventName = sensorLocation;
  eventName.concat("_");
  eventName.concat(sName);
  eventName.toLowerCase();
  Particle.publish(eventName, sValue, PRIVATE);

  // eventName.concat("_p");
  // Particle.publish(eventName, sValue, PUBLIC);
  return;

  // Build JSON
  char bBody[BUFFER_SIZE];

  StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["state"] = value;

  JsonObject& attributes = root.createNestedObject("attributes");
  attributes["unit_of_measurement"] = unit;

  // Build friendly name
  String friendlyName = sensorLocation;
  friendlyName.concat(" ");
  friendlyName.concat(sName);

  strLen = friendlyName.length() + 1;
  char bFriendlyName[strLen];
  friendlyName.toCharArray(bFriendlyName, strLen);
  attributes["friendly_name"] = bFriendlyName;

  // Make request to Home Assistant
  String url = String("/api/states/sensor.");
  url.concat(sensorLocation);
  url.concat("_");
  url.concat(sName);
  url.toLowerCase();

  Particle.process();

  if (client.connect(homeAssistantIp, 8123)) {
    String content;
    root.printTo(content);

    client.println("POST " + url + " HTTP/1.0");
    client.println("Host: raspberrypi.local");
    client.println("Content-Length: " + String(content.length()));
    client.println("Content-Type: application/json");
    client.println();
    client.println(content);

    while (!client.available()) {
      Particle.process();
    }

    String response;
    while (client.available()) {
      char c = client.read();
      response += c;
      Particle.process();
    }
    /*rgbSignal.blinkOk();*/
    if (response.startsWith(String("HTTP/1.0 200 OK"))) {
      rgbSignal.blinkOk();
    } else {
      rgbSignal.blinkError(2);
    }

    if (!client.connected()) {
      client.stop();
    }
  } else {
    Serial.println("Failed to report sensor");
    rgbSignal.blinkError(3);
  }
}

void loop() {
  float h = humidityReporter.getSample();
  float t = temperatureReporter.getSample();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from  sensor!");
  } else {
    reportSensor("Temperature", t, "°C");
    //delay(1000);
    reportSensor("Humidity", h, "%");
  }

  delay(5000);
}
