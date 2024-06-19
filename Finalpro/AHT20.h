#ifndef AHT20_h
#define AHT20_h
#include "Adafruit_AHTX0.h"
#include <Arduino.h>
class AHT20{
    public:
    AHT20();
    void begin();
    float getTemp();
    float getHumidity();
    void set_alarm_temp(float hot_temp, float cold_temp);
    uint8_t check_alarm();
    void set_alarm_humidity(float hot_humidity, float cold_humidity);
    uint8_t check_alarm_humidity();

    private:
    float temp;
    float humidity;
    float hot_temp;
    float cold_temp;
    float hot_humidity;
    float cold_humidity;

    Adafruit_AHTX0 aht;
};

#endif