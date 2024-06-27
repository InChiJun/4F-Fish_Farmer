#include "blue_interface.h"

Bluetooth::Bluetooth(int rxPin, int txPin) : hc10(rxPin, txPin)
{
  // 생성자에서 SoftwareSerial 객체 초기화
}

Bluetooth::~Bluetooth()
{
  // 소멸자 구현
}

void Bluetooth::begin()
{
  hc10.begin(9600); // 시리얼 통신 속도 설정
  delay(3000);      // 잠시 대

  hc10.print("AT"); // AT 명령어 전송
  delay(1000);       // 응답 대기
  while (hc10.available())
  {
    char c = hc10.read(); // 응답 읽기
    Serial.write(c);      // 시리얼 모니터에 출력
  }
  Serial.println("");
  hc10.print("AT+DISC?"); // NAME 명령어 전송
  delay(1000);            // 응답 대기
  while (hc10.available())
  {
    char c = hc10.read(); // 응답 읽기
    Serial.write(c);      // 시리얼 모니터에 출력
  }
  Serial.println("");
  hc10.print("AT+CONN0"); // PIN 명령어 전송
  delay(1000);     
  while (hc10.available())
  {
    char c = hc10.read(); 
    Serial.write(c);      // 시리얼 모니터에 출력
  }       // 응답 대기
  Serial.println("");
}



void Bluetooth::send(String data)
{
  hc10.print(data); // 데이터 전송
}