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
    void power_on();
    void power_off();
    void power_up();
    void power_down();

    private:
    int motorA1;
    int motorA2;

};
#endif