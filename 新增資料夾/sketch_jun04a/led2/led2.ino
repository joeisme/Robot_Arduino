#include "LedControl.h"
#include <CapacitiveSensor.h>
CapacitiveSensor cs_ao = CapacitiveSensor(A0,A1);
#define DIN 4   //DataIn
#define CS  3   //LOAD
#define CLK 2   //CLK
int touched = 0;
LedControl lc=LedControl(DIN,CLK,CS,2);
//============ heart ==============
byte hearts[16] = {//從右而左上而下
  //part 1
    B00011000,
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B01100110,
  B00000000
};
byte things[]={
  B00000000,//1
  B00000100,//2
  B00001010,//3
  B11110001,//4
  B00000001,//5
  B00000001,//6
  B00000000,//7
  B00000000//8
  //part 2
  /*B00000000,//1
  B00000100,//2
  B00001010,//3
  B11110001,//4
  B00000001,//5
  B00000001,//6
  B00000000,//7
  B00000000//8*/
};
//=================================
void setup() {
  //設定正常運作模式
  //true = shutdown mode ; false = normal operation
  lc.shutdown(0,false); //模組0
  //設定亮度
  lc.setIntensity(0,1); //模組0
  //清除DSP
  lc.clearDisplay(0); //模組0
  lc.shutdown(1,false); //模組1
  //設定亮度
  lc.setIntensity(1,1); //模組1
  //清除DSP
  lc.clearDisplay(1); //模組1
  cs_ao.set_CS_AutocaL_Millis(0xFFFFFFF);
  Serial.begin(9600);
}

void loop() {
 long total = cs_ao.capacitiveSensor(50);
    Serial.println(total);
    if(total>1000){
      touched ++;
      delay(250);
    }
      
if(touched%2==0){
  for(int i=0;i<8;i++){
      lc.setColumn(0,i,things[i]);
      lc.setRow(1,i,things[i]); 
}
}
else{
  for(int i=0;i<8;i++){
      lc.setColumn(0,i,hearts[i]);
      lc.setRow(1,i,hearts[i]);     
    }
}


/* if(total>1000){
    for(int i=0;i<8;i++){
      lc.setColumn(0,i,things[i]);
      lc.setRow(1,i,things[i]);     
    }
 }
 else{
    for(int i=0;i<8;i++){
      lc.setColumn(0,i,hearts[i]);
      lc.setRow(1,i,hearts[i]);     
    }
 }*/
     /* delay(1000);
  for (int i = 0; i <8; i++){
    lc.setColumn(0, i, heart[i]);
    lc.setColumn(1, i, heart[i+8]);
  }
    
  delay(1000);
  for (int i = 0; i <8; i++){
    lc.setRow(0, i, heart[i]);
    lc.setRow(1, i, heart[i+8]);
  }
    
  delay(1000);
  for (int i = 0; i <8; i++){
    lc.setRow(0, 7-i, heart[i]);
    lc.setRow(1, 7-i, heart[i+8]);
  }
    
  delay(1000);*/
 
}
