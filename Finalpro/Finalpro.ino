#include "Phsensor.h"
Phsensor phsensor;
void setup()
{
    Serial.begin(115200);
    
    
}
void loop()
{
    float ph = phsensor.get_Ph();
    Serial.print("PH: ");
    Serial.println(ph);
    delay(1000);
}