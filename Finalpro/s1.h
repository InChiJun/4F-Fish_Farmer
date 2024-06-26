#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>
#ifndef s1_H
#define s1_H

class Thermal{
    public:
        Thermal();
        void begin();
        float getTemperature();
        void set_alarm_temp(float hot_temp,float cold_temp);
        uint8_t check_alarm();
    private:
        float temperature;
        int pin;
        float hot_temp, cold_temp;
        OneWire oneWire;
        DallasTemperature dallasTemperature;
};
#endif
