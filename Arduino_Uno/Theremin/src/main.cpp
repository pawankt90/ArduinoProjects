#include <Arduino.h>

int sensorValue = 0, sensorLow = 1023, sensorHigh = 0;

const int LEDPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, HIGH);

  // Calibrate the light sensor

  while (millis() < 5000)
  {
    sensorValue = analogRead(A0);

    sensorHigh = sensorValue > sensorHigh? sensorValue : sensorHigh;
    sensorLow = sensorValue < sensorLow? sensorValue : sensorLow;
  }

  digitalWrite(LEDPin, LOW);
}

void loop()
{
  sensorValue = analogRead(A0);

  Serial.print("Sensor Reading : ");
  Serial.println(sensorValue);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
