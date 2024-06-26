#include <Arduino.h>
#ifndef s5_h
#define s5_h



class SZH{
    public:
    SZH();
    void begin();
    float water_level();
    void set_alarm_depth(float high, float low);
    uint8_t check_alarm();
    
    private:
    float level;
    float high_depth;
    float low_depth;
    float current_depth;
};
#endif