#include <ArduinoMotorShield.h>

ArduinoMotorShield motorShield = ArduinoMotorShield();

void setup() {
   Serial.begin(9600);
   motorShield.begin(); // Initialize the board by choosing the input pins for channel control, if no parameters are specified the default pins will be used.
   
   // For channel 'a'
   motorShield.a.setDirection(FORWARD); // Sets the direction between 'FORWARD' and 'BACKWARD'.
   motorShield.a.setSpeed(255); // Set a speed between 0 and 255.
   motorShield.a.setBrake(BRAKE_DISABLE); // Choose whether to engage the brake.

   // For channel 'b'
   motorShield.b.setDirection(FORWARD); // Sets the direction between 'FORWARD' and 'BACKWARD'.
   motorShield.b.setSpeed(255); // Set a speed between 0 and 255.
   motorShield.b.setBrake(BRAKE_DISABLE); // Choose whether to engage the brake.
}

void loop() {
  motorShield.a.setDirection(BACKWARD);
  motorShield.b.setDirection(BACKWARD);
  delay(1000);
  
  motorShield.a.setDirection(FORWARD);
  motorShield.b.setDirection(FORWARD);
  delay(1000);

  motorShield.a.setBrake(BRAKE_ENABLE);
  delay(1000);

  motorShield.a.setBrake(BRAKE_DISABLE);
  delay(1000);
  
  /* for (int i=0; i<256; i++) {
    motorShield.a.setSpeed(i);
    delay(10);
  } */
}
