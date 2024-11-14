
#define DEBUG_SERIAL_SPEED 9600
void setupDebug(){
  #ifdef _DEBUG
  Serial.begin(DEBUG_SERIAL_SPEED);
  #endif
}
void SerialPrintInt(uint32_t value){
   #ifdef _DEBUG
  Serial.println(value);
  #endif
}