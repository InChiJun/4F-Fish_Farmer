#include "WiFi.h"
#include "ArduinoMqttClient.h"
#include "fan.h"
#include "motor.h"
#include "heater.h"

char ssid[] = "IOTB_24G";
char pass[] = "kosta90009";
char broker[] = "10.10.20.7";    // 열려 있는 포트의 IP 주소를 입력해야 함
int port = 1883; // admin에서 설정한 port

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

fan myfan;
motor mymotor;
heater myheater;

void setup() {
    Serial.begin(115200);

    myfan.begin();
    mymotor.begin();
    myheater.begin(A2);
    connectWiFi();
    connectMQTT();

    mqttClient.onMessage(onMqttMessage);
    Serial.println("mqtt ok");
}

void loop() {
    if (!mqttClient.connected()) {
        connectMQTT();
    }
    mqttClient.poll(); // 메시지 폴링 추가

}

void connectWiFi() {
    while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
        Serial.print(".");
        delay(5000);
    }
    delay(1000);
}

void connectMQTT() {
    while (!mqttClient.connect(broker, port)) {
        Serial.print("MQTT connection failed: ");
        Serial.println(mqttClient.connectError());
        WiFi.disconnect();
        connectWiFi();
    }

    Serial.print("Subscribing to topic: ");
    Serial.println("example/temperature");
    mqttClient.subscribe("example/temperature");
}

void onMqttMessage(int messageSize) {
    // 메시지 처리 콜백
    Serial.print("Received a message with topic '");
    Serial.print(mqttClient.messageTopic());
    Serial.print("', length ");
    Serial.println(messageSize);

    // 메시지 내용을 읽어서 시리얼로 출력
    char payload[messageSize + 1]; // payload 크기 + null terminator
    int i = 0;
    while (mqttClient.available()) {
        payload[i++] = mqttClient.read();
    }
    payload[i] = '\0'; // null terminator 추가

    control(payload);
}

void control(const char* payload) {
    if (payload[1] == '1') {
        if (payload[5] == '1') {
            myfan.power_on();
            Serial.print("Payload: ");
    Serial.println(payload);
        } else if (payload[5] == '0') {
            myfan.power_off();
        }
    } else if (payload[1] == '2') {
        if (payload[5] == '1') {
            mymotor.water_fill();
        } else if (payload[5] == '0') {
            mymotor.stop();
        }
    } else if (payload[1] == '3') {
        if (payload[5] == '1') {
            myheater.power_on();
        } else if (payload[5] == '0') {
            myheater.power_off();
        }
    }
}
