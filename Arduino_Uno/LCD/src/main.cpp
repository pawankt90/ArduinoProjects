#include <LiquidCrystal.h>
#include <Arduino.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int switchPin = 6; // Pin from the tilt switch
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2); // 2 rows 16 chars each
  pinMode(switchPin, INPUT);

  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal ball!");
}

void loop() {
  switchState = digitalRead(switchPin);

  Serial.print("SwitchState =");
  Serial.println(switchState);

  if (switchState != prevSwitchState)
  {
    if (switchState == LOW)
    {
      reply = random(8);

      Serial.print("Reply=");
      Serial.println(reply);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);

      switch (reply)
      {
        case 0:
          lcd.print("Yes");
          break;
        case 1:
          lcd.print("Most likely");
          break;
        case 2:
          lcd.print("Certainly");
          break;
        case 3:
          lcd.print("Outlook good");
          break;
        case 4:
          lcd.print("Unsure");
          break;
        case 5:
          lcd.print("Ask again");
          break;
        case 6:
          lcd.print("Doubtful");
          break;
        case 7:
          lcd.print("No");
          break;
        default:
          break;
      }
    }
  }

  prevSwitchState = switchState;
}
