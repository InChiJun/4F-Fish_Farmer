#ifndef s4_h
#define s4_h

#include <Arduino.h>

class TDS {
public:
    // 매개변수 있는 생성자
    TDS(uint8_t pin, float vref);
    // 기본 생성자 추가
    TDS();

    void begin();
    float readTDS(float temperature);

private:
    uint8_t _pin;
    float _vref;
    float getMedianNum(int *arr, int size);
};

#endif
