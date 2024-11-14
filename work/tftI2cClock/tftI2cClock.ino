
#include "config.h"
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>


#include <TimeLib.h>
#include <DS1307RTC.h>
#include <OneWire.h>
#include <DallasTemperature.h>

void setup() {
  setupDebug();
#ifdef TEMP
  setupTemperature();
#endif
#ifdef LCD
  lcdSetup();
#endif
}

tmElements_t tm;
float temperature;
void loop() {
  RTC.read(tm);
#ifdef TEMP
  loopTemperature();
#endif
#ifdef LCD
  lcdLoop();
#endif
  delay(500);
}
