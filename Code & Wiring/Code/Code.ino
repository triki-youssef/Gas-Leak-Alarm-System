// Pin definitions
const int mq6Pin = A0;       // MQ-6 sensor analog output
const int buzzerPin = 8;     // Buzzer pin
const int ledPin = 7;        // LED pin

// Threshold for gas detection (adjust based on testing)
const int gasThreshold = 400; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(mq6Pin);
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold) {
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
    digitalWrite(ledPin, HIGH);    // Turn on LED
  } else {
    digitalWrite(buzzerPin, LOW);  // Deactivate buzzer
    digitalWrite(ledPin, LOW);     // Turn off LED
  }

  delay(500); // Read every 0.5 sec
}
