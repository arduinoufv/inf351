void setup() {
 // put your setup code here, to run once:
 pinMode(13, OUTPUT);
}

int Ton = 1000;
int Toff = 0;
void loop() {
 // put your main code here, to run repeatedly:
 for (int i=0; i < 1000; i++) 
   for (int j=0; j< 10; j++) 
   {
      digitalWrite(13,HIGH);
      delayMicroseconds(Ton-i);
      digitalWrite(13,LOW);
      delayMicroseconds(Toff+i);
   }
   
}
