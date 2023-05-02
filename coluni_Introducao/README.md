# Curso de Introdução ao Arduino UNO

* [Slides](https://docs.google.com/presentation/d/1yqwdCv-WAOVx7O0xj2GhLn6BmtSU8hcoTMcNri4V1pM/edit?usp=sharing)
* [Playlist Video](https://www.youtube.com/playlist?list=PLcvOyD_LMr6lAH0bfo5sqHm3ONmF3daMf)
## Exercício 1
 * Iremos executar o [Blink](https://wokwi.com/projects/357997295509663745)
 * ![](https://thestempedia.com/wp-content/uploads/2019/07/Blink-LED-once.gif)
    * **Tarefa 1**: Modifique o tempo que fica ligado (HIGH), depois o tempo desligado.
    * **Tarefa 2**: Qual o valor do *delay* para que você não perceba que está piscando ?
    * **Tarefa 3**: Faça um programa para piscar 2x rápido e 2x devagar. 
    * **Tarefa 4**: Testar o [Fading](https://github.com/arduinoufv/inf351/blob/master/coluni_Introducao/fading13.ino)
    
## Exercicio 2
  * [Usando 2 leds Externos e conhecendo o Protoboard](https://wokwi.com/projects/358178202736399361)
  * Tarefas
    * **Tarefa 1**: Modifique Led vermelho piscar 2x mais rapido que o Led verde
    * **Tarefa 2**: Fazer led verde piscar de 3 em 3 segundos, led vermelho de 2 em 2 segundos. Não usar delay, usar millis(): [exemplo com apenas 1 led](https://github.com/arduinoufv/inf351/blob/master/coluni_Introducao/conta3_atraso_de_1.ino), outro [exemplo com apenas 1 led](https://github.com/arduinoufv/inf351/blob/master/coluni_Introducao/3em3segundos_semDelay.ino)
    * **Tarefa 3**: Como fazer o led fazer "fading" (aumentar e diminuir o brilho ?
    
## Exercicio 3
   * Ligar o Buzzer e fazer alguns sons
   * [desenho](https://excalidraw.com/#json=LzW7ja0D9OrnKOmFjVUbQ,S1SOz-VeqlWC23H9sFXblg)
   
  ```
  #define NOTE_C4  262
#define NOTE_D4  294
#define SPEAKER_PIN 8
void setup() {
 pinMode(SPEAKER_PIN, OUTPUT);
}
void loop() {
 tone(SPEAKER_PIN,NOTE_C4);
 delay(200);
 noTone(SPEAKER_PIN);
 delay(200);
 tone(SPEAKER_PIN,NOTE_D4);
 delay(200);
 noTone(SPEAKER_PIN);
  delay(200);

  delay(200);
 }

  ``` 
   * Tarefas
      * **Tarefa 1**: Modifique as frequencias e tempo de duração
      * **Tarefa 2**: Como fazer beep começar lento e depois ficar rapido ?
      * **Tarefa 3**: Alguma música pronta na internet

## Exercicio 4
   * Potenciometro e leitura analógica
   * Tarefas
    * **Tarefa 1**: [Potenciometro com Buzzer](https://github.com/arduinoufv/inf351/blob/master/coluni_Introducao/Potenciometro_Buzzer_coluni.ino)
    * **Tarefa 2**: Fazer o potenciometro mudar a frequencia do Buzzer ?
    * **Tarefa 3**: [Potenciometro com Led e Buzzer](https://github.com/arduinoufv/inf351/blob/master/coluni_Introducao/Potenciometro_Buzzer_Led_coluni.ino)

   
# Terminal Serial

```
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( Serial.available()) {
    char letra = Serial.read();
    if ( letra == 'a' )
      digitalWrite(13, HIGH);
    else if ( letra == 'd')
      digitalWrite(13, LOW);
  }
}
```

   # Exemplo ler um número
   
   ```
   void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( Serial.available()) {
    int dataIn = Serial.parseInt();
    for (int i= 0; i < dataIn; i++) {
      digitalWrite(13, HIGH);
      delay(300);
      digitalWrite(13, LOW);
      delay(300);
    }
  }
}

   ```
    
   
  
  
