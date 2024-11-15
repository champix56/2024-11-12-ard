#include "config.h"
#ifdef DS18B20
#include "struct.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void tempSetup() {
  sensors.begin();
}

void tempLoop() {
  sensors.requestTemperatures();
  data.temp = sensors.getTempCByIndex(0);
}
#endif