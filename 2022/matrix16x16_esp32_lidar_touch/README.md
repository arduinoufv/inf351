# Demo com 16x6 leds, esp32, lidar e touch

[desenho](https://excalidraw.com/#json=TjPmHHEMg_r0rQWZKC3Ci,mKoVmhNtVJZcwLeFRBkWrw)


Abaixo o código para Esp32
* Usando os touch gp4 e gp15 que são touch0 e touch3, com valores que variam de 0 (tocado) a 70 aberto.
* O Lidar pode ficar fora de faixa senao tiver osbtáculo na frente, usa o protocolo SPI para conectar.
* A matrix de 16x16 está usando o pino 13 para conectar. 

montagem
* lidar controla o tom de vermelho quando tiver obstáculo, mais longe mais vermelho, mais perto sem vermelho. Fora de faixa sem vermelho.
* T0 controla o tom de verde, quando tocado reduz o verde
* T3 controla o tom de azul, quando tocado reduz o azul

```
// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    13

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 256

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);



void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
   Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println("Failed to boot VL53L0X");
    while(1);
  }
  // power 
  Serial.println("VL53L0X API Simple Ranging example\n\n"); 

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


void loop()
{
  VL53L0X_RangingMeasurementData_t measure;
  int lidar;
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
         lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
       if (measure.RangeStatus != 4) {  // phase failures have incorrect data
         lidar = measure.RangeMilliMeter;
         Serial.print(measure.RangeMilliMeter); Serial.print(" ");
         Serial.print(touchRead(T0)); Serial.print(" ");
         Serial.println(touchRead(T3));
       } else lidar = 0;
       strip.setPixelColor(i, strip.Color(map(lidar,0,1400,0,100),
                                          map(touchRead(T0),0,70,0,100),
                                          map(touchRead(T3),0,70,0,100)));         //  Set pixel's color (in RAM)
       strip.show();                          //  Update strip to match
       delay(20);                           //  Pause for a moment
  }
}

```
