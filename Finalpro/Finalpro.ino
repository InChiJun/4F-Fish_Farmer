
#include <Arduino.h>
#include "AHT20.h"
AHT20 aht20;
void setup() {
    Serial.begin(115200);
    aht20.begin();
}


void loop() {
    Serial.print("Humidity: ");
    float humid = aht20.getHumidity();
    Serial.println(humid);
    Serial.print("Temperature: ");
    float temp = aht20.getTemp();
    Serial.println(temp);

    delay(2000);
}