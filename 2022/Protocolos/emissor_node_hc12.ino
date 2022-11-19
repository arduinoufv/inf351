
// Emissor NodeMCU hc12
#include <SoftwareSerial.h> // Inclui Biblioteca
#define buttonPin A0 // Define buttonPin estará na porta A0
SoftwareSerial mySerial(D7, D8);        // Simula RX e TX em outras portas
/* NodeMCU d7 Amarelo RX -> TX HC 12
   NodeMCU d8 Laranja TX -> RX HC 12
*/
const int ledPin = D4;                // Define que ledPin estará na porta 13
bool led = false; 

void setup() {
  pinMode(ledPin, OUTPUT);            // Declara que ledPin é uma saída          // Declara que buttonPin é uma entrada
  mySerial.begin(9600);               // Taxa de transferência do HC12
  Serial.begin(9600);                 // Taxa de transferência da Serial
}

void loop() {
  if (led) {                     // Se o botão for pressionado
    mySerial.print(1);                      // mySerial escreve 2 na serial
    digitalWrite(ledPin, LOW);               // Led acende
    led = false;
  }
  else {                                      // Se não 
    digitalWrite(ledPin, HIGH);                // Led desliga
    led = true;
  }
  mySerial.flush();                           // Limpa a memória
  delay(1000);
}