const int ledPin = 13;  // Pin connected to the LED
int blinkInterval = 1000; // Initial blink interval in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600);      // Initialize the Serial Monitor
}

void loop() {
  if (Serial.available() > 0) {
    blinkInterval = Serial.parseInt(); // Read the integer value from Serial Monitor

    // Make sure the interval is within a reasonable range
    if (blinkInterval < 50) {
      blinkInterval = 50;
    } else if (blinkInterval > 2000) {
      blinkInterval = 2000;
    }
  }

  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(blinkInterval);       // Wait for the specified interval
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(blinkInterval);       // Wait for the specified interval again
}
