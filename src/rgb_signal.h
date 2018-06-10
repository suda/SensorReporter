#pragma once

#define RGB_BRIGHTNESS 16

class RGBSignal
{
  public:
    void begin();
    void blinkOk();
    void blinkError(char count);
};