unsigned long agora = 0;

void setup() {
  pinMode(13,OUTPUT);
}

int conta3 = 0;
int EstadoLed = HIGH;

void loop() {

  digitalWrite(13,EstadoLed);
  // Criar a pausa de 3 segundos
  agora = millis();
  while(millis() < agora + 1000) {
    // Pausa de 3 segundos. Nada a fazer
  }
  conta3 ++;
  if ( conta3 == 3) {
    if (EstadoLed == HIGH) EstadoLed = LOW;
    else  EstadoLed = HIGH;
    conta3 = 0;
  }

  
}
