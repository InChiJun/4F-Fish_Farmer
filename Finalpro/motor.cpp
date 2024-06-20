#include "motor.h"

Motor::Motor(int pin1, int pin2) {
    this->motorA1 = pin1;
    this->motorA2 = pin2;
}

void Motor::begin() {
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
}

void Motor::waterDrain() {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
}

void Motor::waterFill() {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
}

void Motor::stop() {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
}
