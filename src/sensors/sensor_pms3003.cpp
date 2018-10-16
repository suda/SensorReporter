#include "sensor_pms3003.h"
#include "ArduinoJson.h"

void SensorPMS3003::begin()
{
    this->pms.begin();
    this->_samplesLeft = 1;
}

Sample SensorPMS3003::getSample()
{
    struct Sample sample;
    this->pm = this->pms.read();
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &root = jsonBuffer.createObject();
    root["cf10"] = this->pm.cf10;
    root["cf25"] = this->pm.cf25;
    root["cf100"] = this->pm.cf100;
    root["at10"] = this->pm.at10;
    root["at25"] = this->pm.at25;
    root["at100"] = this->pm.at100;

    sample.name = "air";
    char jsonChar[100];
    root.printTo(jsonChar);
    sample.value = String(jsonChar);

    this->_samplesLeft--;
    return sample;
}

uint8_t SensorPMS3003::samplesLeft()
{
    uint8_t samplesLeft = this->_samplesLeft;
    if (this->_samplesLeft == 0)
    {
        this->_samplesLeft = 1;
    }
    return samplesLeft;
}