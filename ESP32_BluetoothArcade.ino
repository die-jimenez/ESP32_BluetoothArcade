//This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete

/* Esto codigo fue creado para una ESP WROOM 32S. La libreria BleKeyboard es compatible con con este pero hay que modificar el archivo de la liberia
// Estos cambios fueron dados por ChatGPT:

//1. Abre el archivo BleKeyboard.cpp que se encuentra en la carpeta de la biblioteca ESP32_BLE_Keyboard (Generalmente en documnentos/arduino/Libreries)
//2. Localiza las líneas que causan el error, específicamente -->
// BLEDevice::init(deviceName);
// hid->manufacturer()->setValue(deviceManufacturer);

//3. Cambia ambas lineas por -->
// BLEDevice::init(String(deviceName.c_str()));
// hid->manufacturer()->setValue(String(deviceManufacturer.c_str()));

//URL de la libreria: https://github.com/T-vK/ESP32-BLE-Keyboard
*/

#include <BleKeyboard.h>
#include "ArcadeButton.h"
BleKeyboard bleKeyboard;
bool bluetoothConectado;

//Pines de Leds
#define GPIO_RED_LED 25
#define GPIO_BLUE_LED 26
#define GPIO_GREEN_LED 27
#define GPIO_YELLOW_LED 33

//Pines de Botones (Pines con INPUT_PULLUP: 14, 16, 17, 18, 19, 21, 22, 23)
#define GPIO_RED_BUTTON 16
#define GPIO_BLUE_BUTTON 17
#define GPIO_GREEN_BUTTON 22
#define GPIO_YELLOW_BUTTON 23

//Pines del Joystick
#define GPIO_FRONT_RED 14
#define GPIO_DOWN_ORANGE 18
#define GPIO_LEFT_YELLOW 19
#define GPIO_RIGHT_GREEN 21


//Keys de botones
const char RED_KEY = ' ';
const char BLUE_KEY = '1';
const char GREEN_KEY = '2';
const char YELLOW_KEY = '3';

//Keys de botones
const char JOYSTICK_FRONT = ' ';
const char JOYSTICK_BACK = '1';
const char JOYSTICK_RIGHT = '2';
const char JOYSTICK_LEFT = '3';


//Declaracion de botones
ArcadeButton redButton(GPIO_RED_BUTTON, GPIO_RED_LED, RED_KEY);
ArcadeButton blueButton(GPIO_BLUE_BUTTON, GPIO_BLUE_LED, BLUE_KEY);
ArcadeButton greenButton(GPIO_GREEN_BUTTON, GPIO_GREEN_LED, GREEN_KEY);
ArcadeButton yellowButton(GPIO_YELLOW_BUTTON, GPIO_YELLOW_LED, YELLOW_KEY);

//Declaracion de Joystick
ArcadeButton joystickFront(GPIO_RED_BUTTON, GPIO_RED_LED, RED_KEY);
ArcadeButton joystickBack(GPIO_BLUE_BUTTON, GPIO_BLUE_LED, BLUE_KEY);
ArcadeButton joystickLeft(GPIO_GREEN_BUTTON, GPIO_GREEN_LED, GREEN_KEY);
ArcadeButton joystickRight(GPIO_YELLOW_BUTTON, GPIO_YELLOW_LED, YELLOW_KEY);


void setup() {
  //inicializa la libreria
  bleKeyboard.begin();
  Serial.begin(115200);
  Serial.println("La libreria de bluetooth se inicio");
  Serial.println("Si la luz azul del ESP32 esta encendida, se conecto por bluetooth");

  //Inicializar botones
  redButton.Init(HIGH);
  blueButton.Init(HIGH);
  greenButton.Init(HIGH);
  yellowButton.Init(HIGH);

  //InitButtons();
  InitLedIntegrado();
  ApagarLedIntegrado();
}

void loop() {

  //Aviso de que se desconecto del dispositivo
  if (!bleKeyboard.isConnected() && bluetoothConectado == true) {
    ApagarLedIntegrado();
    bluetoothConectado = false;
    Serial.println("Es ESP32 fue desconectado");
  }

  //Cuando esta conectado
  if (bleKeyboard.isConnected()) {
    //Aviso de que el ESP32 se conecto por bluetooth a algun dispositivo
    if (bluetoothConectado == false) {
      Serial.println("El ESP32 se conecto como teclado");
      bluetoothConectado = true;
      digitalWrite(2, HIGH);
    }

    //Botones
    if (redButton.isPressed()) {
      if (!redButton.isKeyDown) {
        redButton.Press(bleKeyboard);
        redButton.isKeyDown = true;
      }
      //delay(50);
    } else redButton.isKeyDown = false;

    if (blueButton.isPressed()) {
      if (!blueButton.isKeyDown) {
        blueButton.Press(bleKeyboard);
        blueButton.isKeyDown = true;
      }
      //delay(50);
    } else blueButton.isKeyDown = false;

    if (greenButton.isPressed()) {
      if (!greenButton.isKeyDown) {
        greenButton.Press(bleKeyboard);
        greenButton.isKeyDown = true;
      }
      //delay(50);
    } else greenButton.isKeyDown = false;

    if (yellowButton.isPressed()) {
      if (!yellowButton.isKeyDown) {
        yellowButton.Press(bleKeyboard);
        yellowButton.isKeyDown = true;
      }
      //delay(50);
    } else yellowButton.isKeyDown = false;
  }
  delay(50);
}


// void InitButtons() {
//   pinMode(greenButton, INPUT_PULLUP);
// }

void InitLedIntegrado() {
  pinMode(2, OUTPUT);
}

void ApagarLedIntegrado() {
  digitalWrite(2, LOW);
}
