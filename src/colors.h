
long ledColor = CRGB::DarkOrchid; // Color used (in hex)
// long ledColor = CRGB::MediumVioletRed;
// Random colors i picked up
long ColorTable[21] = {
    CRGB::Amethyst,    // white
    CRGB::Aqua,        // pink
    CRGB::Blue,        // Blue
    CRGB::Chartreuse,  // Gold
    CRGB::DarkGreen,   // Red
    CRGB::DarkMagenta, // Aqua
    CRGB::DarkOrange,  // yellow green
    CRGB::DeepPink,    // Aqua
    CRGB::Fuchsia,     // Sea blue
    CRGB::Gold,        // Gold
    CRGB::GreenYellow, // off white
    CRGB::LightCoral,  // white
    CRGB::Tomato,      // white
    CRGB::Salmon,      // Pure white
    CRGB::Red,         // Drak Green
    CRGB::Orchid,      // blue white
    CRGB::Sienna,      // yellow white
    CRGB::Purple,      // aqua
    CRGB::DarkOrange,  // yellow green
    CRGB::FloralWhite, // white
    CRGB::Yellow       // yellow
};
void darkenLed(int pixelPos)
{
  leds[pixelPos].subtractFromRGB(50);
};
void darkenDigit(int digit, int pixelPos)
{
  for (int pixel = 0; pixel <= 12; pixel++)
  {
    if (symbolMap[digit][pixel] == 1) // if pixel is lit
    {
      // leds[pixelPos] = ledColor;
    }
    // else if (symbolMap[digit][pixel] == 0)
    else //
    {
      leds[pixelPos] = 0x000000;
    }
    pixelPos++;
  }
}

void rainbow_beat()
{

  // uint8_t beatA = beatsin8(17, 0, 0); // Starting hue
  // uint8_t beatB = beatsin8(13, 0, 255);
  // uint8_t beatC = beatsin8(0, 160, 255);
  // uint8_t beatD = beatsin8(0, 0, 155);
  // fill_rainbow(leds, NUM_LEDS, (beatA + beatB + beatC + beatD) / 4, 2); // Use FastLED's fill_rainbow routine.

  uint8_t beatA = beatsin8(17, 0, 0); // Starting hue
  uint8_t beatB = beatsin8(13, 0, 255);

  fill_rainbow(leds, NUM_LEDS, (beatA + beatB) / 4, 2); // Use FastLED's fill_rainbow routine.
}
void potToBrightness()
{
  int val = analogRead(analogPin);
  brightness = map(val, 0, 1023, 0, brightnessMax);
  LEDS.setBrightness(brightness); // Set initial brightness
}
// rainbow_beat()
/* coool effect function*/
// void fadeall()
// {
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i].nscale8(250);
//   }
// }
// void cylon()
// {
//   static uint8_t hue = 0;
//   Serial.print("x");
//   // First slide the led in one direction
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     // Set the i'th led to red
//     leds[i] = CHSV(hue++, 255, 255);
//     // Show the leds
//     FastLED.show();
//     // now that we've shown the leds, reset the i'th led to black
//     // leds[i] = CRGB::Black;
//     fadeall();
//     // Wait a little bit before we loop around and do it again
//     delay(10);
//   }
//   Serial.print("x");
// }