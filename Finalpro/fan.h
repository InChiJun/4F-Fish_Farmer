#ifndef fan_h
#define fan_h

#include <Arduino.h>

class fan {
public:
    fan() = default;
    void begin();
    void power_on();
    void power_off();
    bool get_power() const;
    uint8_t get_pwm() const;
    void level_1();
    void level_2();
    void level_3();
    void set_pin(uint8_t pin11, uint8_t pin10);

    // 새로운 함수 추가: s2 데이터를 기반으로 팬 제어
    void control_based_on_s2(float humidity);

private:
    uint8_t pwm = 0;
    bool power_status = false;
};

#endif
