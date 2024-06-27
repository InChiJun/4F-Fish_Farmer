// #include "Arduino.h"
// #include "Phsensor.h"
// #include "AHT20.h"
// #include "thermal.h"

// Phsensor phsensor;
// AHT20 aht20;
// Thermal thermal;


// //     
// //     auto humid = aht20.getHumidity();
// //     auto temp = aht20.getTemp();
// //     auto therm = thermal.getTemperature();
// //     Serial.print("PH: ");
// //     Serial.print(ph);
// //     Serial.print(" | Humidity: ");
// //     Serial.print(humid);
// //     Serial.print(" | Temperature: ");
// //     Serial.print(temp);
// //     Serial.print(" | Thermal: ");
// //     Serial.println(therm);

// // wifi-mqtt 설정
// #include "WiFi.h"
// #include "ArduinoMqttClient.h"

// char ssid[] = "IOTA_24G";
// char pass[] = "kosta90009";
// char broker[] = "10.10.10.19";    // 열려 있는 포트의 IP 주소를 입력해야 함
// int port = 1883; // admin에서 설정한 port

// char p_topic[] = "sensor/image/thermalSensor"; // 주제 설정

// WiFiClient wifiClient;
// MqttClient mqttClient(wifiClient);

// void setup()
// {
//     Serial.begin(115200);
//     thermal.begin();
//     aht20.begin();

//     while(WiFi.begin(ssid, pass) != WL_CONNECTED)
//     {
//         Serial.print(".");
//         delay(5000);
//     }
//     delay(1000);
    
//     while(mqttClient.connect(broker, port) == 0)
//     {
//         Serial.println(mqttClient.connectError());

//         WiFi.disconnect();
//         while(WiFi.begin(ssid, pass) != WL_CONNECTED)
//         {
//             Serial.print(".");
//             delay(5000);
//         }
//         delay(1000);
//     }
//     Serial.println("mqtt ok");
// }

// void loop()
// {

    
//     auto ph = phsensor.get_Ph();
//     mqttClient.beginMessage(p_topic); // 특정 주제 선정
//     mqttClient.print(ph);
//     Serial.print(mqttClient.endMessage());

//     delay(1000);
// }

#include "blue_interface.h"

Bluetooth bt(2, 3); // Bluetooth 객체 생성 시 핀 번호 지정

void setup() {
    Serial.begin(9600);
    delay(2000); // 초기화 대기
    bt.begin(); // Bluetooth 모듈 초기화
}

void loop() {
    bt.send("S11234"); // 데이터 전송
    delay(1000); // 1초 대기
    bt.send("S11235"); // 데이터 전송
    bt.send("S11236"); // 데이터 전송
}


// #include <SoftwareSerial.h>
 
// SoftwareSerial hc06(2,3);
 
// void setup(){
//   //Initialize Serial Monitor
//   Serial.begin(9600);
//   Serial.println("ENTER AT Commands:");
//   //Initialize Bluetooth Serial Port<
//   hc06.begin(9600);
//   hc06.print("AT");
// }
 
// void loop(){
//   //Write data from HC06 to Serial Monitor
//   if (hc06.available()){
//     Serial.write(hc06.read());
//   }
  
//   //Write from Serial Monitor to HC06
//   if (Serial.available()){
//     hc06.write(Serial.read());
//   }  
// }