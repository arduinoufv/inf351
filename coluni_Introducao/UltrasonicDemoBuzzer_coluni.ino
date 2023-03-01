#include <Ultrasonic.h>

const int pinoBuzzer = 5;
#define TRIGGER_PIN  3
#define ECHO_PIN     2

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup()
  {
  Serial.begin(9600);
  pinMode(pinoBuzzer, OUTPUT); 
  }

void loop()
  {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.println(cmMsec);
  int t;
  t = map(microsec,0,5500,25,500);
  int m=0;
  while ( m < 1000) {
    tone(pinoBuzzer,800);
    delay(t);
    noTone(pinoBuzzer);
    delay(t);
    m += t;
  }  
}
