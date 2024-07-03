#include "motor.h"

void motor::begin(){
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
}

void motor::water_fill(){
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
}

void motor::water_drain(){
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
}

void motor::stop(){
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
}

