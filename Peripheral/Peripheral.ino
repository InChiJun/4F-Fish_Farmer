#include <ArduinoBLE.h>

BLEService CountingService("19B10000-E8F2-537E-4F6C-D104768A1214");
BLEStringCharacteristic CountingChar("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite | BLERead | BLENotify, 20);

void setup() {
    Serial.begin(115200);

    if (!BLE.begin()) {
        Serial.println("starting BLE failed!");
        while (1);
    }

    BLE.setLocalName("DaeYammiPeripheral");
    BLE.setAdvertisedService(CountingService);
    CountingService.addCharacteristic(CountingChar);
    BLE.addService(CountingService);
    BLE.advertise();
    Serial.println("Peripheral device active, waiting for connections...");
}

void loop() {
    BLEDevice central = BLE.central();

    if (central) {
        Serial.print("Connected to central: ");
        Serial.println(central.address());

        while (central.connected()) {
            if (Serial.available() > 0) {
                String data = Serial.readStringUntil('\n');
                CountingChar.writeValue(data);
                Serial.print("Sent: ");
                Serial.println(data);
            }

            delay(100);
        }

        Serial.print("Disconnected from central: ");
        Serial.println(central.address());
    }

    delay(1000);
    Serial.println("Waiting for a central device to connect...");
}