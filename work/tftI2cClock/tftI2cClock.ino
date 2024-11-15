

#include "config.h"
#include "struct.h"
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

 
struct S_Datas datas;

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
#ifdef TFT
  tftSetup();
#endif
#ifdef PRESSURE
  pressureSetup();
#endif
}

void loop() {
  RTC.read(datas.dateTime);
#ifdef TEMP
  loopTemperature();
#endif
#ifdef HUMIDITY
  loopHumidity();
#endif
#ifdef PRESSURE
  pressureLoop();
#endif
#ifdef LCD
  lcdLoop();
#endif

#ifdef TFT
  tftLoop();
#endif
  delay(500);
}
