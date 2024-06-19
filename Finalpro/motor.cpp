#include "motor.h"

void Motor::power_on() {
    power_status = true;
}

void Motor::power_off() {
    power_status = false;
}

bool Motor::get_power() const {
    return power_status;
}

uint8_t Motor::get_pwm() const {
    return pwm;
}

void Motor::up_pwm() {
    if (pwm < 255) {
        ++pwm;
    }
}

void Motor::down_pwm() {
    if (pwm > 0) {
        --pwm;
    }
}

void Motor::set_pin(uint8_t pin1, uint8_t pin2) {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);   
}