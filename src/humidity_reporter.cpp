#include "humidity_reporter.h"

void HumidityReporter::begin(HTU21D _htu)
{
    this->htu = _htu;
}

float HumidityReporter::getSample(void)
{
    return this->htu.readHumidity();
}