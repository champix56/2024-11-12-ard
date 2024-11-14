//#define _DEBUG
/******
  definition de l'ecran
*******/
#define LCD_I2C
//#define LCD_CLASSIC
/*******
  definition capteur de temperature
*********/
#define DS18B20
 

#if defined(LCD_I2C)|| defined(LCD_CLASSIC)
  #undef LCD_CLASSIC
#endif

#if defined(DS18B20) 
  #define TEMP
#endif

#if defined(LCD_I2C)|| defined(LCD_CLASSIC)
  #define LCD
#endif
 
