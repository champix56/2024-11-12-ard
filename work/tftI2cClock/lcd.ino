#include "config.h"
#ifdef LCD_CLASSIC
#include <LiquidCrystal.h>
#define LCD_W 16
#define LCD_H 2


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
#define LCD_D7 2
#define LCD_D6 3
#define LCD_D5 4
#define LCD_D4 5
#define LCD_EN 11
#define LCD_RS 12
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

uint8_t DEG_CHAR[8] = {
  0b00000,
  0b00100,
  0b01010,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};
void lcdSetup() {
  lcd.begin(LCD_W, LCD_H);
  lcd.createChar(0, DEG_CHAR);
  lcd.setCursor(0, 0);
  lcd.print("00:00:00");
  lcd.setCursor(9, 0);
  lcd.print("00.00");
  lcd.write((uint8_t)0);
  lcd.print("c");
  lcd.setCursor(3, 1);
  lcd.print("00/00/0000");
  lcd.setCursor(_LCD_HUMIDITY_START_POSITION_X, _LCD_HUMIDITY_START_POSITION_Y);
  lcd.print("00%");
}
void lcdLoop() {
  //affichage Date & Heure
  printIntOnLcd(tmYearToCalendar(tm.Year), _LCD_DATE_START_POSITION_X + 6, _LCD_DATE_START_POSITION_Y, "%04d");
  printIntOnLcd(tm.Month, _LCD_DATE_START_POSITION_X + 3, _LCD_DATE_START_POSITION_Y, "%02d");
  printIntOnLcd(tm.Day, _LCD_DATE_START_POSITION_X, _LCD_DATE_START_POSITION_Y, "%02d");
  printIntOnLcd(tm.Hour, _LCD_TIME_START_POSITION_X, _LCD_TIME_START_POSITION_Y, "%02d");
  printIntOnLcd(tm.Minute, _LCD_TIME_START_POSITION_X + 3, _LCD_TIME_START_POSITION_Y, "%02d");
  printIntOnLcd(tm.Second, _LCD_TIME_START_POSITION_X + 6, _LCD_TIME_START_POSITION_Y, "%02d");
  //affichage temperature
  #ifdef TEMP
  printFloatOnLcd(temperature, _LCD_TEMP_START_POSITION_X, _LCD_TEMP_START_POSITION_Y, 4, 2);
  #endif
  #ifdef HUMIDITY
  printIntOnLcd(humidity, _LCD_HUMIDITY_START_POSITION_X, _LCD_HUMIDITY_START_POSITION_Y, "%02d");
  #endif
}

void printIntOnLcd(uint16_t value, uint8_t x, uint8_t y, const char *format) {
  char buffer[5];
  sprintf(buffer, format, value);
  lcd.setCursor(x, y);
  lcd.print(buffer);
}
void printFloatOnLcd(float value, uint8_t x, uint8_t y, uint8_t minLen, uint8_t prec) {
  char buffer[8];
  dtostrf(value, minLen, prec, buffer);
  lcd.setCursor(x, y);
  lcd.print(buffer);
}
#endif