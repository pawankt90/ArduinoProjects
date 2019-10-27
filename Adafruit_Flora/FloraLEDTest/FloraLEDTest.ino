#include <NeoPatterns.h>

int FloraLEDPin = 8;
uint32_t delayTime = 300;

NeoPatterns neoStrip = NeoPatterns(128, 8, FloraLEDPin, NEO_GRB + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
    neoStrip.begin();
    neoStrip.show();
}

void loop()
{ 
	neoStrip.ConfigureColorWipe(GetKnownColorValue(GREEN), delayTime, FORWARD);
	neoStrip.PerformPattern();
	delay(500);
	neoStrip.ConfigureColorWipe(0, delayTime, REVERSE);
	neoStrip.PerformPattern();
	delay(500);
	neoStrip.ConfigureColorWipe(GetKnownColorValue(BLUE), delayTime, FORWARD);
	neoStrip.PerformPattern();
	delay(500);
	neoStrip.ConfigureColorWipe(0, delayTime, REVERSE);
	neoStrip.PerformPattern();
	delay(500);
}
