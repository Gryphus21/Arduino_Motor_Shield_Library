#ifndef CHANNEL_H
#define CHANNEL_H

#include <Arduino.h>
#include "Constants.h"

// Direction
#define FORWARD HIGH
#define BACKWARD LOW

// Brake
#define BRAKE_ENABLE HIGH
#define BRAKE_DISABLE LOW

// Current calc
#define VOLT_X_AMPS 1.65
#define ADC_ADJUST 15


class Channel {

private:
    uint8_t g_chn_direction_pin;
    uint8_t g_chn_speed_pin;
    uint8_t g_chn_brake_pin;
    uint8_t g_chn_sens_pin;

    uint8_t direction;
    uint8_t speed;
    uint8_t brake;

    uint8_t checkValue(uint8_t value);

public:
    Channel();

    void init(uint8_t chn_direction_pin, uint8_t chn_speed_pin, uint8_t chn_brake_pin, uint8_t chn_sens_pin);

    void setCurrentProtection(float value);
    void setMaxCurrentProtection();

    void setDirection(uint8_t value);
    void setSpeed(uint8_t value);
    void setBrake(uint8_t value);

    uint8_t getDirection();
    uint8_t getSpeed();
    uint8_t getBrake();

    uint8_t getDirectionPin();
    uint8_t getSpeedPin();
    uint8_t getBrakePin();

    uint16_t getADC();
    float getCurrent();
};
#endif