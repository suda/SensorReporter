#pragma once
#include "application.h"
#include "../types.h"

class ISensor
{
  public:
    virtual Sample getSample();
    virtual uint8_t samplesLeft() = 0;
    uint8_t _samplesLeft;
};