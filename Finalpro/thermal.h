#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>
#ifndef THERMAL_H
#define THERMAL_H



class Thermal{
    public:
        Thermal();
        void begin();
        float getTemperature();
        
    private:
        float temperature;
        int pin;
        OneWire oneWire;
        DallasTemperature dallasTemperature;
};
#endif
