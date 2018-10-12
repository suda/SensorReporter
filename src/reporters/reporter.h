#pragma once
#include "application.h"
#include "../types.h"

class IReporter
{
  public:
    virtual void report(Sample _sample);
};