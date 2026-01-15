#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include <Arduino.h>
#include <BleKeyboard.h>


class Joystick {
private:
  uint8_t frontPin;
  uint8_t backPin;
  uint8_t leftPin;
  uint8_t rightPin;

  //Se utiliza para que solo se ejecute una accion una sola vez, aunque se deje presioanada la tecla
  bool isFrontDown;
  bool isBackDown;
  bool isLeftDown;
  bool isRightDown;


public:
  Joystick(uint8_t _frontPin, uint8_t _backPin, uint8_t _leftPin, uint8_t _rightPin);
  ~Joystick();

  void Init();
  void Loop(BleKeyboard _bleKeyboard);
  bool isPressed(uint8_t _directionPin);
  bool Read(uint8_t _directionPin);
};




#endif
