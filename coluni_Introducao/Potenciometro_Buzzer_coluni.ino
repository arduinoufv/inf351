const int pinoBuzzer = 5;

void setup()
  {
  Serial.begin(9600);
  pinMode(pinoBuzzer, OUTPUT); 
  }

void loop()
  {
  int pot = analogRead(A0);
  Serial.print("Analogico: ");
  Serial.println(pot);
  int t;
  t = map(pot,0,1024,25,500);
  int m=0;
  while ( m < 1000) {
    tone(pinoBuzzer,800);
    delay(t);
    noTone(pinoBuzzer);
    delay(t);
    m += t;
  }  
}
