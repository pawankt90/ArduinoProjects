#include <Arduino.h>

const int controlPin1 = 2, controlPin2 = 3;
const int enablePin = 9;
const int dirSwitchPin = 4;
const int onStateSwitchPin = 5;
const int potPin = A0;

int onSwitchState = 0;
int prevOnSwitchState = 0;
int dirSwitchState = 0;
int prevDirSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDir = 1;

void setup()
{
  Serial.begin(115200);

  pinMode(dirSwitchPin, INPUT);
  pinMode(onStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
}

void loop() {
  int onSwitchState = digitalRead(onStateSwitchPin);
  delay(1);
  dirSwitchState = digitalRead(dirSwitchPin);

  motorSpeed = 128;

  if (onSwitchState != prevOnSwitchState)
  {
    if (onSwitchState == HIGH)
    {
      motorEnabled = !motorEnabled;
    }
  }

  if (dirSwitchState != prevDirSwitchState)
  {
    if (dirSwitchState == HIGH)
    {
      motorDir = !motorDir;
    }
  }

  if (motorDir == 1)
  {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else
  {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1)
  {
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    analogWrite(enablePin, 0);
  }

  prevDirSwitchState = dirSwitchState;
  prevOnSwitchState = onSwitchState;
}
