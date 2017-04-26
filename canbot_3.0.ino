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
/*
void loop(){
  unsigned int blue_dot = 0;
  unsigned int shift = 0;
  while(true){
    for(unsigned int i = 0; i < NUM_LEDS; i++ ){
      leds[i] = CRGB::Green;
    }
    shift++;
    shift %= 3;
    for(unsigned int i = shift; i < NUM_LEDS; i += 3){
      leds[i] = CRGB::Red;
    }
    blue_dot++;
    if(blue_dot >= NUM_LEDS){
      blue_dot = 0;
    }
    leds[blue_dot] = CRGB::Blue;
    
    FastLED.show();
    delay(MILLISECONDS);
  }
}
*/
// ASSIGN S1 TO HAPPY
int S1 [NUM_LEDS];
// ASSIGN S2 TO ANGRY
int S2 [NUM_LEDS];
// ASSIGN S3 TO PUKER
CRGB S3 [NUM_LEDS];
CRGB to_from [2] = {S1, S3};
float R_DIST [NUM_LEDS];
float G_DIST [NUM_LEDS];
float B_DIST [NUM_LEDS];
float R_PREVIOUS [NUM_LEDS];
float G_PREVIOUS [NUM_LEDS];
float B_PREVIOUS [NUM_LEDS];
float R_INCREMENT [NUM_LEDS];
float G_INCREMENT [NUM_LEDS];
float B_INCREMENT [NUM_LEDS];
// GETS DISTANCE FROM R1 AND R2
for(unsigned int i = 0; i < NUM_LEDS; i++){
  R_DIST[i] = abs(to_from[0].r - to_from[1].r);
  G_DIST[i] = abs(to_from[0].g - to_from[1].g);
  B_DIST[i] = abs(to_from[0].b - to_from[1].b);
}
int INCREMENT = 1000;
for(unsigned int i = 0; i < NUM_LEDS; i++){
  R_INCREMENT[i] = R_DIST[i] / INCREMENT;
  G_INCREMENT[i] = G_DIST[i] / INCREMENT;
  B_INCREMENT[i] = B_DIST[i] / INCREMENT;
}

for(unsigned int i = 0; i < incrment; i++){
  R_PREVIOUS[i] -= R_INCREMENT[i];
  G_PREVIOUS[i] -= G_INCREMENT[i];
  B_PREVIOUS[i] -= B_INCREMENT[i];
}

/*
void loop(){
  unsigned int eyebrow1[6] = {0, 1, 2, 3, 4, 5};
  unsigned int eyebrow2[6] = {59, 60, 61, 62, 63, 64};
  unsigned int eye1[20] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
  unsigned int eye2[20] = {39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58};
  unsigned int mouth[13] = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
  while(true){
    
    unsigned int analog_val = analogRead(sensorPin1);
    if(analog_val < 1){
      for(unsigned int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Red;
      }
    }else if(analog_val <= 500){
      for(unsigned int i = 0; i < 6; i++){
        leds[eyebrow1[i]] = CRGB(0, 75, 0);
      }
      for(unsigned int i = 0; i < 6; i++){
        leds[eyebrow2[i]] = CRGB(0, 75, 0);
      }
      for(unsigned int i = 0; i < 20; i++){
        leds[eye1[i]] = CRGB::Green;
      }
      for(unsigned int i = 0; i < 20; i++){
        leds[eye2[i]] = CRGB(0, 150, 0);
      }
      for(unsigned int i = 0; i < 13; i++){
        leds[mouth[i]] = CRGB(0, 75, 0);
      }
    }else{
      for(unsigned int i = 0; i < 6; i++){
        leds[eyebrow1[i]] = CRGB::Yellow;
      }
      for(unsigned int i = 0; i < 6; i++){
        leds[eyebrow2[i]] = CRGB::Yellow;
      }
      for(unsigned int i = 0; i < 20; i++){
        leds[eye1[i]] = CRGB::Blue;
      }
      for(unsigned int i = 0; i < 20; i++){
        leds[eye2[i]] = CRGB::Blue;
      }
      for(unsigned int i = 0; i < 13; i++){
        leds[mouth[i]] = CRGB::White;
      }
    }
    FastLED.show();
    delay(MILLISECONDS);
  }
}
*/
/*
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
*/
/*
void loop(){
  CRGB rand_vals[3] = {CRGB::Red, CRGB::Blue, CRGB::Yellow};
  while(true){
    unsigned int analog_val = analogRead(sensorPin1);
    if(analog_val > 3){
      for(unsigned int x = 0; x < NUM_LEDS; x++){
        leds[x] = rand_vals[random(0, 3)];
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
*/

/*
void loop(){
  unsigned int num = 0;
  while(true){
    for(unsigned int x = 0; x < NUM_LEDS; x++){
      leds[x] = CRGB::Blue;
    }
    if(num >= NUM_LEDS){
      num = 0;
    }
    leds[num] = CRGB::Red;
    num += 1;
    FastLED.show();
    delay(MILLISECONDS);
  }
}*/

