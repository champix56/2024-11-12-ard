#ifndef __STRUCT_H_
#define __STRUCT_H_
#include <TimeLib.h>
#include "config.h"

struct S_Datas {
  tmElements_t dTime;
#ifdef HUMIDITY
  uint8_t humidity;
#endif
#ifdef PRESSURE
  uint8_t pressure_hpa;
#endif
#ifdef TEMP
  float temp;
#endif
};
#endif