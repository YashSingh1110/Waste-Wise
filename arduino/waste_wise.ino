#define TRIG_PIN 9
#define ECHO_PIN 10

#define LED_LOW 3
#define LED_MED 4
#define LED_FULL 5

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_LOW, OUTPUT);
  pinMode(LED_MED, OUTPUT);
  pinMode(LED_FULL, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 20) {
    digitalWrite(LED_LOW, HIGH);
    digitalWrite(LED_MED, LOW);
    digitalWrite(LED_FULL, LOW);
  }
  else if (distance > 10) {
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MED, HIGH);
    digitalWrite(LED_FULL, LOW);
  }
  else {
    digitalWrite(LED_LOW, LOW);
    digitalWrite(LED_MED, LOW);
    digitalWrite(LED_FULL, HIGH);
  }

  delay(1000);
}
