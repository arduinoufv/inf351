/* PWM Uno

Pins 3, 5, 6, 9, 10, 11
490 Hz (pins 5 and 6: 980 Hz)
2ms  or 1ms
2ms/256 = 8 us 
*/

int ton = 2048;
int sinal = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  delayMicroseconds(ton);
  digitalWrite(13,LOW);
  delayMicroseconds(2048-ton);
  ton = ton + sinal*8;
  if ( ton < 32 && sinal < 0 ) {
    sinal = -sinal; 
  } else if ( ton > 2016 && sinal > 0 ) {
    sinal = -sinal;
  }
}
