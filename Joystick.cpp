#include <stdint.h>
#include "HardwareSerial.h"
#include "esp32-hal-gpio.h"
#include "Joystick.h"

Joystick::Joystick(uint8_t _frontPin, uint8_t _backPin, uint8_t _leftPin, uint8_t _rightPin) {
  frontPin = _frontPin;
  backPin = _backPin;
  leftPin = _leftPin;
  rightPin = _rightPin;
}

Joystick::~Joystick() {
}

void Joystick::Init() {
  pinMode(frontPin, INPUT_PULLUP);
  pinMode(backPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
}

void Joystick::Loop(BleKeyboard _bleKeyboard) {
  // Frente
  if (isPressed(frontPin)) {
    _bleKeyboard.press('w');
    isFrontDown = true;
  } else if (isFrontDown) {
    Serial.println("W ");
    _bleKeyboard.release('w');
    isFrontDown = false;
  }

  //Back
  if (isPressed(backPin)) {
    _bleKeyboard.press('s');
    isBackDown = true;
  } else if (isBackDown) {
    _bleKeyboard.release('s');
    Serial.println("S ");
    isBackDown = false;
  }

  //Left
  if (isPressed(leftPin)) {
    _bleKeyboard.press('a');
    isLeftDown = true;
  } else if (isLeftDown) {
    _bleKeyboard.release('a');
    Serial.println("A ");
    isLeftDown = false;
  }

  //Right
  if (isPressed(rightPin)) {
    _bleKeyboard.press('d');
    isRightDown = true;
  } else if (isRightDown) {
    _bleKeyboard.release('d');
    isRightDown = false;
  }
 
}

bool Joystick::Read(uint8_t _directionPin) {
  return digitalRead(_directionPin);
}

bool Joystick::isPressed(uint8_t _directionPin) {
  if (Read(_directionPin) == LOW) {
    return true;
  } else return false;
}
