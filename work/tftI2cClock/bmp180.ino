#include "config.h"
#ifdef _BMP180_CHIP_PRESENT
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
bool isBMPAlreadyInitialized = false;
void setupBMP180() {
  if (!isBMPAlreadyInitialized) {
    bmp.begin();
    isBMPAlreadyInitialized = true;
  }
}
#ifdef BMP180_PRESSURE
void pressureSetup() {
  setupBMP180();
}
void pressureLoop() {
  datas.pressure_hpa = (bmp.readPressure() / 1000.0F);
}
#endif
#ifdef BMP180_TEMPERATURE
void temperatureSetup() {
  setupBMP180();
}
void temperatureLoop() {
  datas.temperature = bmp.readTemperature();
}
#endif

#endif
