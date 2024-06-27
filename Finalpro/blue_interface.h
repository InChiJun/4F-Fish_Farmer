#ifndef BLUE_INTERFACE_H
#define BLUE_INTERFACE_H

#include <SoftwareSerial.h>

class Bluetooth {
public:
    Bluetooth(int rxPin, int txPin); // 생성자를 추가하여 초기화할 핀 번호를 전달
    ~Bluetooth(); // 소멸자 추가

    void begin(); // begin 함수의 매개변수를 제거
    void send(String data);

private:
    SoftwareSerial hc10; // 핀 번호를 초기화하는 것은 생성자에서 처리
};

#endif // BLUE_INTERFACE_H