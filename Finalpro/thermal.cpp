#include "thermal.h"

Thermal::Thermal() : oneWire(D2), dallasTemperature(&oneWire)
{
    this->temperature = 0;
    this->pin = D2;
}

void Thermal::begin()
{
    pinMode(pin, INPUT);
    dallasTemperature.begin();
}

float Thermal::getTemperature()
{
    dallasTemperature.requestTemperatures();
    return dallasTemperature.getTempCByIndex(0);
}
