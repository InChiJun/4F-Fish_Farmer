#ifndef fan_h
#define fan_h

#include <Arduino.h>

class fan {
public:
    void begin();
    void power_on();
    void power_off();
    bool get_power() const;
    void set_pin(uint8_t pin11, uint8_t pin10);
private:
    bool power_status = true;
    uint8_t pin11;
    uint8_t pin10;
};

#endif
