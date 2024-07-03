#include <Arduino.h>
#ifndef heater_h
#define heater_h
class heater{
    public:
    void begin();
    void power_on();
    void power_off();
    bool get_power() const;
    uint8_t get_pwm() const;
    void set_pin(uint8_t pin9, uint8_t pin10);
    uint8_t pwm = 0;

    private:
    bool power_status = false;
};

#endif