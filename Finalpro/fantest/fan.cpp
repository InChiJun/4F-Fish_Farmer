#include "fan.h"

void fan::begin(){
    power_status = true;
    set_pin(pin11, pin10);
    digitalWrite(pin11, power_status);
}

void fan::power_on() {
    power_status = true;
    digitalWrite(pin11, power_status);
}

void fan::power_off() {
    power_status = false;
    digitalWrite(pin11, LOW);
}

bool fan::get_power() const {
    return power_status;
}

void fan::set_pin(uint8_t pin11, uint8_t pin10) {
    this->pin11 = pin11;
    this->pin10 = pin10;
    pinMode(pin11, OUTPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin11, LOW);
    digitalWrite(pin10, LOW);
}
