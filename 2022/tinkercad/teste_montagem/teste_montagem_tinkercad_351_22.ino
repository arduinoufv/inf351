/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 6;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (buttonState) Serial.println(buttonState);
  delay(100);        // delay in between reads for stability
  if ( Serial.available() ) {
    char c = Serial.read();
    switch(c) {
      case 'q': digitalWrite(12,!digitalRead(12));
                break;
      case 'w': digitalWrite(11,!digitalRead(11));
                break;
      case 'e': digitalWrite(10,!digitalRead(10));
                break;
      case 'r': digitalWrite(9,!digitalRead(9));
                break;
      case 't': digitalWrite(8,!digitalRead(8));
                break;
      case 'y': digitalWrite(7,!digitalRead(7));
                break;
    }
  }
  
}
