#include "Arduino.h"
#include "Phsensor.h"
#include "AHT20.h"
#include "thermal.h"

Phsensor phsensor;
AHT20 aht20;
Thermal thermal;

void setup()
{
    Serial.begin(115200);    
}
void loop()
{
    delay(1000);
}