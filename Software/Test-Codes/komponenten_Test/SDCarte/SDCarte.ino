#include "SDCard.h"
#include "conf.h"

SPIClass* myspi = NULL;

void setup(){
  
  SDCardUtill card = SDCardUtill();
  card.begin(&conf);

  Serial.begin(115200);

  Serial.println(card.getCardSize());

}

void loop(){

}
