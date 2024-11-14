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
  lcd.setCursor(0, 0);
  lcd.print("00:00:00");
  lcd.setCursor(9, 0);
  lcd.print("00.00");
  lcd.write(0);
  lcd.print("c");
  lcd.setCursor(3, 1);
  lcd.print("00/00/0000");
}


void lcdLoop() {
  //affichage Date & Heure
  printIntOnLcd(tmYearToCalendar(tm.Year), 9, 1, "%04d");
  printIntOnLcd(tm.Month, 6, 1, "%02d");
  printIntOnLcd(tm.Day, 3, 1, "%02d");
  printIntOnLcd(tm.Hour, 0, 0, "%02d");
  printIntOnLcd(tm.Minute, 3, 0, "%02d");
  printIntOnLcd(tm.Second, 6, 0, "%02d");
  //affichage temperature
    printFloatOnLcd(temperature, 9, 0, 4, 2);
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