// receptor desconectar o VCC do HC para gravar o NodeMCU

#include <SoftwareSerial.h> // Inclui Biblioteca
SoftwareSerial mySerial(D7, D8);       // Simula RX e TX em outras portas 
const int ledPin = D4;               // Define que ledPin estará na porta 13
void setup() {
  Serial.begin(9600);                // Taxa de transferência da Serial
  mySerial.begin(9600);              // Taxa de transferência do HC12
  pinMode(ledPin, OUTPUT);           // Define ledPin como saída
}
bool flag = false;

void loop() {
  if (mySerial.available() > 1) {    // Se o sinal de mySerial for maior que 1
    int input = mySerial.read();     // input será igual ao valor de mySerial
    Serial.println(input);           // Escreve na serial o valor de input
    if (input == '1') {                  // O valor de input for diferente de 1
      digitalWrite(ledPin, LOW);    // Led acende 
      if (flag) {
        flag=false; 
        digitalWrite(ledPin, LOW);
      } else {
        flag=true;
        digitalWrite(ledPin, HIGH);
      }                   // 100 milissegundos 
    }   
  }
}