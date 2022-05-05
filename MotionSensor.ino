#define LED_PIN 2
#define MOTION_SENSOR 7

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_SENSOR, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  //Serial.println(digitalRead(MOTION_SENSOR));

}








