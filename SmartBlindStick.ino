// Define pin numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// Variables
long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT);   // Trigger pin
  pinMode(echoPin, INPUT);    // Echo pin
  pinMode(buzzer, OUTPUT);    // Buzzer
  pinMode(ledPin, OUTPUT);    // LED (optional)

  Serial.begin(9600);         // Begin serial communication
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;
  safetyDistance = distance;

  // Alert at 15 cm or less
  if (safetyDistance <= 15 && safetyDistance > 0) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }

  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(50);
}
