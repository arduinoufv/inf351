#include <Adafruit_NeoPixel.h>
#define PIN 15  // esp32 
#define NUM_LEDS 256
#define LINE 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

#include <Ultrasonic.h>

#define TRIGGER_PIN  5
#define ECHO_PIN     18

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void table(int i, int j, byte red, byte green, byte blue)
{
  int x = i * LINE;
  x  = (i%2)? x+(LINE-1)-j:x+j;
  setPixel(x, red, green, blue);   
}



void setup()
  {
  Serial.begin(115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  setAll(10,0,0);
  delay(1000);
  setAll(0,0,0);
    
  }

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}

int Mapping(float cm) {
  int l;
  l = (int) cm;
  l = l * 15 /170;
  return l;
}

void loop()
  {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.println(inMsec);
  int l = Mapping(cmMsec);
  setAll(0,0,0);
  for (int i=0; i < l*LINE; i++) 
    setPixel(i,50,0,0);
  showStrip();     
  delay(250);
  }
