/*
Arduino 2x16 LCD - Detect Buttons
modified on 18 Feb 2019
by Saeed Hosseini @ Electropeak
https://electropeak.com/learn/
*/

#include <LiquidCrystal.h>

//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 

const int pin_BL = 10; 

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);


uint8_t heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
};


void setup() {
   lcd.createChar(3, heart);
  
  lcd.begin(16, 2);

  lcd.setCursor(0,0);

  lcd.print("UFV");
  lcd.setCursor(0,1);
  lcd.print("Press Key:");
}



void loop() {
  int x;
  x = analogRead (0);
  lcd.setCursor(10,1);
  if (x < 60) {
    lcd.print ("Right ");
        lcd.setCursor(5,0);
    lcd.print(" ");

  }
  else if (x < 200) {
    lcd.print ("Up    ");
        lcd.setCursor(5,0);
    lcd.print(" ");

  }
  else if (x < 400){
    lcd.print ("Down  ");
    lcd.setCursor(5,0);
    lcd.print(" ");

  }
  else if (x < 600){
    lcd.print ("Left  ");
    lcd.setCursor(5,0);
    lcd.print(" ");
  }
  else if (x < 800){
     lcd.print ("Select");
     lcd.setCursor(5,0);
     lcd.print("\x03");
 
  }
}
