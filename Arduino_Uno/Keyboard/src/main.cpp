#include <Arduino.h>

int notes[] = {262, 294, 330, 349};

const int resLadderInput = A0;
const int piezoPin = 8;

void setup()
{
  Serial.begin(115200);
  pinMode(piezoPin, OUTPUT);
}

void loop()
{
  int inputValue = analogRead(resLadderInput);

  Serial.print("Resistor Ladder: ");
  Serial.println(inputValue);

  if (inputValue > 900 && inputValue < 1100)
  {
    tone(piezoPin, notes[1]);
  }
  else if (inputValue > 400 && inputValue < 600)
  {
    tone(piezoPin, notes[2]);

  }
  else if (inputValue > 4 && inputValue < 10)
  {
    tone(piezoPin, notes[3]);
  }
  else
  {
    noTone(piezoPin);
  }
}
