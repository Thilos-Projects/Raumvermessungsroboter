#include "libs/lib_include.h"

class SDCardUtill{
public:

  //
  //Forbidden pins For SPI:
  //  1,3,6,7,8
  //
  typedef struct{
    public:
      byte MOSI = 0;
      byte MISO = 4;
      byte CS = 15;
      byte SCK = 2;
      bool SPIH = true;
  } pinConfig;

  bool begin(pinConfig* conf){

    pinConf = *conf;

    if(pinConf.SPIH)
      this->spi = new SPIClass(HSPI);
    else
      this->spi = new SPIClass(VSPI);

    spi->begin(pinConf.SCK, pinConf.MISO, pinConf.MOSI, pinConf.CS);
    return mySD.begin(pinConf.CS, *spi) && SD.cardType() != CARD_NONE;
  }
  
  uint64_t getCardSize(){
    return mySD.cardSize() / (1024 * 1024);
  }

private:
  fs::SDFS mySD = fs::SDFS(std::make_shared<VFSImpl>(VFSImpl()));
  SPIClass *spi;
  pinConfig pinConf;

  bool createDir(const char * path){
    return mySD.mkdir(path);
  }

  bool exists(const char * path){
    return mySD.exists(path);
  }

  File getFile(const char * path, bool canCreate, bool isAppend){
    if(isAppend)
      return mySD.open(path, FILE_APPEND);
    if(canCreate)
      return mySD.open(path, FILE_WRITE);
    return mySD.open(path, FILE_READ);
  }

  bool removeFile(const char * path){
    return mySD.remove(path);
  }
};