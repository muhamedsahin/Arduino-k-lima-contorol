#include <IRremote.h>
IRsend irsend;
void setup(){
  Serial.begin(9600);
}

void loop(){
  while(Serial.available() > 0 ){
    String str = Serial.readString();
    if(str.indexOf("on") > -1){
       Serial.println("acıldı");
       unsigned int  kilimaon[59] = {8650,3900, 600,1450, 500,500, 450,550, 550,450, 450,1600, 500,500, 500,500, 500,500, 450,600, 400,600, 550,450, 450,550, 450,550, 450,550, 600,450, 450,550, 500,500, 450,550, 500,1550, 400,1550, 500,550, 450,1500, 500,550, 550,450, 450,550, 450,1550, 600,1450, 400,1600, 550};  // LG 0
       irsend.sendRaw(kilimaon,59,38);
      }else if(str.indexOf("off") > -1){
       Serial.println("kapandı");
       unsigned int  kilimaoff[59] = {8650,4000, 550,1500, 550,450, 450,550, 500,500, 500,1550, 450,550, 450,550, 500,500, 500,1550, 450,1550, 500,500, 500,500, 500,550, 450,550, 450,550, 450,550, 500,500, 500,550, 500,500, 450,550, 450,550, 450,1550, 500,550, 450,1550, 500,500, 500,500, 500,550, 450,1550, 450};  // LG 0
       irsend.sendRaw(kilimaoff,59,38);
      } 
    else{
      Serial.println("böyle bir komut yok");
    }
  }
}
