#include "config.h"
#include <DHT11.h>
#include "struct.h"

#define DHT11_PIN 5
DHT11 dht11(DHT11_PIN);

#ifdef DHT11_HUMIDITY
void humiditySetup() {
  // Serial.begin(9600);
}

void humidityLoop() {
    data.humidity = dht11.readHumidity();
    // if (data.humidity != DHT11::ERROR_CHECKSUM && data.humidity != DHT11::ERROR_TIMEOUT) {
    //     Serial.print("Humidity: ");
    //     Serial.print(data.humidity);
    //     Serial.println(" %");
    // } else {
    //     // Print error message based on the error code.
    //     Serial.println(DHT11::getErrorString(data.humidity));
    // }
}
#endif
// #ifdef DHT11_TEMP
// void tempLoop() {

// }
// void tempSetup() {
//   int temperature = dht11.readTemperature();
//   if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
//       Serial.print("Temperature: ");
//       Serial.print(temperature);
//       Serial.println(" °C");
//   } else {
//       Serial.println(DHT11::getErrorString(temperature));
//   }
// }
// #endif