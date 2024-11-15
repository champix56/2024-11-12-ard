#include "config.h"
#ifdef LCD_CLASSIC
#include "struct.h"
#include <Wire.h>
#include <LiquidCrystal.h>

uint8_t DEG_CHAR[8] = {0b00000, 0b00100, 0b01010, 0b01010, 0b00100, 0b00000, 0b00000, 0b00000};
// LiquidCrystal_I2C lcd(0x27, 16, 2);
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void lcdSetup() {
  lcd.begin();
}

void lcdLoop() {
  if (Serial.available() == 0) {
    delay(200); 
    return;
  }

  while (Serial.available() > 0) {
    uint8_t readByte = Serial.read();
    if (isAlphaNumeric(readByte)) {
      Serial.print((char)readByte);
      lcd.print((char)readByte);
    }
  }
}
#endif