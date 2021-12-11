
# Arduino_Motor_Shield_Library
This library allows you to better manage the Arduino Motor Shield, this library is not official [Arduino.cc](https://www.arduino.cc/)

## Library
### The methods for ArduinoMotorShield library:

- This method allows you to initialize the interface pins with the motor shield, if no parameters are declared the default pins of the board will be used.
```cpp
void begin(uint8_t chn_a_direction_pin, uint8_t chn_a_speed_pin, uint8_t chn_a_brake_pin, uint8_t chn_a_sens_pin, uint8_t chn_b_direction_pin, uint8_t chn_b_speed_pin, uint8_t chn_b_brake_pin, uint8_t chn_b_sens_pin);
```

<br>

### Channels methods
#### Set methods
Channel methods to manage the two channels, these methods must refer to their respective instances, namely **a** and **b**.<br>
Example:
```cpp
motorShield.a.setCurrentProtection(0.50);
```

- This method allows you to set a protection current for the channel in question, the global constant `L298P_MAX_CURRENT_SINGLE_CHANNEL` can be used to choose the maximum current that a channel can support.<br>
Alternatively there is `void setMaxCurrentProtection();` which does the same thing.
```cpp
void setCurrentProtection(float value);
```

- These three methods respectively set the direction in which the motor should turn, it is possible to use the constants `FORWARD` and `BACKFARD`.
```cpp
void setDirection(uint8_t value);
```

- This method sets the expressible speed with a value from `0` to `255`.
```cpp
void setSpeed(uint8_t value);
```

- This method decides whether the brake is engaged or not, using the `BRAKE_ENABLE` or `BRAKE_DISABLE` constants.
```cpp
void setBrake(uint8_t value);
```
<br>

#### Get methods
- These methods allow you to control the direction, speed and if the brake is engaged, each will have to be compared with their own **constants** for verification.
```cpp
uint8_t getDirection();
uint8_t getSpeed();
uint8_t getBrake();
```

- These methods respectively return the number of the pin used during initialization using the `begin()` method.
```cpp
uint8_t getDirectionPin();
uint8_t getSpeedPin();
uint8_t getBrakePin();
```

- This method returns AnalogRead's raw read value.
```cpp
uint16_t getADC();
```

- This method returns the current for the single channel, expressed in **Amperes**.
```cpp
float getCurrent();
```

<br>

## Other Constants
There are 4 Molex KK type ports on the official shield to which devices can be connected, these ports can be identified by these constants, respectively for I/O pins 2, 3, 5, 6.
```cpp
IN3_PIN
IN2_PIN
OUT5_PIN
OUT6_PIN
```
