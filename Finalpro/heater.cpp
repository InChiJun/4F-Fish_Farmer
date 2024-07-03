#include "heater.h"

void heater::begin(){
    pwm = 0;
    power_status = false;
    set_pin(A3, A2);
}

void heater::power_on() {
    power_status = true;
    analogWrite(A3, pwm);
}

void heater::power_off() {
    power_status = false;
    analogWrite(A3, pwm);
}

bool heater::get_power() const {
    return power_status;
}

uint8_t heater::get_pwm() const {
    return pwm;
}

void heater::set_pin(uint8_t pin9, uint8_t pin10) {
    pinMode(pin9, OUTPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin9, LOW);
    digitalWrite(pin10, LOW);
}