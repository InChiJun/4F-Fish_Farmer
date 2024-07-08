#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#define PIN 3 // DI 핀번호
#define N_LEDS 8 // 네오픽셀 LED 갯수

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
//NEO_GRB <= 네오픽셀 타입 , NEO_KHZ800 <= 클럭 주파수

void setup() {
    Serial.begin(115200);
  strip.setBrightness(100); // 네오픽셀 밝기
  strip.begin(); // 네오픽셀 시작

}

void loop() {
chase(strip.Color(50,255,50));
delay(150);
chase(strip.Color(50,50,255));
delay(150);
chase(strip.Color(255,50,50));
delay(150);
Serial.println("박준혁 하트");
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i , c); // i 번째 픽셀에 LED 색상 지정
      strip.setPixelColor(i-3, 0); // i-3 픽셀에 색상 0을 지정하여 지움
      strip.show(); //
      delay(10);
  }
}