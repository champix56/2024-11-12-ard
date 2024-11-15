

#include "config.h"
#include "struct.h"
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


struct S_Datas datas;

void setup() {
  setupDebug();
  Serial.println("coucou");
#ifdef TFT
  tftSetup();
#endif
#ifdef SD_CSV
  setupCSV();
#endif
#ifdef SD_BIN
  setupBIN();
#endif
#ifdef TEMP
  setupTemperature();
#endif
#ifdef HUMIDITY
  setupHumidity();
#endif
#ifdef LCD
  lcdSetup();
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
#ifdef SD_CSV
  loopCSV();
#endif
#ifdef SD_BIN
  loopBIN();
#endif
  delay(500);
}
