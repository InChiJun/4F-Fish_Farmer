#ifndef OUTPUT_INTERFACE_H
#define OUTPUT_INTERFACE_H

#include <cstdint>  // uint8_t를 사용하기 위해 필요합니다.

class Output_interface
{
public:
    // 순수 가상 소멸자는 기본 구현을 제공해야 합니다.
    virtual ~Output_interface() = default;

    // 순수 가상 함수들
    virtual void power_on() = 0;
    virtual void power_off() = 0;
    virtual bool get_power() const = 0;
    virtual uint8_t get_pwm() const = 0;
    virtual void up_pwm() = 0;
    virtual void down_pwm() = 0;
    virtual void set_pin(uint8_t pin1, uint8_t pin2) = 0;
};

#endif