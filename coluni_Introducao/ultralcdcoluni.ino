#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>
// scl a5 sda a4
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 3 
#define echoPin 2
Ultrasonic ultrasonic(trigPin, echoPin);


void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Coluni UFV");
  delay(2000);
  lcd.setCursor(0,0);  
  lcd.print("Distancia:"); }

void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
 
  lcd.setCursor(0,1);  //Set cursor to first column of second row
  lcd.print("                "); //Print blanks to clear the row
  lcd.setCursor(0,1);   //Set Cursor again to first column of second row
  lcd.print(cmMsec); //Print measured distance
  lcd.print(" cm");  //Print your units.
  delay(250); //pause to let things settle
}
