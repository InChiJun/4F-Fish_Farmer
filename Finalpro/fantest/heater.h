#ifndef heater_h
#define heater_h

#include <Arduino.h>

class heater {
public:
    void begin();
    void power_on();
    void power_off();
    bool get_power() const;
    void set_pin(uint8_t pin1, uint8_t pin2);
    bool power_status;
private:
    uint8_t control_pin1;
    uint8_t control_pin2; 
};

#endif
