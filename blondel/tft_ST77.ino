#include "struct.h"
#include "config.h"
#ifdef TFT_ST7735_128_1660
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "tft_position.h"

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void tftSetup() {
  // Serial.begin(9600);
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  loadingScreen();
  printStaticSceen();
}

void tftLoop() {
  // Print date
  char buffer[10];
  sprintf(buffer, "%02d/%02d/%04d", data.dTime.Day, data.dTime.Month, data.dTime.Year + 1970);
  tft.fillRect(_SCREEN_DATE_X, _SCREEN_DATE_Y, 80, _SCREEN_DATE_SIZE*8, BGCOLOR);
  tftPrint(_SCREEN_DATE_X, _SCREEN_DATE_Y, buffer, FGCOLOR);

  // Print time
  sprintf(buffer, "%02d:%02d:%02d", data.dTime.Hour, data.dTime.Minute, data.dTime.Second);
  tft.fillRect(_SCREEN_TIME_X, _SCREEN_TIME_Y, 80, _SCREEN_TIME_SIZE*8, BGCOLOR);
  tftPrint(_SCREEN_TIME_X, _SCREEN_TIME_Y, buffer, FGCOLOR);

#ifdef TEMP
  // Print temperature
  dtostrf(data.temp, 4, 2, buffer);
  tft.fillRect(_SCREEN_TEMP_X, _SCREEN_TEMP_Y, 80, _SCREEN_TEMP_SIZE*8, BGCOLOR);
  tftPrint(_SCREEN_TEMP_X, _SCREEN_TEMP_Y, buffer, FGCOLOR);
  tft.write(0xF8);
  tft.print("C");
#endif

  // Print pressure
  sprintf(buffer, "%02d", data.pressure_hpa);
  tft.fillRect(_SCREEN_PRESSURE_X, _SCREEN_PRESSURE_Y, 80, _SCREEN_PRESSURE_SIZE*8, BGCOLOR);
  tftPrint(_SCREEN_PRESSURE_X, _SCREEN_PRESSURE_Y, buffer, FGCOLOR);
  tft.print("hPa");

#ifdef HUMIDITY
  // Print humidity
  sprintf(buffer, "%02d", data.humidity);
  tft.fillRect(_SCREEN_HUMIDITY_X, _SCREEN_HUMIDITY_Y, 80, _SCREEN_HUMIDITY_SIZE*8, BGCOLOR);
  tftPrint(_SCREEN_HUMIDITY_X, _SCREEN_HUMIDITY_Y, buffer, FGCOLOR);
  tft.print("%");
#endif
  delay(2000);
}

void loadingScreen() {
  tft.fillScreen(ST77XX_BLACK);
  tftPrint(0, 0, (char*)"Bienvenue dans cette station meteo hightech ...", FGCOLOR);
  delay(2000);
  tft.fillScreen(ST77XX_BLACK);
}

void tftPrint(int x, int y, char *text, uint16_t color) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void printStaticSceen() {
  // Print date
  tftPrint(0, _SCREEN_DATE_Y, (char*)"Date:", FGCOLOR);
  // Print time
  tftPrint(0, _SCREEN_TIME_Y, (char*)"Time:", FGCOLOR);
  // Print temperature
  tftPrint(0, _SCREEN_TEMP_Y, (char*)"Temperature:", FGCOLOR);
  // Print pressure
  tftPrint(0, _SCREEN_PRESSURE_Y, (char*)"Pressure:", FGCOLOR);
  // Print humidity
  tftPrint(0, _SCREEN_HUMIDITY_Y, (char*)"Humidity:", FGCOLOR);
}
#endif