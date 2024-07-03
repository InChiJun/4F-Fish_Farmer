#include "fan.h"

void fan::begin(){
    pwm = 0;
    power_status = false;
    set_pin(11, 10);
}
void fan::power_on() {
    power_status = true;
    digitalWrite(11, HIGH);
}

void fan::power_off() {
    power_status = false;
    analogWrite(11, pwm);
}

bool fan::get_power() const {
    return power_status;
}

uint8_t fan::get_pwm() const {
    return pwm;
}

void fan::set_pin(uint8_t pin11, uint8_t pin10) {
    pinMode(pin11, OUTPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin11, LOW);
    digitalWrite(pin10, LOW);
}