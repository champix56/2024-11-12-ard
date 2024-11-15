#include "config.h"
#ifdef LCD_I2C
#include "struct.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

uint8_t DEG_CHAR[8] = {0b00000, 0b00100, 0b01010, 0b01010, 0b00100, 0b00000, 0b00000, 0b00000};
LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcdSetup() {
  lcd.init();
  lcd.createChar(0, DEG_CHAR);
  lcdPrintDefault();
}

void lcdLoop() {
  lcdPrintInfo(data.dTime, data.temp, data.humidity);
}

void lcdPrintFirstLine(uint8_t hour, uint8_t minute, uint8_t second, float temp) {
  lcd.setCursor(0, 0);
  lcd.print(hour);
  lcd.print(':');
  lcd.print(minute);
  lcd.print(':');
  lcd.print(second);
#ifdef TEMP
  lcd.setCursor(9, 0);
  lcd.print(temp);
  lcd.write(0);
  lcd.write('C');
#endif
}

void lcdPrintSecondLine(uint8_t day, uint8_t month, uint8_t year, uint8_t humidity) {
  lcd.setCursor(1, 1);
  lcd.print(day);
  lcd.print('/');
  lcd.print(month);
  lcd.print('/');
  lcd.print(year);

  lcd.setCursor(12, 1);
  lcd.print(humidity);
  lcd.print('%');
}

void lcdPrintInfo(tmElements_t tm, float temp, uint8_t humidity) {
  lcdPrintFirstLine(tm.Hour, tm.Minute, tm.Second, temp);
  lcdPrintSecondLine(tm.Day, tm.Month, tmYearToCalendar(tm.Year), humidity);
}

void lcdPrintDefault() {
  lcd.clear();
  lcd.backlight();
  lcd.print("Hello, le monde!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("00:00:00");
  lcd.setCursor(9, 0);
  lcd.print("00.00");
  lcd.write(0);
  lcd.print('C');
  lcd.setCursor(1, 1);
  lcd.print("00/00/0000");
  lcd.setCursor(12, 1);
  lcd.print("00%");
  delay(2000);
  lcd.clear();
}
#endif