/**
 * DRV8837C example: Sweep
 * 
 * Sweeps the DRV8837C to ON and OFF in the forward (default) direction.
 * Assumes the device the DRV8837C is driving is a small DC motor.
 */

#include <DRV8837C.h>

#define nSLEEP 7
#define IN2 6
#define IN1 5

DRV8837C motor = DRV8837C(nSLEEP, IN1, IN2);

void setup() {
  motor.enable();
}

void loop() {
  // Ramp up
  for (uint8_t i = 0; i < 255; i++) {
    motor.drive(i, FORWARD);
    delay(10);
  }
 
  delay(1000);

  // Ramp down
  for (uint8_t i = 255; i > 0; i--) {
    motor.drive(i, FORWARD);
    delay(10);
  }

  delay(1000);

  // Explicit turn off
  motor.off();

  delay(5000);

  // Toggle enable state
  if (motor.getEnableState())
    motor.disable();
  else
    motor.enable();
}
