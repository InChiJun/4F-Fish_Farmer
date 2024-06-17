#include "thermal.h"

Thermal::Thermal() : oneWire(D2), dallasTemperature(&oneWire)
{
    this->temperature = 0;
    this->pin = D2;
    this->hot_temp = 35.0, this->cold_temp = 15.0;
}

void Thermal::begin()
{
    pinMode(pin, INPUT);
    dallasTemperature.begin();
}

float Thermal::getTemperature()
{
    dallasTemperature.requestTemperatures();
    this->temperature = dallasTemperature.getTempCByIndex(0);
    return this->temperature;
}

void Thermal::set_alarm_temp(float hot_temp, float cold_temp)
{
    this->hot_temp = hot_temp;
    this->cold_temp = cold_temp;
}

uint8_t Thermal::check_alarm()
{
    if(this->temperature > this->hot_temp)
    {
        return 1;
    }
    else if(this->temperature < this->cold_temp)
    {
        return 2;
    }
    else
        return 0;
    
}