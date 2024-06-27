#ifndef BLUE_INTERFACE_H
#define BLUE_INTERFACE_H

#include <SoftwareSerial.h>

class Bluetooth {
public:
    Bluetooth(); // Constructor declaration
    void begin(int RX, int TX);
    void send(String data);

private:
    SoftwareSerial* hc10; // Pointer to SoftwareSerial object
};

#endif // BLUE_INTERFACE_H