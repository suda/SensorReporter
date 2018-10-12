#include "sensor_analog_pin.h"

void SensorAnalogPin::begin(uint8_t _pin, String _name)
{
    this->pin = _pin;
    this->name = _name;
    pinMode(this->pin, INPUT);
    this->_samplesLeft = 1;
}

Sample SensorAnalogPin::getSample()
{
    struct Sample sample;
    sample.name = this->name;
    sample.value = String(analogRead(this->pin));
    this->_samplesLeft--;
    return sample;
}

uint8_t SensorAnalogPin::samplesLeft()
{
    uint8_t samplesLeft = this->_samplesLeft;
    if (this->_samplesLeft == 0)
    {
        this->_samplesLeft = 1;
    }
    return samplesLeft;
}