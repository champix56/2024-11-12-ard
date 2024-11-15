#ifndef __STRUCT_H_
#define __STRUCT_H_
#include "config.h"
#include <TimeLib.h>
struct S_Datas{
  tmElements_t dateTime;
  #ifdef HUMIDITY
  uint8_t humidity;
  #endif
  #ifdef PRESSURE
  uint8_t pressure_hpa;  
  #endif
  #ifdef TEMP
  float temperature;
  #endif
} ;

union U_Datas{
  struct S_Datas datas;
  byte b[sizeof(struct S_Datas)];
  //unit16_t u16[sizeof(struct S_Datas)/2];
};


#endif