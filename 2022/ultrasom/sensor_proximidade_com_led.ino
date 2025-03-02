int trig = 4;
int echo = 5;
#define S 6
#define G1 7
#define G2 8
#define Y1 9
#define Y2 10
#define R1 11
#define R2 12 

float distancia;	

void setup() {
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  pinMode(S, INPUT_PULLUP);


  // led
  pinMode(G1, OUTPUT);	//Configuração dos pinos como saída
  pinMode(G2, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  
  Serial.begin (9600);
}

void loop() {
  if ( digitalRead(S) == LOW ) {
    digitalWrite(G1, LOW);
    digitalWrite(G2, LOW);
    digitalWrite(Y1, LOW);
    digitalWrite(Y2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
  } else {

    digitalWrite(trig, LOW);
    delay(0005);
    digitalWrite(trig, HIGH);
    delay(0010);
    digitalWrite(trig, LOW);
    
    distancia = pulseIn (echo, HIGH);
    distancia = distancia/58;
    Serial.println (distancia);
    
    int distancia2 = (int)distancia;

    if (distancia > 60) {
      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);

    } else if (distancia > 50) {
      digitalWrite(G1, HIGH);
      digitalWrite(G2, LOW);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);

    } else if (distancia > 40) {
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    } else if (distancia > 30) {
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    } else if (distancia > 20) {
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    } else if (distancia > 10) {
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, LOW);
    } else {
      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, HIGH);
    }
  }
}
