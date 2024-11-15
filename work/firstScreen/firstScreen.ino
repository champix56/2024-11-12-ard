
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
#include "tft_position.h"
#include "struct.h"
// For the breakout board, you can use any 2 or 3 pins.
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 9  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

struct Datas datas;

void setup() {
  // put your setup code here, to run once:
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab

  LoadingScreen();
  datas.dateTime.Year = 2024 - 1970;
  datas.dateTime.Month = 11;
  datas.dateTime.Day = 14;
  datas.dateTime.Hour = 14;
  datas.dateTime.Minute = 15;
  datas.dateTime.Second = 16;

  datas.pressure_hpa = 100;
  datas.humidity = 38;
  datas.temperature = 29.52F;
}

void loop() {
  char buffer[10];

  sprintf(buffer, "%02d/%02d/%04d", datas.dateTime.Day, datas.dateTime.Month, datas.dateTime.Year + 1970);
  tft.setCursor(_SCREEN_DATE_X + 1, _SCREEN_DATE_Y + 3);
  tft.setTextColor(FGCOLOR);
  tft.setTextSize(_SCREEN_DATE_TEXTSIZE);
  tft.fillRect(_SCREEN_DATE_X, _SCREEN_DATE_Y, 120, _SCREEN_DATE_TEXTSIZE * 7+2, BGCOLOR);
  tft.print(buffer);

  sprintf(buffer, "%02d:%02d:%02d", datas.dateTime.Hour, datas.dateTime.Minute, datas.dateTime.Second);
  tft.setCursor(_SCREEN_TIME_X + 1, _SCREEN_TIME_Y + 3);
  tft.setTextColor(FGCOLOR);
  tft.setTextSize(_SCREEN_TIME_TEXTSIZE);
  tft.fillRect(_SCREEN_TIME_X, _SCREEN_TIME_Y, 80, _SCREEN_TIME_TEXTSIZE  * 7+2, BGCOLOR);
  tft.print(buffer);

  dtostrf(datas.temperature, 2, 2, buffer);
  sprintf(buffer, "%s%c", buffer, 0xf8);
  tft.setCursor(_SCREEN_TEMP_X + 1, _SCREEN_TEMP_Y + 3);
  tft.setTextColor(FGCOLOR);
  tft.setTextSize(_SCREEN_TEMP_TEXTSIZE);
  tft.fillRect(_SCREEN_TEMP_X, _SCREEN_TEMP_Y, 80, _SCREEN_TEMP_TEXTSIZE * 7+2, BGCOLOR);
  tft.print(buffer);


  sprintf(buffer, "%3d", datas.humidity);
  tft.setCursor(_SCREEN_HUMIDITY_X + 1, _SCREEN_HUMIDITY_Y + 3);
  tft.setTextColor(FGCOLOR);
  tft.setTextSize(_SCREEN_HUMIDITY_TEXTSIZE);
  tft.fillRect(_SCREEN_HUMIDITY_X, _SCREEN_HUMIDITY_Y, 80, _SCREEN_HUMIDITY_TEXTSIZE * 7+2, BGCOLOR);
  tft.print(buffer);


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
  constFrame();
}
void constFrame() {
  tft.fillScreen(0x0);
  tft.setCursor(_SCREEN_PRESSURE_X + 20, _SCREEN_PRESSURE_Y);
  tft.setTextSize(_SCREEN_PRESSURE_TEXTSIZE);
  tft.setTextColor(FGCOLOR);
  tft.print("hPa");

  tft.drawCircle(100, _SCREEN_TEMP_Y+((_SCREEN_TEMP_TEXTSIZE*5)/2)-3,2,FGCOLOR);
}
