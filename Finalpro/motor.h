#ifndef MOTOR_H
#define MOTOR_H

#include "output_interface.h"
#include <Arduino.h>  // Arduino 환경에서 제공되는 함수 사용을 위해 필요합니다.

class Motor : public Output_interface
{
public:
    Motor() = default;
    void power_on() override;
    void power_off() override;
    bool get_power() const override;
    uint8_t get_pwm() const override;
    void up_pwm() override;
    void down_pwm() override;
    void set_pin(uint8_t pin1, uint8_t pin2) override;

private:
    uint8_t pwm = 0;
    bool power_status = false;
};

#endif