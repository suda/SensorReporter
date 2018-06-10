#pragma once

#include <SparkFunHTU21D.h>
#include "sample_reporter.h"

class TemperatureReporter: public ISampleReporter {
    public:
		void begin(HTU21D _htu);
        float getSample();
    private:
        HTU21D htu;
};