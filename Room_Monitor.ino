#include <Akeru.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define TX 5
#define RX 4
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

Akeru akeru(RX, TX);
Adafruit_BMP280 bmp;

void setup() {

  bmp280Config();
  sigfoxConfig();

}

void loop() {

  sigfoxSend();
  waitaDay();

}


