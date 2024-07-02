#include "fan.h"

void fan::begin(){
    pwm = 0;
    power_status = false;
    set_pin(11, 10);
}
void fan::power_on() {
    power_status = true;
}

void fan::power_off() {
    power_status = false;
}

bool fan::get_power() const {
    return power_status;
}

uint8_t fan::get_pwm() const {
    return pwm;
}

void fan::level_1() {
    // 팬의 속도 레벨 1에 해당하는 제어 로직 추가
    if (pwm < 100) {
         analogWrite(11, ++pwm);
    }else if (pwm > 100) {
         analogWrite(11, --pwm);
    }
}

void fan::level_2() {
    // 팬의 속도 레벨 2에 해당하는 제어 로직 추가
    if (pwm > 150) {
         analogWrite(11, ++pwm);
    }else if (pwm < 150) {
         analogWrite(11, --pwm);
    }
}

void fan::level_3() {
    // 팬의 속도 레벨 3에 해당하는 제어 로직 추가
    if (pwm < 255) {
         analogWrite(11, ++pwm);
    } else if (pwm > 255) {
         analogWrite(11, --pwm);
    }
}

void fan::set_pin(uint8_t pin11, uint8_t pin10) {
    pinMode(pin11, OUTPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin11, LOW);
    digitalWrite(pin10, LOW);
}

// 새로운 함수 구현: s2 센서 데이터에 따라 팬 제어
void fan::control_based_on_s2(float humidity) {
    // 예제로 humidity 값에 따라 팬의 동작을 제어할 수 있도록 구현
    if (humidity >= 40.0) {
        level_3(); // 높은 습도에 대한 처리, 예를 들어 level 3으로 팬 제어
    } else {
        power_off(); // 낮은 습도에 대한 처리, 예를 들어 팬을 꺼줌
    }
}
