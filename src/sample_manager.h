#pragma once

#include "spark_wiring_vector.h"
#include "sample_reporter.h"

class SampleManager
{
  public:
    void addReporter(ISampleReporter reporter);
    void process();
  private:
    spark::Vector<ISampleReporter*> reporters;
};