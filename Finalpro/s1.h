#include "Arduino.h"
#include "DallasTemperature.h"

class Thermal
{
public:
    Thermal();
    void begin(float hot_temp, float cold_temp);
    float getTemperature();
    void set_alarm_temp(float hot_temp, float cold_temp);
    uint8_t check_alarm();
private:
    OneWire oneWire;
    DallasTemperature dallasTemperature;
    float temperature;
    float hot_temp;
    float cold_temp;
    int pin;
};