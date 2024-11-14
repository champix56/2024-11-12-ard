#include "config.h"
#ifdef LCD_I2C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//#define DEG_CHAR (uint8_t[]){0b00000,0b00100,0b01010,0b01010,0b00100,0b00000,0b00000,0b00000}
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
  lcd.init();  // initialize the lcd
  lcd.createChar(0, DEG_CHAR);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(_LCD_TIME_START_POSITION_X, _LCD_TIME_START_POSITION_Y);
  lcd.print("00:00:00");
  lcd.setCursor(_LCD_TEMP_START_POSITION_X, _LCD_TEMP_START_POSITION_Y);
  lcd.print("00.00");
  lcd.write(0);
  lcd.print("c");
  lcd.setCursor(_LCD_DATE_START_POSITION_X, _LCD_DATE_START_POSITION_Y);
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
  char buffer[9];
  dtostrf(value, minLen, prec, buffer);
  lcd.setCursor(x, y);
  lcd.print(buffer);
}
#endif