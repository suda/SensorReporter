#include "sensor_moisture.h"

void SensorMoisture::begin(uint8_t _analogPin, uint8_t _enablePin)
{
    this->analogPin = _analogPin;
    this->enablePin = _enablePin;
    pinMode(this->analogPin, INPUT);
    pinMode(this->enablePin, OUTPUT);
    this->_samplesLeft = 1;
}

Sample SensorMoisture::getSample()
{
    // Turn on the sensor
    digitalWrite(this->enablePin, HIGH);
    delay(50);
    struct Sample sample;
    sample.name = "moisture";
    sample.value = String(analogRead(this->analogPin));
    this->_samplesLeft--;
    delay(50);
    // Turn off the sensor
    digitalWrite(this->enablePin, LOW);
    return sample;
}

uint8_t SensorMoisture::samplesLeft()
{
    uint8_t samplesLeft = this->_samplesLeft;
    if (this->_samplesLeft == 0)
    {
        this->_samplesLeft = 1;
    }
    return samplesLeft;
}