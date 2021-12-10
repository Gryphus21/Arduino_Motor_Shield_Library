#include <ArduinoMotorShield.h>

ArduinoMotorShield motorShield = ArduinoMotorShield();

void setup() {
   Serial.begin(9600);
   motorShield.begin(); // Initialize the board by choosing the input pins for channel control, if no parameters are specified the default pins will be used.
   
   motorShield.a.setDirection(FORWARD); // Sets the direction between 'FORWARD' and 'BACKWARD'.
   motorShield.a.setSpeed(255); // Set a speed between 0 and 255.
   motorShield.a.setBrake(BRAKE_DISABLE); // Choose whether to engage the brake.

   Serial.println("Direction: " + String(motorShield.a.getDirection())); // Gets the set direction.
   Serial.println("Speed: " + String(motorShield.a.getSpeed())); // Gets the set speed.
   Serial.println("Brake: " + String(motorShield.a.getBrake()) + "\n\n"); // Gets the set brake
}

void loop() {
  Serial.println("Current: " + String(motorShield.a.getCurrent()) + "A"); // Get the current for channel 'a'
  Serial.println("ADC: " + String(motorShield.a.getADC()) + "\n"); // The raw analog read value

  // It allows you to set a board protection current threshold, for channel 'a', the type to use is float.
  // This method will have to be invoked every time for checking the current.
  // You can use 'L298P_MAX_CURRENT_SINGLE_CHANNEL' to set the maximum current value for the single channel.
  motorShield.a.setCurrentProtection(L298P_MAX_CURRENT_SINGLE_CHANNEL);
  delay(1000);
}
