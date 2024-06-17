#include <Arduino.h>
#include "AHT20.h"
AHT20 aht20;
void setup() {
    Serial.begin(115200);
    aht20.begin();
}


void loop() {
    //float temp = aht20.
    Serial.print("Temperature: ");
    //Serial.println(temp);
    delay(2000);
}