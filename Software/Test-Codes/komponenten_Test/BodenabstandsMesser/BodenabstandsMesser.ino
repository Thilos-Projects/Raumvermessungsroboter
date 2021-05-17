void setup() {
  Serial.begin(115200);
  pinMode(34,INPUT);
}

void loop() {
  Serial.println(analogRead(34));
  delay(100);
}
