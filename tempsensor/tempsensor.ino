int Temp = 10;
float val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);
  val = analogRead(Temp);
  float celVal = (val/1024.0)*50;
  Serial.print(celVal);
  Serial.println();
}
