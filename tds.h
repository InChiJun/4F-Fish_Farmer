#ifndef TDS_H
#define TDS_H

#include <Arduino.h>

class TDS {
    public:
        TDS(uint8_t pin, float vref = 5.0);
        void begin();
        float readTDS(float temperature);

    private:
        uint8_t _pin;
        float _vref;
        float getMedianNum(int *arr, int size);
};
#endif
