#include "config.h"

#ifdef SD_BIN
#include "struct.h"
#include <SD.h>
#define SD_CS 7
#define FILE_PATHNAME_BIN "log.BIN"
File myFileBin;
void setupBIN() {
  SD.begin(SD_CS);
}
void loopBIN() {
  union U_Datas udatas;
  udatas.datas=datas;
  myFileBin = SD.open(FILE_PATHNAME_BIN, FILE_WRITE);
  myFileBin.seek(myFileBin.size());
  for (uint16_t i = 0; i < sizeof(struct S_Datas); i++) {
    myFileBin.write(udatas.b[i]);
  }
  myFileBin.write((byte)0x0);
  myFileBin.close();
}
struct S_Datas readFile(){
  union U_Datas u;
  myFileBin.open(FILE_PATHNAME_BIN, FILE_READ);
  while(myFileBin.available()){
    for(uint8_t i=0;i<sizeof(struct S_Datas);i++)
    {
      u.b[i]=myFileBin.read();
    }
    //lecture du separateur 0x0
    myFileBin.read();
     myFileBin.close();
     return  u.data;
  }
 
}
#endif
