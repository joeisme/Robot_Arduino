#define trigPin 12
#define echoPin 13

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long microsec = pulseIn(echoPin,HIGH);
  float cmMsec = (microsec / 2) / 29.1; //將時間換算成距離cm
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.println(cmMsec);
  delay(50);
}
