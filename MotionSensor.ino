#define LED_PIN 2         //digital
#define MOTION_SENSOR 7   //digital
#define PHOTO_SENSOR 0    //analog

static const unsigned int LIGHT_ON_DURATION = 20000;  //duration of time the light stays on after motion (in ms)
static const unsigned int PHOTOSENSOR_THRESHOLD = 130;     

unsigned long motionDetected = 0;

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
  digitalWrite(LED_PIN, LEDOnCondition());
}

bool LEDOnCondition() {
  return (motionDetected + LIGHT_ON_DURATION > millis()) && (analogRead(PHOTO_SENSOR) < PHOTOSENSOR_THRESHOLD);
}

void detectMotion() {
  if (digitalRead(MOTION_SENSOR)) {
    motionDetected = millis();
    digitalWrite(LED_BUILTIN, HIGH);
    return;
  }
  digitalWrite(LED_BUILTIN, LOW);
}






