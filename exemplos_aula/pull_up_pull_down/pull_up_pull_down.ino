void setup() {
  // put your setup code here, to run once:
 pinMode(2,INPUT_PULLUP);
 Serial.begin(9600);
}

int conta = 0;
int marcador = 0;
byte a;

void loop() {
  // put your main code here, to run repeatedly:
   a = digitalRead(2);
   if ( a == 0 && marcador == 0) { 
    conta++; 
    marcador = 1;
    Serial.println(conta);
   } else if ( a == 0 && marcador == 1 ) {
     // nada
   } else if ( a == 1 && marcador == 1 ) {
     marcador = 0;
   }
   
  
}
