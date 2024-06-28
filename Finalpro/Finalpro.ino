
// wifi-mqtt 설정
#include "WiFi.h"
#include "ArduinoMqttClient.h"
#include "s1.h"
char ssid[] = "IOTA_24G";
char pass[] = "kosta90009";
char broker[] = "10.10.10.19";    // 열려 있는 포트의 IP 주소를 입력해야 함
int port = 1883; // admin에서 설정한 port

char p_topic[] = "sensor/image/Sensor1"; // 주제 설정

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

Thermal s1;

void setup()
{
    Serial.begin(115200);
    s1.begin(30.0,10.0);
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
    mqttClient.beginMessage(p_topic); // 특정 주제 선정
    mqttClient.print(s1.getTemperature());
    Serial.print(mqttClient.endMessage());

    delay(1000);
}
