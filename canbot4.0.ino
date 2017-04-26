#include <Time.h>
#include <TimeLib.h>
#include <FastLED.h>
#define DATA_PIN 3
#define INIT_TIME   now()
#define LED_PIN     2
#define NUM_LEDS    76
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 10
#define MILLISECONDS 200
#define AMNT_COLORS  6
CRGB leds[NUM_LEDS];
int sensorPin0 = A0;
int sensorPin1 = A1;

void setup() { 
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}
// AUTON 2
// ANGRY 0
// NORMAL 4

void loop(){
  CRGB rand_vals[6] = {CRGB::Yellow, CRGB::Red, CRGB::Blue, CRGB::Green, CRGB::Magenta, CRGB::Purple};
  while(true){
    unsigned int analog_val = analogRead(sensorPin1);
    if(analog_val > 3){
      for(unsigned int x = 0; x < NUM_LEDS; x++){
        leds[x] = rand_vals[random(0, 6)];
      }
      FastLED.show();
      delay(MILLISECONDS);
    }else{
      for(unsigned int x = 0; x < NUM_LEDS; x++){
        leds[x] = CRGB::Red;
      }
      FastLED.show();
      delay(MILLISECONDS);
    }
  }
}

