#include <Arduino.h>
#include "thermal.h"
Thermal thermal;
void setup() {
    Serial.begin(115200);
    thermal.begin();
}


void loop() {
    float temp = thermal.getTemperature();
    Serial.print("Temperature: ");
    Serial.println(temp);
    delay(2000);
}