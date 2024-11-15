#include "config.h"

#ifdef DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setupTemperature() {
  sensors.begin();
}
void loopTemperature() {
  sensors.requestTemperatures();  // Send the command to get temperatures
  datas.temperature = sensors.getTempCByIndex(0);
}

#endif