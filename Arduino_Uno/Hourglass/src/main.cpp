#include <Arduino.h>

const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;

unsigned long interval = 10000;

void setup()
{
  Serial.begin(115200);

  for (int i = 2; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(switchPin, INPUT);

  pinMode(13, OUTPUT);

  digitalWrite(13, LOW);
}

void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval)
  {
    if (led >= 8)
    {
      digitalWrite(13, HIGH);
    }
    else
    {
      previousTime = currentTime;
      digitalWrite(led++, HIGH);
    }
  }

  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState)
  {
    for (int i = 2; i < 8; i++)
    {
      digitalWrite(i, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
