#include <Servo.h>
#include <Arduino.h>
Servo myServo;

const int piezoPin = A0;
const int switchPin = 2;
const int yellowLED = 3;
const int greenLED = 5;
const int redLED = 4;

int knockVal = 0, switchVal = 0;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numKnocks = 0;

void setup() {
  Serial.begin(115200);
  myServo.attach(9);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(greenLED, HIGH);
  myServo.write(0);
}

boolean checkForKnock(int value)
{
  if (value > quietKnock && value < loudKnock)
  {
    digitalWrite(yellowLED, HIGH);
    delay(50);
    digitalWrite(yellowLED, LOW);
    Serial.print("Valid knock value! Value =");
    Serial.println(value);

    return true;
  }
  else
  {
    Serial.print("Invalid knock value. Value = ");
    Serial.println(value);

    return false;
  }

  return false;
}


void loop() {
  if (!locked)
  {
    switchVal = digitalRead(switchPin);

    if (switchVal == HIGH)
    {
      locked = true;
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }

  if (locked)
  {
    knockVal = analogRead(piezoPin);

    if (numKnocks < 3 && knockVal > 0)
    {
      if (checkForKnock(knockVal) == true)
      {
        numKnocks++;
      }

      Serial.print(3-numKnocks);
      Serial.println(" knocks to go");
    }

    if (numKnocks >= 3)
    {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      Serial.println("The box is unlocked!");
      numKnocks = 0;
    }
  }
}
