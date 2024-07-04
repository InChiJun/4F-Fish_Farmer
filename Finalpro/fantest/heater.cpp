#include "heater.h"

void heater::begin(uint8_t sigPin) {
    power_status = false;
    signal_pin = A2; // 신호 핀 설정
    pinMode(signal_pin, OUTPUT); // 신호 핀을 입력으로 설정
    digitalWrite(signal_pin, HIGH);
}

void heater::control() {
    int signal = digitalRead(signal_pin);
    if (signal == HIGH) {
        power_on();
    } else {
        power_off();
    }
}

void heater::power_on() {
    power_status = true;
    digitalWrite(signal_pin, HIGH);
}

void heater::power_off() {
    power_status = false;
    digitalWrite(signal_pin, LOW);
}

bool heater::get_power() const {
    return power_status;
}

