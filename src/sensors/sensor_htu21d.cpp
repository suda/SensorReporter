#include "sensor_htu21d.h"

void SensorHTU21D::begin()
{
    htu.begin();
    this->_samplesLeft = 2;
}

Sample SensorHTU21D::getSample()
{
    struct Sample sample;
    if (this->_samplesLeft == 2)
    {
        sample.name = "temperature";
        sample.value = String(this->htu.readTemperature());
    }
    else
    {
        sample.name = "humidity";
        sample.value = String(this->htu.readHumidity());
    }

    this->_samplesLeft--;
    return sample;
}

uint8_t SensorHTU21D::samplesLeft()
{
    uint8_t samplesLeft = this->_samplesLeft;
    if (this->_samplesLeft == 0)
    {
        this->_samplesLeft = 2;
    }
    return samplesLeft;
}