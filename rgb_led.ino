#define RED_PIN 9
#define BLUE_PIN 11
#define GREEN_PIN 10
#define POWER_PIN 4
//common anode RGB LED
void setup() 
{
pinMode(RED_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(POWER_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(POWER_PIN, HIGH);
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0); 
}
