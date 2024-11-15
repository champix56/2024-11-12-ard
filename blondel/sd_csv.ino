#include "config.h"
#ifdef SD_CARD
#include <SD.h>

#define CHIP_SELECT_SD_CARD 7
#define FILE_PATH_NAME_CSV "data.csv"
File dataFile;

void storageSetup() {
  SD.begin(CHIP_SELECT_SD_CARD);
}

void storageLoop() {
  // if (dataFile.available()) {
    dataFile = SD.open(FILE_PATH_NAME_CSV, FILE_WRITE);
    char buffer[11];
    // Date
    sprintf(buffer, "%02d/%02d/%04d;", data.dTime.Day, data.dTime.Month, data.dTime.Year + 1970);
    dataFile.print(buffer);
    Serial.print(buffer);

    // Time
    sprintf(buffer, "%02d:%02d:%02d;", data.dTime.Hour, data.dTime.Minute, data.dTime.Second);
    dataFile.print(buffer);
    Serial.print(buffer);

    // Temperature
    dtostrf(data.temp, 4, 2, buffer);
    dataFile.print(buffer);
    dataFile.print(';');
    Serial.print(buffer);

    // Pressure
    sprintf(buffer, "%03d;", data.pressure_hpa);
    dataFile.print(buffer);
    Serial.print(buffer);

    // Humidity
    sprintf(buffer, "%02d", data.humidity);
    dataFile.print(buffer);
    dataFile.print("\n");
    Serial.println(buffer);

    dataFile.close();
  // }
}
#endif