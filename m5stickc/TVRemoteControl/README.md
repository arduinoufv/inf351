Use #include <IRremote.h> library

IRrecv irrecv(recvPin);// read the TV remote control

IRsend irsend;// create a new library to use IR m5stickC

  irrecv.enableIRIn();

if (irrecv.decode(&results)) {  // Grab an IR code
    dumpCode(&results);           // Output the results as source code
    delay(50);
    irrecv.resume();              // Prepare for the next value

  }
  
   [Example to be adapted](https://github.com/rabee2050/arduino-ir/blob/master/ir_sketch_v1.0/ir_sketch_v1.0.ino)
