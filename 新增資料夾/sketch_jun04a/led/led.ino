#include "LedControl.h"
#define DIN 4   //DataIn
#define CS  3   //LOAD
#define CLK 2   //CLK
LedControl lc=LedControl(DIN,CLK,CS,1);
//============ heart ==============
byte heart[8] = {
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B01100110,
  B00000000
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
}

void loop() {
  for (int i = 0; i < 8; i++)
    lc.setColumn(0, i, heart[i]);
  delay(1000);
  /*for (int i = 0;i < 8; i++)
    lc.setRow(0, 7-i, heart[i]);
  delay(1000);
  for (int i = 0; i < 8; i++)
    lc.setColumn(0, i, heart[i]);
  delay(1000);
  for (int i = 0; i < 8; i++)
    lc.setColumn(0, 7-i, heart[i]);
  delay(1000);*/
}
