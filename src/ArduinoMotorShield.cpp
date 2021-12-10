#include "ArduinoMotorShield.h"


ArduinoMotorShield::ArduinoMotorShield() {
    // Empty
}

void ArduinoMotorShield::begin(uint8_t chn_a_direction_pin=CHN_A_DIRECTION_PIN, 
                               uint8_t chn_a_speed_pin=CHN_A_SPEED_PIN, 
                               uint8_t chn_a_brake_pin=CHN_A_BRAKE_PIN,
                               uint8_t chn_a_sens_pin=CHN_A_SENS_PIN,

                               uint8_t chn_b_direction_pin=CHN_B_DIRECTION_PIN, 
                               uint8_t chn_b_speed_pin=CHN_B_SPEED_PIN, 
                               uint8_t chn_b_brake_pin=CHN_B_BRAKE_PIN,
                               uint8_t chn_b_sens_pin=CHN_B_SENS_PIN) {

    ArduinoMotorShield::a.init(chn_a_direction_pin, chn_a_speed_pin, chn_a_brake_pin, chn_a_sens_pin);
    ArduinoMotorShield::b.init(chn_b_direction_pin, chn_b_speed_pin, chn_b_brake_pin, chn_b_sens_pin);
}