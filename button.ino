int buttonState = 0;
void setup() {  // initialize digital pin 13 as an output.
   pinMode(2, INPUT);
   Serial.begin(9600);
}

// the loop function runs over and over again forever

void loop() {
   buttonState = digitalRead(2);
   if (buttonState == HIGH)
   {
    Serial.println("HIGH");
   }
   else
   {
    Serial.println("LOW");
   }
}
