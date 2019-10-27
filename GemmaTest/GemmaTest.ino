#include <Adafruit_NeoPixel.h>
#include <Neopatterns.h>

int GemmaLEDPin = 1;
NeoPatterns neostrip = NeoPatterns(64, 6, GemmaLEDPin, NEO_GRB + NEO_KHZ800);

void setup() {
	// put your setup code here, to run once:
	neostrip.begin();
	neostrip.show();
	neostrip.ConfigureRainbowCycle(50);
}

void loop() {
	// put your main code here, to run repeatedly:	
	neostrip.PerformPattern();
}