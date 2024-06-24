#include "water_level.h"
#include <Arduino.h>

SZH::SZH() {
    this->level = 0.0f;
    this->high_depth = 0.0f;
    this->low_depth = 0.0f;
    this->current_depth = 0.0f;
}

void SZH::begin() {
    // 필요한 초기화 코드를 여기에 추가합니다.
}

float SZH::water_level() {
    int sensor_value = analogRead(A0);
    level = map(sensor_value, 0, 1023, 0, 100);
    return level;
}

void SZH::set_alarm_depth(float high, float low) {
    high_depth = high;
    low_depth = low;
    current_depth = water_level();
}

uint8_t SZH::check_alarm() {
    float current_level = water_level();
    if (current_level > high_depth) {
        return 1;
    } else if (current_level < low_depth) {
        return 2;
    } else {
        return 0;
    }
}
