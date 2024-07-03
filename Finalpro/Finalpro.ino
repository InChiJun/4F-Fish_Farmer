#include "WiFi.h"
#include "ArduinoMqttClient.h"
#include "s1.h"
#include "s2.h"
#include "s3.h"
#include "s4.h"
#include "s5.h"

char ssid[] = "IOTB_24G";
char pass[] = "kosta90009";
char broker[] = "10.10.20.7"; // 열려 있는 포트의 IP 주소를 입력해야 함
int port = 1883;              // admin에서 설정한 port

char p_topic1[] = "sensor/value/Sensor1";
char p_topic2[] = "sensor/value/Sensor2";
char p_topic3[] = "sensor/value/Sensor3";
char p_topic4[] = "sensor/value/Sensor4";
char p_topic5[] = "sensor/value/Sensor5";

char p_topic6[] = "sensor/alarm/Sensor1";
char p_topic7[] = "sensor/alarm/Sensor2";
char p_topic8[] = "sensor/alarm/Sensor3";
char p_topic9[] = "sensor/alarm/Sensor4";
char p_topic10[] = "sensor/alarm/Sensor5";

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

Thermal s1;
AHT20 s2;
Phsensor s3;
TDS s4;
SZH s5;

void setup()
{
    Serial.begin(115200);
    s1.begin(30.0, 10.0);
    s2.begin();
    s3.begin();
    s4.begin();
    s5.begin();

    s1.set_alarm_temp(30.0, 10.0);
    s2.set_alarm_humidity(80.0, 20.0);
    s3.set_Ph_alarm(0.0, 14.0);
    s5.set_alarm_depth(20.0, 0.0);

    connectWiFi();
    connectMQTT();

    mqttClient.onMessage(onMqttMessage);
    Serial.println("mqtt ok");
}

void loop()
{
    if (!mqttClient.connected())
    {
        connectMQTT();
    }
    mqttClient.poll(); // 메시지 폴링 추가

    sendDataToMQTT();
    delay(3000); // 전체 데이터를 보내는 루프에 대한 지연 시간
}

void connectWiFi()
{
    while (WiFi.begin(ssid, pass) != WL_CONNECTED)
    {
        Serial.print(".");
        delay(5000);
    }
    delay(1000);
}

void connectMQTT()
{
    while (!mqttClient.connect(broker, port))
    {
        Serial.print("MQTT connection failed: ");
        Serial.println(mqttClient.connectError());
        WiFi.disconnect();
        connectWiFi();
    }

    Serial.print("Subscribing to topic: ");
    Serial.println("example/temperature");
    mqttClient.subscribe("example/temperature");
}

void sendDataToMQTT()
{
    sendMQTTMessage(p_topic1, String(s1.getTemperature()));
    delay(1000);
    sendMQTTMessage(p_topic2, String(s2.getHumidity()));
    delay(1000);
    sendMQTTMessage(p_topic3, String(s3.get_Ph()));
    delay(1000);
    sendMQTTMessage(p_topic4, String(s4.readTDS(s1.getTemperature())));
    delay(1000);
    sendMQTTMessage(p_topic5, String(s5.water_level()));
    delay(1000);
    sendMQTTMessage(p_topic6, String(s1.check_alarm()));
    delay(1000);
    sendMQTTMessage(p_topic7, String(s2.check_alarm_humidity()));
    delay(1000);
    sendMQTTMessage(p_topic8, String(s3.check_Ph_alarm()));
    delay(1000);
    sendMQTTMessage(p_topic10, String(s5.check_alarm()));
    delay(1000);
}

void sendMQTTMessage(const char *topic, const String &payload)
{
    if (mqttClient.beginMessage(topic))
    {
        mqttClient.print(payload);
        if (mqttClient.endMessage())
        {
            Serial.print("Message sent to topic ");
            Serial.print(topic);
            Serial.print(": ");
            Serial.println(payload);
        }
        else
        {
            Serial.print("Error sending message to topic ");
            Serial.println(topic);
        }
    }
    else
    {
        Serial.print("Error starting message for topic ");
        Serial.println(topic);
    }
}

void onMqttMessage(int messageSize)
{
    // 메시지 처리 콜백
    Serial.print("Received a message with topic '");
    Serial.print(mqttClient.messageTopic());
    Serial.print("', length ");
    Serial.println(messageSize);

    // 메시지 내용을 읽어서 시리얼로 출력
    char payload[messageSize + 1]; // payload 크기 + null terminator
    int i = 0;
    while (mqttClient.available())
    {
        payload[i++] = mqttClient.read();
    }
    payload[i] = '\0'; // null terminator 추가

    Serial.print("Payload: ");
    Serial.println(payload);
}