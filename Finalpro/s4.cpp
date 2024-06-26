#include "s4.h"

TDS::TDS(uint8_t pin, float vref) : _pin(pin), _vref(vref) {}

void TDS::begin() {
    pinMode(_pin, INPUT);
}

float TDS::readTDS(float temperature) {
    const int numReadings = 10;
    int readings[numReadings];
    for (int i = 0; i < numReadings; i++) {
        readings[i] = analogRead(_pin);
        delay(10);
    }

    float averageVoltage = getMedianNum(readings, numReadings) * (_vref / 1024.0);
    float compensationCoefficient = 1.0 + 0.02 * (temperature - 25.0);
    float compensationVoltage = averageVoltage / compensationCoefficient;
    float tdsValue = (133.42 * compensationVoltage * compensationVoltage * compensationVoltage
                    - 255.86 * compensationVoltage * compensationVoltage
                    + 857.39 * compensationVoltage) * 0.5;

    return tdsValue;
}

float TDS::getMedianNum(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    } else {
        return arr[size / 2];
    }
}
