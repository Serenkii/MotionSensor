#define LED_PIN 2
#define MOTION_SENSOR 7

static const unsigned int LIGHT_ON_DURATION = 2000;  //duration of time the light stays on after motion (in ms)

unsigned int motionDetected = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_SENSOR, INPUT);

  Serial.begin(9600);
}

void loop() {
  detectMotion();
  updateLED();
  
}

void updateLED() {
  if (LEDOnCondition()) {
    digitalWrite(LED_PIN, HIGH);
    return;
  }
  digitalWrite(LED_PIN, LOW);
}

bool LEDOnCondition() {
  return motionDetected + LIGHT_ON_DURATION > millis();
}

void detectMotion() {
  if (digitalRead(MOTION_SENSOR)) {
    motionDetected = millis();
    Serial.println("Motion detected");
  }
}






