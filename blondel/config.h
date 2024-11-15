#ifndef __CONFIG_H_
#define __CONFIG_H_

#define SD_CARD
// #define LCD_I2C
#define TFT_ST7735_128_1660
#define DS18B20
#define BMP180
#define DHT11_HUMIDITY
#define DHT11_TEMP
// #define RTC
// #define PRESSURE
// #define LCD_CLASSIC

#if defined(SD_CARD)
  #define SD_ENABLED
#endif

#if defined(BMP180)
  #define PRESSURE
#endif

#if defined(TFT_ST7735_128_1660)
  #define TFT
#endif

#if defined(DS18B20) || defined(DHT11_TEMP)
  #define TEMP
#endif

#if defined(DHT11_HUMIDITY)
  #define HUMIDITY
#endif

#if defined(LCD_I2C) && defined(LCD_CLASSIC)
  #undef LCD_CLASSIC
#endif

#if defined(LCD_I2C) || defined(LCD_CLASSIC)
  #define LCD
#endif
#endif