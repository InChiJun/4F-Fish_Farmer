#include "ArduinoBLE.h"
BLEService CountingService("19B10000-E8F2-537E-4F6C-D104768A1214");
BLEStringCharacteristic CountingChar("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite | BLERead | BLENotify, 10);
void setup()
{
    Serial.begin(115200);

    if (!BLE.begin())
    {
        Serial.println("starting BLE failed!");

        while (1);
    }

    {
        BLE.setLocalName("DaeYammi");
        BLE.setAdvertisedService(CountingService);
        CountingService.addCharacteristic(CountingChar);
        BLE.addService(CountingService);
        BLE.advertise();
        Serial.println("Bluetooth device active, waiting for connections...");
    }
}
void loop()
{
    uint8_t value = 0;
    BLEDevice central = BLE.central();
    if (central)
    {
        Serial.print("Connect");
        Serial.println(central.address());

        while (1)
        {
            CountingChar.writeValue("Hello!");
            if (!central.connected())
            {
                Serial.println("Disconnected");
                break;
            }

            delay(1000);
        }
    }
    Serial.println("Waiting...");
    delay(1000);
}