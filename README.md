#Bluetooth Arcade Controls
Esto codigo fue creado para una ESP WROOM 32S. La libreria BleKeyboard es compatible con con este pero hay que modificar el archivo de la liberia
1. Abre el archivo BleKeyboard.cpp que se encuentra en la carpeta de la biblioteca ESP32_BLE_Keyboard (Generalmente en documnentos/arduino/Libreries)
2. Localiza las líneas que causan el error, específicamente -->
BLEDevice::init(deviceName);
hid->manufacturer()->setValue(deviceManufacturer);

3. Cambia ambas lineas por -->
BLEDevice::init(String(deviceName.c_str()));
hid->manufacturer()->setValue(String(deviceManufacturer.c_str()));

--> URL de la libreria: https://github.com/T-vK/ESP32-BLE-Keyboard
