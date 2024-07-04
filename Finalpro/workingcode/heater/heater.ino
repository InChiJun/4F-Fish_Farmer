#include <Arduino.h>

// 핀 정의
const int in1Pin = A2;   // H-Bridge IN1 핀
const int in2Pin = A3;   // H-Bridge IN2 핀


void setup() {
  // 핀 모드 설정
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);


  // 시리얼 통신 시작
  Serial.begin(115200);
}

void loop() {
  char payload[] = "m30001";
  control(payload);
  Serial.println(payload);
  delay(1000);

}

void control(const char* payload) {
    if (payload[1] == '1') {
        if (payload[5] == '1') {
            // myfan.power_on();
            // Serial.print("Payload: ");
    Serial.println(payload);
        } else if (payload[5] == '0') {
            // myfan.power_off();
        }
    } else if (payload[1] == '2') {
        if (payload[5] == '1') {
            // mymotor.water_fill();
        } else if (payload[5] == '0') {
            // mymotor.stop();
        }
    } else if (payload[1] == '3') {
        if (payload[5] == '1') {
            digitalWrite(in1Pin, HIGH);
            digitalWrite(in2Pin, LOW);
            Serial.print ("Payload: ");
        } else if (payload[5] == '0') {
            digitalWrite(in1Pin, LOW);
            digitalWrite(in2Pin, LOW);
        }
    }
}
