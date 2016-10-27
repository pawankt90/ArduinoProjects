#include <NeoPatterns.h>

int FloraLEDPin = 8;
uint32_t delayTime = 500;

NeoPatterns neoStrip = NeoPatterns(1, FloraLEDPin, NEO_GRB + NEO_KHZ800);

void setup()
{
    neoStrip.begin();
    neoStrip.show();

}

void loop()
{
    neoStrip.ConfigureColorWipe(GetKnownColorValue(RED), delayTime);
    neoStrip.PerformPattern();
    neoStrip.ConfigureColorWipe(GetKnownColorValue(GREEN), delayTime);
    neoStrip.PerformPattern();
    neoStrip.ConfigureColorWipe(GetKnownColorValue(BLUE), delayTime);
    neoStrip.PerformPattern();

}
