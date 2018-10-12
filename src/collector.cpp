#include "collector.h"

void Collector::begin(String _prefix)
{
    this->prefix = _prefix;
    this->sensorCount = 0;
    this->sampleCount = 0;
}

void Collector::addSensor(ISensor *_sensor)
{
    if (this->sensorCount < MAX_SENSORS)
    {
        this->sensors[this->sensorCount] = _sensor;
        this->sensorCount++;
    }
}

void Collector::addReporter(IReporter *_reporter)
{
    if (this->reporterCount < MAX_REPORTERS)
    {
        this->reporters[this->reporterCount] = _reporter;
        this->reporterCount++;
    }
}

void Collector::collect()
{
    for (uint8_t i = 0; i < this->sensorCount; i++)
    {
        while (this->sensors[i]->samplesLeft() > 0)
        {
            this->addSample(this->sensors[i]->getSample());
        }
    }
}

void Collector::report()
{
    for (uint8_t i = 0; i < this->sampleCount; i++)
    {
        for (uint8_t j = 0; j < this->reporterCount; j++)
        {
            this->reporters[j]->report(this->samples[i]);
        }
    }
    this->sampleCount = 0;
}

void Collector::addSample(Sample _sample)
{
    if (this->sampleCount < MAX_SAMPLES)
    {
        this->samples[this->sampleCount] = _sample;
        this->sampleCount++;
    }
}