#include <Arduino.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <FastLED.h>
#define NUM_LEDS 86
#define COLOR_ORDER RGB // Define color order for your strip
#define LED_PIN 5       // Data pin for led comunication
#define DST_PIN 4       // Define DST adjust button pin
#define MIN_PIN 3       // Define Minutes adjust button pin
#define HUR_PIN 2       // Define Hours adjust button pin
CRGB leds[NUM_LEDS];
int analogPin = A6;
int cursorPos[6] = {73, 60, 43, 30, 13, 0};
int timeAsArray[6] = {0, 0, 0, 0, 0, 0};
int last_digit = 0;
int cursor = 0;
int rndLocal1 = 26;
int rndLocal2 = 26;
int hours = 0;
int minutes = 0;
int seconds = 0;
long timeAsNumber = 0;
byte brightness = 25;
byte brightnessMax = 255;
byte symbolMap[12][13] = {
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},  // 0
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},  // 1
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},  // 2
    {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},  // 3
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},  // 4
    {1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1},  // 6
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1},  // 7
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},  // 8
    {1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},  // 9
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},  //
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}}; //
bool dot = true;                              // dot state
bool DST = true;                              // DST state // false to true
bool tempShow = false;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial
  delay(200);
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(brightness); // Set initial brightness
  pinMode(DST_PIN, INPUT_PULLUP); // Define DST adjust button pin
  pinMode(MIN_PIN, INPUT_PULLUP); // Define Minutes adjust button pin
  pinMode(HUR_PIN, INPUT_PULLUP); // Define Hours adjust button pin
}

#include "colors.h"
#include "calcTime.h"
#include "temp.h"
#include "dst.h"
#include "dot.h"

void updateClockDisplay()
{
  dot ? dotOn() : dotOff();

  for (int currClockDigit = 0; currClockDigit <= 5; currClockDigit++)
  {
    int currDigit = timeAsNumber % 10; // get last digit in time
    int currCursorPos = cursorPos[currClockDigit];
    timeAsNumber /= 10;

    darkenDigit(timeAsArray[currClockDigit], currCursorPos);
    // darkenDigit(currDigit, currCursorPos);
    // if (i == 0 && currDigit != last_digit)
    // {
    //   // ledColor = ColorTable[random(21)];
    // }
    // last_digit = currDigit;
  };
};

void loop()
{
  potToBrightness();
  rainbow_beat();
  getTime();
  // BrightnessCheck(); // Check brightness
  // DSTcheck();    // Check DST
  // TimeAdjust();  // Check to se if time is geting modified
  updateClockDisplay(); // Get leds array with required configuration
  // TempToArray();
  FastLED.show(); // Display leds array
  // if (tempShow == true)
  //   delay(8000);
}
