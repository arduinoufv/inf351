# Trabalhos 

1. [snake]()
2. [fazer movimentos de olhos]()
3. [Acompanhar com o movimento de olhos, um motor e sensor Lidar]
4. 

# lcd draw characteres

[animations](https://create.arduino.cc/projecthub/tusindfryd/create-custom-animations-on-16x2-lcd-displays-025fb6)
[dog](https://create.arduino.cc/projecthub/milespeterson101/an-lcd-dog-friend-updated-b0bdee)

[Arduino LCD Game on TinkerCad Circuits](https://www.instructables.com/LCD-Screen-Game-on-TinkerCad-Circuits/)

# Shield com LCD e teclado
```
#include <LiquidCrystal.h> //INCLUSÃO DE BIBLIOTECA
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //PORTAS DO ARDUINO QUE SÃO UTILIZADAS PELO SHIELD KEYPAD DISPLAY LCD
  
void setup(){  
 lcd.begin(16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY. EM SUMA: UMA MATRIZ DE 16 COLUNAS E 2 LINHAS
 lcd.setCursor(0,0); //SETA A POSIÇÃO EM QUE O CURSOR INCIALIZA(LINHA 1) 
 lcd.print("APERTOU A TECLA"); //ESCREVE A FRASE "APERTOU A TECLA" NA PRIMEIRA LINHA DO DISPLAY LCD  
}  
  
void loop(){  
 lcd.setCursor(0,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)
 if ((analogRead(0)) < 80) { //SE A LEITURA DO PINO FOR MENOR QUE 80, FAZ 
  lcd.print ("    DIREITA    "); //ESCREVE NO LCD O TEXTO 
 }  
 else if ((analogRead(0)) < 200) { //SE A LEITURA DO PINO FOR MENOR QUE 200, FAZ
  lcd.print ("      CIMA     ");  //ESCREVE NO LCD O TEXTO
 }  
 else if ((analogRead(0)) < 400){ //SE A LEITURA DO PINO FOR MENOR QUE 400, FAZ  
  lcd.print ("     BAIXO     "); //ESCREVE NO LCD O TEXTO 
 }  
 else if ((analogRead(0)) < 600){ //SE A LEITURA DO PINO FOR MENOR QUE 600, FAZ  
  lcd.print ("    ESQUERDA   "); //ESCREVE NO LCD O TEXTO 
 }  
 else if ((analogRead(0)) < 800){ //SE A LEITURA DO PINO FOR MENOR QUE 800, FAZ 
  lcd.print ("     SELECT    "); //ESCREVE NO LCD O TEXTO 
 }  
}
```

