/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
// include the library code:
#include <LiquidCrystal.h>
#define RS 12
#define EN 11
#define D4 7
#define D5 6
#define D6 5
#define D7 4

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  //demarrage serie
  Serial.begin(9600);
  Serial.print("Hello\n");
  //demarrage de l'instance de lcd
  lcd.begin(16, 2);
  lcd.print("DEMAT BREIZH");
}

void loop() {
  if (Serial.available() == 0) {
    delay(200);
    return;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  while (Serial.available() > 0) {
    uint8_t c = Serial.read();
    if (isAlphaNumeric(c)) {
      lcd.write(c);
      //Serial.print((char)c);
      Serial.write(c);
    }
  }
  Serial.print("\n");
}
