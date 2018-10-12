#pragma once
#include "application.h"
#include "reporter.h"

class ReporterParticle : public IReporter
{
  public:
    void report(Sample _sample);
    void setPrefix(String _prefix);
  private:
    String prefix;
};