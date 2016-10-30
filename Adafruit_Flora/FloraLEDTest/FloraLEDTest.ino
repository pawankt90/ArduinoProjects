#include <NeoPatterns.h>

int FloraLEDPin = 6;
uint32_t delayTime = 10;

NeoPatterns neoStrip = NeoPatterns(8, FloraLEDPin, NEO_GRB + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
    neoStrip.begin();
    neoStrip.show();
}

void loop()
{ 

	
}
