#include <Arduino.h>

const int motorPin = 8;
const int switchPin = 2;

int switchState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  Serial.print("SwitchState = ");
  Serial.println(switchState);

  if (switchState == HIGH)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }

}
