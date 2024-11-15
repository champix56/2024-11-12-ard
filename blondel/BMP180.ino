#include "config.h"
#ifdef BMP180
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void pressureSetup() {
  bmp.begin();
}

void pressureLoop() {
  // float bmpTemp = bmp.readTemperature();
  // int32_t bmpPres = readPressure();
  data.pressure_hpa = (uint8_t)bmp.readSealevelPressure() / 100;
  // int32_t bmpSeaLevelPressure = bmp.readSealevelPressure();
  // bmp.readSealevelPressure();
  // bmp.readAltitude(101500);
}
#endif