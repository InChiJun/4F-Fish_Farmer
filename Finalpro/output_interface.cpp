#include "motor.h"

Motor::Motor() : pwm(0), status(false) {}

void Motor::set_status(bool _status) {
    status = _status;
}

bool Motor::get_status() const {
    return status;
}

void Motor::set_pwm(uint8_t _pwm) {
    pwm = _pwm;
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