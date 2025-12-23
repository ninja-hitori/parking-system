#define trigPin 9
#define echoPin 10

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  // Check slot status
  if (distance > 0 && distance < 10) {
    Serial.println("OCCUPIED");
  } else {
    Serial.println("SLOT FREE");
  }

  delay(500);
}



