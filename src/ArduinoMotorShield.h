#ifndef ARDUINO_MOTOR_SHIELD_H
#define ARDUINO_MOTOR_SHIELD_H

#include <Arduino.h>
#include "Channel.h"
#include "Constants.h"

// Channel A
#define CHN_A_DIRECTION_PIN 12
#define CHN_A_SPEED_PIN 3
#define CHN_A_BRAKE_PIN 9
#define CHN_A_SENS_PIN A0

// Channel B
#define CHN_B_DIRECTION_PIN 13
#define CHN_B_SPEED_PIN 11
#define CHN_B_BRAKE_PIN 8
#define CHN_B_SENS_PIN A1

// Built-in pins
#define IN3_PIN 3
#define IN2_PIN 2
#define OUT5_PIN 5
#define OUT6_PIN 6


class ArduinoMotorShield {
    
public:
    ArduinoMotorShield();

    void begin(uint8_t chn_a_direction_pin=CHN_A_DIRECTION_PIN, 
               uint8_t chn_a_speed_pin=CHN_A_SPEED_PIN,
               uint8_t chn_a_brake_pin=CHN_A_BRAKE_PIN,
               uint8_t chn_a_sens_pin=CHN_A_SENS_PIN,

               uint8_t chn_b_direction_pin=CHN_B_DIRECTION_PIN, 
               uint8_t chn_b_speed_pin=CHN_B_SPEED_PIN, 
               uint8_t chn_b_brake_pin=CHN_B_BRAKE_PIN,
               uint8_t chn_b_sens_pin=CHN_B_SENS_PIN);

    Channel a = Channel();
    Channel b = Channel();
};
#endif