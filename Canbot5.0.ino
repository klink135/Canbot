#include <Time.h>
#include <FastLED.h>
#define INIT_TIME   now()
#define LED_PIN     4
#define NUM_LEDS    76
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 10
#define MILLISECONDS 200
#define AMNT_COLORS  6
CRGB leds[NUM_LEDS];
double channel;
double ratio;
double r;
double b;
double g;
double offset = 75;
double brows = random(-255, 255);
double eyes = random(-255, 255);
double mouthe = random(-255, 255);

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  pinMode(2, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  channel = pulseIn(2, HIGH);
  Serial.println(channel);
  rgb(1100,2000,channel);
  unsigned int eyebrow1[6] = {0, 1, 2, 3, 4, 5};
  unsigned int eyebrow2[6] = {59, 60, 61, 62, 63, 64};
  unsigned int eye1[20] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
  unsigned int eye2[20] = {39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58};
  unsigned int mouth[13] = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
  for(unsigned int i = 0; i < 6; i++){
    leds[eyebrow1[i]] = CRGB(g + brows, r + brows, b + brows);
  }
  for(unsigned int i = 0; i < 6; i++){
    leds[eyebrow2[i]] = CRGB(g + brows, r + brows, b + brows);
  }
  for(unsigned int i = 0; i < 20; i++){
    leds[eye1[i]] = CRGB(g + eyes, r + eyes, b + eyes);
  }
  for(unsigned int i = 0; i < 20; i++){
    leds[eye2[i]] = CRGB(g + eyes, r + eyes, b + eyes);
  }
  for(unsigned int i = 0; i < 13; i++){
    leds[mouth[i]] = CRGB(g + mouthe, r + mouthe, b + mouthe);
  }
  
  FastLED.show();
  delay(MILLISECONDS);
}

void rgb(double minimum, double maximum, double value){

  minimum, maximum = float(minimum), float(maximum);
  ratio = 2 * (value-minimum) / (maximum - minimum);
  b = int(max(0, 255*(1 - ratio)));
  r = int(max(0, 255*(ratio - 1)));
  g = 255 - b - r;
}
