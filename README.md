# Bluetooth Arcade Controls
Este código fue creado para una **ESP32 WROOM 32S**.  
La librería **BleKeyboard** es compatible con este modelo, pero es necesario modificar un archivo interno de la librería.

### Pasos a seguir

1. Abrí el archivo `BleKeyboard.cpp`, ubicado en la carpeta de la librería  
   `ESP32_BLE_Keyboard` (generalmente en `Documentos/Arduino/Libraries`).

2. Localizá las siguientes líneas que causan el error:

```cpp
BLEDevice::init(deviceName);
hid->manufacturer()->setValue(deviceManufacturer);
```
por: 
```cpp
BLEDevice::init(String(deviceName.c_str()));
hid->manufacturer()->setValue(String(deviceManufacturer.c_str()));
```

--> URL de la libreria: https://github.com/T-vK/ESP32-BLE-Keyboard
