void setupSerial(){
  Sertial.begin(9600);
}
void EmiterLoop(){
  union U_Datas u;
  u.data=datas;
  for(uint8_t i=0;i<sizeof(struct S_Datas);i++){
    Serial.write(u.b[i]);
  }
  Serial.write((byte)0x0);
}
struct S_Datas RecieverLoop(){
   union U_Datas u;
  while(Serial.available()){
    for(uint8_t i=0; i<sizeof(struct S_Datas);i++)
    {
      u.b[i]=Serial.read();
    }
    //read le 0x0 de fin de tranqmition
    Serial.read();
  }
  return u.data;
}