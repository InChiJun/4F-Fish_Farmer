#include "fan.h"

void fan::begin(){
    power_status = true;
    set_pin(D11, D10);
}
void fan::power_on() {
    power_status = true;
    digitalWrite(D10, LOW);
    }


void fan::power_off() {
    power_status = false;
    digitalWrite(D10, HIGH);
}

bool fan::get_power() const {
    return power_status;
}

void fan::set_pin(uint8_t pin11, uint8_t pin10) {
    pinMode(pin11, INPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin10, HIGH);
}