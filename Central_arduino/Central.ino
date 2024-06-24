<<<<<<< HEAD
#include <SoftwareSerial.h>
 
SoftwareSerial hc06(2,3);
 
void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
  Serial.println(hc06.print("AT"));
  Serial.println(hc06.print("AT+NAMEHyun"));
  Serial.println(hc06.print("AT+PIN0000"));
=======
#include <SoftwareSerial.h> // 블루투스 시리얼 통신 라이브러리 추가
#define BT_RXD 8 // 데이터 핀 번호
#define BT_TXD 7 // 데이터 핀 번호
SoftwareSerial bluetooth(BT_RXD, BT_TXD); // 블루투스 설정 BTSerial(Tx, Rx)
void setup()
{
    Serial.begin(9600);
    bluetooth.begin(9600); // 블루투스 통신 시작
}
void loop()
{
    
    if (bluetooth.available())
    { // 블루투스에서 보낸 내용은 시리얼모니터로 전송
        Serial.write(bluetooth.read());
    }
    if (Serial.available())
    { // 시리얼모니터에서 보낸 내용은 블루투스로 전송
        bluetooth.write(Serial.read());
    }
    delay(1000);
>>>>>>> 1e96e23787afd6a88197e6cad905d159e311de7f
}
 
void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()){
    hc06.write(Serial.read());
  }  
}