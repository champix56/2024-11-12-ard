
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
#include "tft_position.h"

// For the breakout board, you can use any 2 or 3 pins.
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 9  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void setup() {
  // put your setup code here, to run once:
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  LoadingScreen();
}

void loop() {
  tft.fillRect(_SCREEN_DATE_X, _SCREEN_DATE_Y, 80, 20, BGCOLOR);
  tft.setCursor(_SCREEN_DATE_X + 1, _SCREEN_DATE_Y + 3);
  tft.setTextColor(FGCOLOR);
  tft.setTextSize(_SCREEN_DATE_TEXTSIZE);
  tft.print("00/00/2024");

  tft.fillRect(_SCREEN_TIME_X, _SCREEN_TIME_Y, 80, 9, BGCOLOR);
  tft.setCursor(_SCREEN_TIME_X + 1, _SCREEN_TIME_Y + 3);
  tft.setTextColor(FGCOLOR);
  tft.setTextSize(_SCREEN_TIME_TEXTSIZE);
  tft.print("00:00:00");

  delay(600);
}

void LoadingScreen() {
  tft.fillScreen(BGCOLOR);
  tft.setCursor(5, ST7735_TFTHEIGHT_160 / 2 - 8);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(2);
  tft.print("Loading");
  for (int i = 0; i < 3; i++) {
    delay(800);
    tft.print(".");
  }
  delay(800);
  tft.fillScreen(BGCOLOR);
}
