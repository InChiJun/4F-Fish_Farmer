#include "blue_interface.h"

Bluetooth::Bluetooth()
    : hc10(nullptr) // Initialize hc10 to nullptr
{
}

void Bluetooth::begin(int RX, int TX)
{
    hc10 = new SoftwareSerial(RX, TX); // Dynamically allocate SoftwareSerial object
    hc10->begin(9600); // Start serial communication at 9600 baud rate
    delay(100);
    if (hc10->availableForWrite()) {
        hc10->write("AT+DISC?");
        while (hc10->available()) {
            char c = hc10->read();
            Serial.write(c);
        }
    }
}

void Bluetooth::send(String data)
{
    if (hc10 != nullptr) {
        hc10->print(data);
    }
}
