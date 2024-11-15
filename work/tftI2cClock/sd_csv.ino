#include "config.h"
#ifdef SD_CSV
#include <SD.h>
#define SD_CS 7
#define FILE_PATHNAME_CSV "log.csv"
File myFile;
void setupCSV() {
  SD.begin(SD_CS);
}
void loopCSV() {
  myFile = SD.open(FILE_PATHNAME_CSV, FILE_WRITE);
  char buff[12];
  //dates
  sprintf(buff, "%2d/%2d/%4d;", datas.dateTime.Day, datas.dateTime.Month, tmYearToCalendar(datas.dateTime.Year));
  myFile.print(buff);
  //time
  sprintf(buff, "%02d:%02d:%02d;", datas.dateTime.Hour, datas.dateTime.Minute, datas.dateTime.Second);
  myFile.print(buff);
#ifdef PRESSURE
  myFile.print(datas.pressure_hpa);
  myFile.print(';');
#endif
#ifdef TEMP
  myFile.print(datas.temperature);
  myFile.print(';');
#endif
#ifdef HUMIDITY
  myFile.print(datas.humidity);
  myFile.print(';');
#endif
  myFile.print('\n');
  myFile.close();
}
#endif
