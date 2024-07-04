#include "heater.h"

heater h;

void setup() {
    h.begin();
}

void loop() {
    h.power_on();
}