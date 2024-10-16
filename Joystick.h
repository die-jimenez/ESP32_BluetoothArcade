//#ifndef Evita posibles errores de duplicar clases
#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include <Arduino.h>
#include <BleKeyboard.h>


class Joystick {
private:
  uint8_t pinButton;
  uint8_t pinLed;
  char key;

  


public:
  //Constructor
  Joystick(uint8_t _frontPin, _backPin, _leftPin, _rightPin;
  //Deconstructor: para eliminarlo
  ~Joystick();

  void Init();
  void Press(BleKeyboard _bleKeyboard);
  bool isPressed();
  bool Read();
  
  //Se utiliza para que solo se ejecute una accion una sola vez, aunque se deje presioanada la tecla
  bool isKeyDown;
};




#endif