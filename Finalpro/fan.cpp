#include "fan.h"

void fan::begin(){
    power_status = true;
    set_pin(11, 10);
    digitalWrite(11,power_status);
}
void fan::power_on() {
    power_status = true;
    digitalWrite(11, power_status);
    }

void fan::power_off() {
    power_status = false;
    digitalWrite(11, LOW);
}

bool fan::get_power() const {
    return power_status;
}

void fan::set_pin(uint8_t pin11, uint8_t pin10) {
    pinMode(pin11, OUTPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin11, LOW);
    digitalWrite(pin10, LOW);
}