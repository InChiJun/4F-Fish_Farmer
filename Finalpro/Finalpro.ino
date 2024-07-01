#include "WiFi.h"
#include "ArduinoMqttClient.h"
#include "s1.h"
#include "s2.h"
#include "s3.h"
#include "s4.h"
#include "s5.h"


char ssid[] = "IOTB_24G";
char pass[] = "kosta90009";
char broker[] = "10.10.20.7";    // 열려 있는 포트의 IP 주소를 입력해야 함
int port = 1883; // admin에서 설정한 port

char p_topic1[] =   "sensor/value/Sensor1"; 
char p_topic2[] =   "sensor/value/Sensor2"; 
char p_topic3[] =   "sensor/value/Sensor3"; 
char p_topic4[] =   "sensor/value/Sensor4"; 
char p_topic5[] =   "sensor/value/Sensor5"; 

char p_topic6[] =   "sensor/alarm/Sensor1";
char p_topic7[] =   "sensor/alarm/Sensor2";
char p_topic8[] =   "sensor/alarm/Sensor3";
char p_topic9[] =   "sensor/alarm/Sensor4";
char p_topic10[] =  "sensor/alarm/Sensor5";


WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

Thermal     s1;
AHT20       s2;
Phsensor    s3;
//TDS         s4;
SZH         s5; 
void setup()
{
    Serial.begin(115200);
    s1.begin(30.0,10.0);
    s2.begin();
    s3.begin();
    //s4.begin();
    s5.begin();

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

  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(p_topic1);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(p_topic1);

    Serial.println("mqtt ok");
}

void loop()
{
    mqttClient.beginMessage(p_topic1); 
    mqttClient.print(s1.getTemperature());
    Serial.print(mqttClient.endMessage());
    
    mqttClient.beginMessage(p_topic2); 
    mqttClient.print(s2.getHumidity());
    Serial.print(mqttClient.endMessage());

    mqttClient.beginMessage(p_topic3);
    mqttClient.print(s3.get_Ph());
    Serial.print(mqttClient.endMessage());

    mqttClient.beginMessage(p_topic4); 
    mqttClient.print(s1.getTemperature());
    Serial.print(mqttClient.endMessage());

    mqttClient.beginMessage(p_topic5); 
    mqttClient.print(s5.water_level());
    Serial.print(mqttClient.endMessage());

    delay(1000);
}


void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  Serial.println("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.print("', length ");
  Serial.print(messageSize);
  Serial.println(" bytes:");

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    Serial.print((char)mqttClient.read());
  }
  Serial.println();

  Serial.println();
}