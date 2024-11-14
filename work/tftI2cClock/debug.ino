
#define DEBUG_SERIAL_SPEED 9600
void setupDebug(){
  #ifdef _DEBUG
  Serial.begin(DEBUG_SERIAL_SPEED);
  Serial.println("DEBUG");
  #endif
}
void SerialPrintUInt(uint32_t value){
   #ifdef _DEBUG
  Serial.println(value);

  #endif
}
void SerialPrintInt(int value){
   #ifdef _DEBUG
  Serial.println(value);
  #endif
}