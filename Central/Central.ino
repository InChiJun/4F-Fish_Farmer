#include <ArduinoBLE.h>
#include <Arduino.h>
BLEService CountingService("19B10000-E8F2-537E-4F6C-D104768A1214");
BLEStringCharacteristic CountingChar("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite | BLERead | BLENotify, 20);

void setup() {
    Serial.begin(115200);

    if (!BLE.begin()) {
        Serial.println("starting BLE failed!");
        while (1);
    }

    Serial.println("Central device active, searching for peripherals...");
    BLE.scanForUuid("19B10000-E8F2-537E-4F6C-D104768A1214");
}

void loop() {
    BLEDevice peripheral = BLE.available();

    if (peripheral) {
        Serial.print("Found peripheral: ");
        Serial.println(peripheral.address());

        if (peripheral.connect()) {
            Serial.println("Connected to peripheral");

            if (peripheral.discoverAttributes()) {
                Serial.println("Attributes discovered");

                BLECharacteristic countingChar = peripheral.characteristic("19B10001-E8F2-537E-4F6C-D104768A1214");

                if (countingChar) {
                    while (peripheral.connected()) {
                        if (countingChar.written()) {
                            String value = countingChar.value();
                            Serial.print("Received: ");
                            Serial.println(value);
                        }
                    }
                }
            }
        }

        Serial.println("Peripheral disconnected");
    }

    delay(1000);
}
