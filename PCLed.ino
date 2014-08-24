#include "FastLED.h"

#define NUM_LEDS 41

#define DATA_PIN 11
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
}

void Pulse(CRGB colour)
{

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colour;
    leds[i].maximizeBrightness();
  }
  FastLED.show();

  for(int i = 0; i < 14; i++) {
    for(int k = 0; k < NUM_LEDS; k++) {
      leds[k].fadeLightBy( 64 );
    }
    FastLED.show();
    delay(50);
  }

  for(int i = 0; i < 14; i++) {
    for(int k = 0; k < NUM_LEDS; k++) {
      leds[k] *= 2;
    }
    FastLED.show();
    delay(100);
  }
}

void UpDown(CRGB colour) { 

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colour;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(30);
  }

  for(int i = NUM_LEDS-1; i >= 0; i--) { 
    leds[i] = colour;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(30);
  }
}
void loop() { 

  UpDown(CRGB::Red);
  UpDown(CRGB::Red);
  for(int i = 0; i < 5; i++){
    Pulse(CRGB::Red);
  }
  UpDown(CRGB::Purple);
  UpDown(CRGB::Purple);
  for(int i = 0; i < 5; i++){
    Pulse(CRGB::Purple);
  }
  UpDown(CRGB::Blue);
  UpDown(CRGB::Blue);
  for(int i = 0; i < 5; i++){
    Pulse(CRGB::Blue);
  }
}
