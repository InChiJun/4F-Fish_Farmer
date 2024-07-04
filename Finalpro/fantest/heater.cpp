#include "heater.h"

void heater::begin(){
    power_status = false;
    set_pin(A3, A2);
    power_off();
}

void heater::power_on() {
    power_status = true;
    digitalWrite(control_pin1, HIGH);
    digitalWrite(control_pin2, LOW);
}

void heater::power_off() {
    power_status = false;
    digitalWrite(control_pin1, LOW);
    digitalWrite(control_pin2, LOW);
}

bool heater::get_power() const {
    return power_status;
}

void heater::set_pin(uint8_t pin1, uint8_t pin2) {
    control_pin1 = pin1;
    control_pin2 = pin2;
    pinMode(control_pin1, OUTPUT);
    pinMode(control_pin2, OUTPUT);
}
