#include <Neopatterns.h>

int ProMicroLEDPin = 10;
NeoPatterns neostrip = NeoPatterns(10, 64, ProMicroLEDPin, NEO_RBG + NEO_KHZ800);

void setup() {
	// put your setup code here, to run once:
	neostrip.begin();
	neostrip.show();
	neostrip.ConfigureTheaterChaseRainbow(100);
}

void loop() {
	// put your main code here, to run repeatedly:	
	neostrip.PerformPattern();
}