// wifi-mqtt 설정
#include "WiFi.h"
#include "ArduinoMqttClient.h"

char ssid[] = "IOTA_24G";
char pass[] = "kosta90009";
char broker[] = "10.10.10.19";    // 라즈베리파이 주소
int port = 1883; // admin에서 설정한 port

char p_topic[] = "sensor/image"; // 주제 설정

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void setup()
{
    Serial.begin(115200);

    while(WiFi.begin(ssid, pass) != WL_CONNECTED)
    {
        Serial.print(".");
        delay(5000);
    }
    delay(1000);
    
    while(mqttClient.connect(broker, port) == 0)
    {
        Serial.println(mqttClient.connectError());

        WiFi.disconnect();
        while(WiFi.begin(ssid, pass) != WL_CONNECTED)
        {
            Serial.print(".");
            delay(5000);
        }
        delay(1000);
    }
    Serial.println("mqtt ok");
}

void loop()
{

    // MQTT 메시지 전송
    String message = "Hello World!";
    mqttClient.beginMessage(p_topic); // 특정 주제 선정
    mqttClient.print(message);
    Serial.print(mqttClient.endMessage());

    delay(1000);
}
