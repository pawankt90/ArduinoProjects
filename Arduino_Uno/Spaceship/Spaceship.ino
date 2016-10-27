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

long debounce = 500;
long tick = 0;

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(2);
  Serial.print("Reading GPIO 2: ");
  Serial.println(reading, DEC);
  Serial.print("Previous: ");
  Serial.println(previous, DEC);
  Serial.print("Tick: ");
  Serial.println(tick, DEC);
  
  if ((reading == HIGH) && (previous == LOW))
  {
    if ((millis() - tick) > 200)
    {
      Serial.print("Able to toggle\n");
      Serial.print("State was :");
      Serial.println(state,DEC);
      
      if (state == LOW)
      {
        state = HIGH;
      }
      else
      {
        state = LOW;
      }
      
      Serial.print("State now is :");
      Serial.println(state,DEC);
    }
    else
    {
      Serial.println("!!Warning!! Millis failed");
      tick = millis();
      delay(1000);
    }
  }
  
      
  Serial.print("State check: ");
  Serial.println(state, DEC);
  
  if (state == LOW)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else
  {
    Serial.println("Toggling with state HIGH");
    digitalWrite(3, LOW);
    
    if (toggle == LOW)
    {
      Serial.println("Toggle is LOW");
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
    else
    {
      Serial.println("Toggle is high");
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
    
    toggle = !toggle;
  }
  
  tick = millis();
  
  delay(200);
    
}
