#include "Arduino.h"
int LED = 7;

void setup()
{
	Serial.begin(115200);
	pinMode(LED, OUTPUT);
  /* add setup code here */

}

void loop()
{
	Serial.println("Hello!");
	digitalWrite(LED, HIGH);
	delay(100);
	Serial.println("Goodbye!");
	digitalWrite(LED, LOW);
	delay(100);
	
  /* add main program code here */

}
