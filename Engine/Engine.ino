#define p1 2
#define p2 3
#define p3 4
#define p4 5

void setup(){
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
}
void loop(){
  //delay(100);
  Onfwd(1350,1350);
  delay(100);
  /*Onfwd(1350,-1350);e
  delay(100);
  Onfwd(1350,1350);
  delay(100);
  Onfwd(-1350,-1350);*/
}
void Onfwd(int R,int L){
  if(R>=0){
    int PR = R*5/2;
    if(PR>255)
      PR=255;
    analogWrite(p1,PR);
    analogWrite(p2,0);
  }
  else{
    int PR=-R*5/2;
    if(PR>255)
      PR=255;
    analogWrite(p1,0);
    analogWrite(p2,PR);
  }
//---------------------
  if(L>=0){
    int PL = L*5/2;
    if(PL>255)
      PL=255;
    analogWrite(p3,PL);
    analogWrite(p4,0);
  }
  else{
    int PL=-L*5/2;
    if(PL>255)
      PL=255;
    analogWrite(p3,0);
    analogWrite(p4,PL);
  }
  
}

