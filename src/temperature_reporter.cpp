#include "temperature_reporter.h"

void TemperatureReporter::begin(HTU21D _htu) {
    this->htu = _htu;
}

float TemperatureReporter::getSample(void) {
    return this->htu.readTemperature();
}