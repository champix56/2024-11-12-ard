#define _DEBUG
/******
  definition de l'ecran
*******/
//#define LCD_I2C
//#define LCD_CLASSIC
#define TFT_ST7735_128_160
/********
humidity sensors
*********/
#define DHT11_HUMIDITY
//#define DHT22_HUMIDITY
/*******
  definition capteur de pression atmo
*********/
 
//#define BMP180_PRESSURE
/*******
  definition capteur de temperature
*********/
#define DS18B20
//#define DHT11_TEMPERATURE
//#define BMP180_TEMPERATURE

/********
 SD CARD (can be both of them)
*********/
//#define SD_CSV
#define SD_BIN


/**************************************
        GENERIC DEFINE DO NOT TOUCH
***************************************/
#if defined(SD_BIN)|| defined(SD_CSV)
  #undef SD_CARD
#endif

#if defined(LCD_I2C)|| defined(LCD_CLASSIC)
  #undef LCD_CLASSIC
#endif

#if defined(DS18B20) || defined(DHT11_TEMPERATURE)||defined(BMP180_TEMPERATURE)
  #define TEMP
#endif

#if defined(DHT11_HUMIDITY)|| defined(DHT22_HUMIDITY)
  #define HUMIDITY
#endif

#if defined(LCD_I2C)|| defined(LCD_CLASSIC)
  #define LCD
#endif
#if defined(TFT_ST7735_128_160) 
  #define TFT
#endif
#if defined(DHT11_HUMIDITY)|| defined(DHT11_TEMP)
  #define _DHT11_CHIP_PRESENT
#endif
#if defined(BMP180_PRESSURE)|| defined(BMP180_TEMPERATURE)
  #define _BMP180_CHIP_PRESENT
#endif
#if defined(BMP180_PRESSURE) 
  #define PRESSURE
#endif
#include "config_adv.h"
