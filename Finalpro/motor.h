#include <Arduino.h>
#ifndef motor_h
#define motor_h

class motor{
    public:
    motor(int pin1, int pin2);
    void begin();
    void water_fill();
    void water_drain();
    void stop();

    private:
    int motorA1;
    int motorA2;

};
#endif