#include "Arduino.h"
#include "DRV8837C.h"

DRV8837C::DRV8837C(uint8_t pin_nSleep, uint8_t pin_in1, uint8_t pin_in2, bool invertDirection = false) {
  _pin_nSleep = pin_nSleep;
  _pin_in1 = invertDirection ? pin_in2 : pin_in1;
  _pin_in2 = invertDirection ? pin_in1 : pin_in2;

  initialize();
}

void DRV8837C::initialize() {
  pinMode(_pin_nSleep,INPUT);

  disable();
}

void DRV8837C::enable() {
  setEnableState(HIGH);
}

void DRV8837C::disable() {
  setEnableState(LOW);
}

bool DRV8837C::getEnableState() {
  return _enabled;
}

void DRV8837C::drive(uint8_t magnitude, bool direction = FORWARD) {
  analogWrite(_pin_in2,direction ? 0 : magnitude);
  analogWrite(_pin_in1,direction ? magnitude : 0);
}

void DRV8837C::off() {
  drive(0);
  drive(0);
}

void DRV8837C::brake() {
  drive(255);
  drive(255);
}

void DRV8837C::setEnableState(bool enabled) {
  _enabled = enabled;

  digitalWrite(_pin_nSleep,_enabled);
}
