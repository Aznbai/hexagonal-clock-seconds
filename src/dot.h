void dotOn()
{
    // leds[26] = ledColor;
    // leds[27] = ledColor;
    // leds[28] = ledColor;
    // leds[29] = ledColor;
    //    for (int i = 26; i < 30; i++)
    // {
    //   leds[i].nscale8(250);
    // }
    // leds[rndLocal1] = 0x000000;
}

void dotOff()
{
    // first dot
    // leds[rndLocal2] = 0x000000;
    leds[26] = 0x000000;
    leds[27] = 0x000000;
    leds[28] = 0x000000;
    leds[29] = 0x000000;
    // second dot
    leds[56] = 0x000000;
    leds[57] = 0x000000;
    leds[58] = 0x000000;
    leds[59] = 0x000000;
}