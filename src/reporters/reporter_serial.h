#pragma once
#include "application.h"
#include "reporter.h"

class ReporterSerial : public IReporter
{
  public:
    void begin(unsigned long _baudrate);
    void report(Sample _sample);
    void setPrefix(String _prefix);
  private:
    String prefix;
};