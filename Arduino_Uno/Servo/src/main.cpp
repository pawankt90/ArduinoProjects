#include <Servo.h>
#include <Arduino.h>

Servo myServo;
int const potPin = A1;
int potVal = 0;
int angle = 0;

void setup()
{
  myServo.attach(9);
  Serial.begin(115200);
}

void loop()
{
  potVal = analogRead(potPin);
  Serial.print("potVal=");
  Serial.println(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print ("Angle=");
  Serial.println(angle);
  Serial.println();

  myServo.write(angle);
  delay(15);
}
