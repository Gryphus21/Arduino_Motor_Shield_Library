#include "Channel.h"


Channel::Channel() {
	// Empty
}


void Channel::init(uint8_t chn_direction_pin, uint8_t chn_speed_pin, uint8_t chn_brake_pin, uint8_t chn_sens_pin) {
	g_chn_direction_pin = chn_direction_pin;
    g_chn_speed_pin = chn_speed_pin;
    g_chn_brake_pin = chn_brake_pin;
    g_chn_sens_pin = chn_sens_pin;

	pinMode(chn_direction_pin, OUTPUT);
    pinMode(chn_speed_pin, OUTPUT);
    pinMode(chn_brake_pin, OUTPUT);

    digitalWrite(chn_direction_pin, FORWARD); // Direction FORWARD
    digitalWrite(chn_speed_pin, 0); // Speed 0
    digitalWrite(chn_brake_pin, BRAKE_ENABLE); // Brake ON
}


// Set
void Channel::setCurrentProtection(float value) {
    if (value > L298P_MAX_CURRENT_SINGLE_CHANNEL) 
        value = L298P_MAX_CURRENT_SINGLE_CHANNEL;
    else if (value < 0)
        value = 0; 

    if (Channel::getCurrent() >= value && !Channel::getBrake()) {
        Channel::setBrake(BRAKE_ENABLE);
        //Serial.println("OVER CURRENT! Brake Enable");

    } else if (Channel::getBrake()) {
        Channel::setBrake(BRAKE_DISABLE);
        //Serial.println("CURRENT OK. Brake Disable");
    }
}

void Channel::setMaxCurrentProtection() {
    Channel::setCurrentProtection(L298P_MAX_CURRENT_SINGLE_CHANNEL);
}

void Channel::setDirection(uint8_t value) {
	direction = Channel::checkValue(value);
	digitalWrite(g_chn_direction_pin, direction);
}

void Channel::setSpeed(uint8_t value) {
	speed = value;
 	analogWrite(g_chn_speed_pin, speed);
}

void Channel::setBrake(uint8_t value) {
	brake = Channel::checkValue(value);
	digitalWrite(g_chn_brake_pin, brake);
}


// Get
uint8_t Channel::getDirection() {
	return direction;
}

uint8_t Channel::getSpeed() {
	return speed;
}

uint8_t Channel::getBrake() {
	return brake;
}



// Get Pins
uint8_t Channel::getDirectionPin() {
	return g_chn_direction_pin;
}

uint8_t Channel::getSpeedPin() {
	return g_chn_speed_pin;
}

uint8_t Channel::getBrakePin() {
	return g_chn_brake_pin;
}



// Current sensing
uint16_t Channel::getADC() {
	return analogRead(g_chn_sens_pin) - ADC_ADJUST;
}

float Channel::getCurrent() {
    float currentVolts = Channel::getADC() * (5.0 / 1024.0);
    return currentVolts / VOLT_X_AMPS;
}


// Private method
uint8_t Channel::checkValue(uint8_t value) {
    if (value > HIGH)
        value = HIGH;
    else if (value < LOW)
        value = LOW;
    return value;
}