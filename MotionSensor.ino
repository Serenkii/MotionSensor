void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, false);
  delay(100);
  digitalWrite(LED_BUILTIN, true);
  delay(300);
}
