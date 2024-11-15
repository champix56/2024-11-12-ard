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
#endif