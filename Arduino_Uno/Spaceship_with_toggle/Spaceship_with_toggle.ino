void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

int previous = LOW;
int state = LOW;
int reading = LOW;
int toggle = LOW;

long debounce = 200;
long tick = 0;

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(2);

  if ((reading == HIGH) && (previous == LOW))
  {
    if ((millis() - tick) > debounce)
    {     
      if (state == LOW)
      {
        state = HIGH;
      }
      else
      {
        state = LOW;
      }
    }
    else
    {
      Serial.println("!!Warning!! Millis failed");
      tick = millis();
    }
    
    tick = millis();
  }
 
  
  if (state == LOW)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else
  {
    digitalWrite(3, LOW);
    
    if (toggle == LOW)
    {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
    else
    {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
    
    toggle = !toggle;
  }
  
  
  delay(200);
    
}
