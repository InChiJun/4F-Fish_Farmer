#include "AHT20.h"

AHT20::AHT20()
{
    this->temp = 0.0f;
    this->humidity = 0.0f;
    this->hot_temp = 0.0f;
    this->cold_temp = 0.0f;
    this->hot_humidity = 0.0f;
    this->cold_humidity = 0.0f;

    this->aht = Adafruit_AHTX0();
}

void AHT20::begin()
{
    this->aht.begin();
}

float AHT20::getTemp()
{
    this->aht.getEvent(&this->humidity, &this->temp);
    return this->temp;
}

float AHT20::getHumidity()
{
    this->aht.getEvent(&this->humidity, &this->temp);
    return this->humidity;
}

void AHT20::set_alarm_temp(float hot_temp, float cold_temp)
{
    this->hot_temp = hot_temp;
    this->cold_temp = cold_temp;
}

uint8_t AHT20::check_alarm()
{
    if (this->temp > this->hot_temp)
    {
        return 1;
    }
    else if (this->temp < this->cold_temp)
    {
        return 2;
    }
    else
        return 0;
}

void AHT20::set_alarm_humidity(float hot_humidity, float cold_humidity)
{
    this->hot_humidity = hot_humidity;
    this->cold_humidity = cold_humidity;
}

uint8_t AHT20::check_alarm_humidity()
{
    if (this->hot_humidity < this->humidity)
    {
        return 1;
    }
    else if (this->temp < this->cold_temp)
    {
        return 2;
    }
    else
        return 0;
}
