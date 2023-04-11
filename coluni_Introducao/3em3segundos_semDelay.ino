unsigned long agora = 0;

void setup() {
  pinMode(13,OUTPUT);
}

void loop() {

  digitalWrite(13,HIGH);
  // Criar a pausa de 3 segundos
  agora = millis();
  while(millis() < agora + 3000) {
    // Pausa de 3 segundos. Nada a fazer
  }
  digitalWrite(13,LOW);
  // Criar a pausa de 3 segundos
  agora = millis();
  while(millis() < agora + 3000) {
    // Pausa de 3 segundos. Nada a fazer
  }

  
}
