#include "s3.h"

Phsensor::Phsensor()
{

}

void Phsensor::begin()
{
    pinMode(A0, INPUT);
    pinMode(A1, OUTPUT);
    this->ph = 0.0f;
    this->low_ph = 0.0f;
    this->high_ph = 0.0f;
}

float Phsensor::get_Ph()
{
    float sensorValue;
    int m;
    long sensorSum;
    int buf[10];                 // buffer for read analog
    for (int i = 0; i < 10; i++) // Get 10 sample value from the sensor for smooth the value
    {
        buf[i] = analogRead(A0); // Connect the PH Sensor to A0 port
        delay(10);
    }
    for (int i = 0; i < 9; i++) // sort the analog from small to large
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (buf[i] > buf[j])
            {
                int temp = buf[i];
                buf[i] = buf[j];
                buf[j] = temp;
            }
        }
    }
    float avgvalue = 0;
    for (int i = 2; i < 8; i++) // take the average value of 6 center sample
        avgvalue += buf[i];
    sensorValue = avgvalue / 6;
    this->ph = 7-1000*(sensorValue-365)*Vref/59.16/1023;
    return this->ph;
}

void Phsensor::set_Ph_alarm(float low_ph, float high_ph)
{
    this->low_ph = low_ph;
    this->high_ph = high_ph;
}

uint8_t Phsensor::get_alarm()
{
    if (this->ph > this->high_ph)
    {
        return 1;
    }
    else if (this->ph < this->low_ph)
    {
        return 2;
    }
    else return 0;
}
