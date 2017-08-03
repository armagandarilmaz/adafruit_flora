// NeoPixel Demo minimum 
// By the sons of the gun
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6 

// How many NeoPixels are attached to the adafruit flora? In here I have one
#define NUMPIXELS      1

int switchPin = 9;     // switch connected to digital pin 7
int switchValue;     // a variable to keep track of when switch is pressed

int j=0;    //this is just for random int

int myFavoriteColors[][3] = {{255,   0, 0},   // red
                                 {0,   0,   255},   // blue 
                                 {0, 255, 0},   //green
                                 {200,   0, 200},   // purple
                                 {200, 200, 200}, // white
                               };

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 1000; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special cod
  
          pinMode(switchPin, INPUT);     // sets the switchPin to be an input
         digitalWrite(switchPin, HIGH);     // sets the default (unpressed) state of switchPin to HIGH

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.


    switchValue = digitalRead(switchPin);     // check to see if the switch is pressed
          if (switchValue == HIGH) {     // if the switch is pressed then,

          }      
          else {     // otherwise,

              int j = random(0,5); delay(500);

              Serial.print(j);
              Serial.print(myFavoriteColors[j][0]);
              
              pixels.setPixelColor(0, pixels.Color(myFavoriteColors[j][0],myFavoriteColors[j][1],myFavoriteColors[j][2]));
              pixels.show(); // This sends the updated pixel color to the hardware
          }  
  
  
  
}
