#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup()
{
Serial.begin(115200);

// wait until serial port opens for native USB devices
while (! Serial)
{
delay(1);
}

Serial.println("Adafruit VL53L0X test");
if (!lox.begin())
{
Serial.println(F("Failed to boot VL53L0X"));
while(1);
}
// power
Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}

void loop()
{
VL53L0X_RangingMeasurementData_t measure;

Serial.print("Reading a measurement... ");

int dist[30];

int d = lox.rangingTest(&measure, false);
while ( measure.RangeStatus == 4 || d == 8191) {
  d = lox.rangingTest(&measure, false);
}
for (int i=0; i< 30; i++){ 
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4)
    { // phase failures have incorrect data
    //  Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    dist [i] = measure.RangeMilliMeter;
    }
    else
    {
      dist [i] = -1;
    //Serial.println(" out of range ");
    }
    delay(30);
 }
 for (int i=0; i<30; i++) {
   Serial.print(dist[i]);
   if ( i % 10 == 0 ) Serial.println();
   else Serial.print(" ");
 }   
 delay(3000);
 Serial.println("Ready to read");
}

