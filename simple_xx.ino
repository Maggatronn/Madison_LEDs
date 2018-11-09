// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      57

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGBW + NEO_KHZ800);

int delayval = 500; // delay for half a second
const int startPin = 12;
const int recordPin = 13;
const int ledPin = 6;
int startVal = 0;
int recordVal = 0;


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  pinMode(ledPin, OUTPUT);
  pinMode(startPin, INPUT);
  pinMode(recordPin, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

//  for(int i=1;i<NUMPIXELS;i++){

  startVal = digitalRead(startPin);
  recordVal = digitalRead(recordPin);
 
  if (startVal == HIGH) { 
     if (recordVal == HIGH) { // the Pi is recording
      for (int i = 0; i<10;i++) {
       colorWipe(pixels.Color(80, 255, 0), 0); // Red
      }
     }
     else {
      for (int i = 0; i<10;i++) {
       colorWipe(pixels.Color(0, 0, 255), 0); // Red       
     }
     }
      }
  else {
    for (int i = 0; i<10;i++) {
       colorWipe(pixels.Color(0, 0, 255), 0); // Red
       delay(400);
       colorWipe(pixels.Color(0, 0, 0), 0); // Red
       delay(100);
    }
   
    
    //pixels.setPixelColor(0,255,0,0);
    //pixels.show();
//    delay(500);
//      pixels.setPixelColor(i, pixels.Color(0,0,0,0));
//      pixels.show();
//      delay(700);
//    }
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
   
    //pixels.show(); // This sends the updated pixel color to the hardware.

//    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(0); 
  }
}

//
//void colorWipe(uint32_t c, uint8_t wait) {
////void colorWipe(uint32_t c, uint8_t) {
//  for(uint16_t i=0; i<pixels.numPixels(); i++) {
//    pixels.setPixelColor(i, c);
//    pixels.show();
//    delay(wait);
//  }
//}
//uint32_t Wheel(byte WheelPos) {
//  WheelPos = 255 - WheelPos;
//  if(WheelPos < 85) {
//    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  }
//  if(WheelPos < 170) {
//    WheelPos -= 85;
//    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//  WheelPos -= 170;
//  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//}
