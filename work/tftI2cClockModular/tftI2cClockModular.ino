//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <TimeLib.h>
#include <DS1307RTC.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//#define DEG_CHAR (uint8_t[]){0b00000,0b00100,0b01010,0b01010,0b00100,0b00000,0b00000,0b00000}
uint8_t DEG_CHAR[8]={
0b00000,
0b00100,
0b01010,
0b01010,
0b00100,
0b00000,
0b00000,
0b00000
};
void setup() {
  Serial.begin(9600);
  lcd.init();  // initialize the lcd
  lcd.createChar(0,DEG_CHAR );
  sensors.begin();
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


void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    printOnLcd(tmYearToCalendar(tm.Year), 9, 1, "%04d");
    printOnLcd(tm.Month, 6, 1, "%02d");
    printOnLcd(tm.Day, 3, 1, "%02d");
    printOnLcd(tm.Hour, 0, 0, "%02d");
    printOnLcd(tm.Minute, 3, 0, "%02d");
    printOnLcd(tm.Second, 6, 0, "%02d");
  }
  sensors.requestTemperatures(); // Send the command to get temperatures
  char buffer[6];
  float t0=sensors.getTempCByIndex(0);
  dtostrf(t0, 4, 2, buffer);
  lcd.setCursor(9,0);
  lcd.print(buffer);
  Serial.println(buffer);
  delay(500);
}
void printOnLcd(uint16_t value, uint8_t x, uint8_t y, const char *format) {
  char buffer[5];
  sprintf(buffer, format, value);
  lcd.setCursor(x, y);
  lcd.print(buffer);
}
