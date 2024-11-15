#include "config.h"
  #ifdef _DHT11_CHIP_PRESENT
  #include <DHT11.h>
  #define DHT11_PIN 5
  DHT11 dht11(DHT11_PIN);
#endif
#ifdef DHT11_HUMIDITY
  void setupHumidity(){}
  void loopHumidity(){
    datas.humidity = dht11.readHumidity();
  }
#endif
#ifdef DHT11_TEMPERATURE
  void setupTemperature() {}
  void loopTemperature() {
     datas.temperature = dht11.readTemperature();
  }
#endif
