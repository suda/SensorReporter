#include "application.h"
#include "rgb_signal.h"

void RGBSignal::begin() {
    RGB.brightness(RGB_BRIGHTNESS);
}

void RGBSignal::blinkOk() {
    RGB.control(true);
    for (int i = 0; i < 2; i++)
    {
        RGB.color(0, RGB_BRIGHTNESS, 0);
        delay(200);
        RGB.color(0, 0, 0);
        delay(200);
    }
    RGB.control(false);
}

void RGBSignal::blinkError(char count) {
    RGB.control(true);
    for (int i = 0; i < count; i++)
    {
        RGB.color(RGB_BRIGHTNESS, 0, 0);
        delay(400);
        RGB.color(0, 0, 0);
        delay(400);
    }
    RGB.control(false);
}