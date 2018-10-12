#include "reporter_serial.h"

void ReporterSerial::begin(unsigned long _baudrate)
{
    Serial.begin(_baudrate);
}

void ReporterSerial::report(Sample _sample)
{
    Serial.print(_sample.name);
    Serial.print("=");
    Serial.println(_sample.value);
}