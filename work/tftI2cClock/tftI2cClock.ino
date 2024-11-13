//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <TimeLib.h>
#include <DS1307RTC.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  lcd.init();  // initialize the lcd

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("00:00:00");
  lcd.setCursor(3, 1);
  lcd.print("00/00/0000");
}


void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    printOnLcd(tmYearToCalendar(tm.Year), 9, 1, "%04d");
    printOnLcd(tm.Month, 6, 1, "%02d");
    printOnLcd(tm.Day, 3, 1, "%02d");
    printOnLcd(tm.Hour, 1, 0, "%02d");
    printOnLcd(tm.Minute, 4, 0, "%02d");
    printOnLcd(tm.Second, 7, 0, "%02d");
  }
}
void printOnLcd(uint16_t value, uint8_t x, uint8_t y, const char *format) {
  char buffer[5];
  sprintf(buffer, format, value);
  lcd.setCursor(x, y);
  lcd.print(buffer);
}
