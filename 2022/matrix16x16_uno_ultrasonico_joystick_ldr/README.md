
* [video](https://youtu.be/xVMvTJAAfWg)

* ultrasonico no pinos 12 e 13
* LDR no A2
* Matrix de LED no 10

[desenho da montagem](https://excalidraw.com/#json=OCN_HcPjqUDWFijSfhjPi,ZiDBZ7BAAxvs7pitaK6LGQ)

A demo movimenta com joystick com a cor verde (se o botão UP pino 2 estiver apertado), para movimentar
tem que ir e volta na direcao. 

O ultrasonico pode trocar o tom de verde.

```
#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define LED_PIN (9)

#define ROWS (16)
#define COLS (16)

#define MS_PER_TICK (300)


Adafruit_NeoPixel pixels =
    Adafruit_NeoPixel(ROWS * COLS, LED_PIN, NEO_GRB + NEO_KHZ800);

int last_axis_x;


// LED helper {{{

bool change; 
int px,py,rx,gx,bx;

/// Lights up a pixel.
void set_pixel(int x, int y, int r, int g, int b) {
  // Odd rows are counted backwartds.
  if (y % 2 == 1)
    x = (COLS - 1) - x;
  pixels.setPixelColor(COLS * y + x, pixels.Color(r, g, b));
}
// }}}




void setup() {
  Serial.begin(115200);
  
  int axis = analogRead(A0);
  last_axis_x = axis;

  pixels.begin();
  pixels.setBrightness(50);
  pixels.show(); // Initialize all pixels to 'off'
}
bool esq = false;
bool dir = false;
bool sobe = false;
bool desce = false;

int posx = 0;
int posy = 0;

int g = 50;

void loop() {
 
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.print(inMsec);
// LDR
  Serial.print(", LDR: ");
  Serial.println(analogRead(A2));
  

  g = map(microsec,0,15000,0,255);
  
  int axis_X = analogRead(A0);
  int axis_Y = analogRead(A1);

  if ( axis_X < 300 && !esq) {
    esq = true;
    posx--; 
    if ( posx < 0) posx = 0; 
  } else if ( axis_X > 600 && !dir  ) {
    dir = true;
    posx++; 
    if ( posx > 15) posx = 15;
  } else if ( axis_X > 300 & axis_X < 600) {
    esq = false;
    dir = false;
  }
  if ( axis_Y < 300 && !sobe) {
    sobe = true;
    posy--; 
    if ( posy < 0) posy = 0; 
  } else if ( axis_Y > 600 && !desce  ) {
    desce = true;
    posy++; 
    if ( posy > 15) posy = 15;
  } else if ( axis_Y > 300 & axis_Y < 600) {
    sobe = false;
    desce = false;
  }


  if ( digitalRead(2)== LOW ) {    
     set_pixel(posx, posy, 0, g, 0);
  }
    
  else
     set_pixel(posx, posy, 0, 0, 0);

  pixels.show(); 

  delay(300);
}

```
