
#include "config.h"
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


tmElements_t tm;
float temperature;
int humidity;

void setup() {
  setupDebug();
  Serial.println("coucou");
#ifdef TEMP
  setupTemperature();
#endif
#ifdef HUMIDITY
  setupHumidity();
#endif
#ifdef LCD
  lcdSetup();
#endif
}

void loop() {
  RTC.read(tm);
#ifdef TEMP
  loopTemperature();
  Serial.println(temperature);
#endif
#ifdef HUMIDITY
  loopHumidity();
#endif
#ifdef LCD
  lcdLoop();
#endif
  delay(500);
}
