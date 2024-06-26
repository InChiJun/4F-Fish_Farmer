
#ifndef s3_h
#define s3_h
#include "Arduino.h"
#define Vref 4.95
class Phsensor{
public:
    Phsensor();
    float get_Ph();
    void set_Ph_alarm(float low_ph, float high_ph);
    uint8_t get_alarm();
private:
    uint8_t _alarm = 0;
    float ph;
    float low_ph;
    float high_ph;
};

#endif