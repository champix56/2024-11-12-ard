#include <TimeLib.h>
#include <DS1307RTC.h>
#include "config.h"
#include "struct.h"

struct S_Datas data;

void setup() {
  RTC.read(data.dTime);
  Serial.begin(9600);
  Serial.println("HELLO WORLD");
#ifdef TFT
  tftSetup();
#endif
#ifdef HUMIDITY
  humiditySetup();
#endif
#ifdef TEMP
  tempSetup();
#endif
#ifdef LCD
  lcdSetup();
#endif
#ifdef PRESSURE
  pressureSetup();
#endif
#ifdef SD_ENABLED
  storageSetup();
#endif
}

void loop() {
  if (RTC.read(data.dTime)) {
#ifdef PRESSURE
    pressureLoop();
#endif
#ifdef HUMIDITY
    humidityLoop();
#endif
#ifdef TEMP
    tempLoop();
#endif
#ifdef LCD
    lcdLoop();
#endif
#ifdef TFT
    tftLoop();
#endif
#ifdef SD_ENABLED
  storageLoop();
#endif
  }
}
