#define trigPin 13
#define echoPin 7
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(8, OUTPUT);
}
void loop() 
{
  long duration,distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  if (distance>=200||distance<=0)
  {
    Serial.println("out of range");
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
  }
  if (distance<=50)
  {
    tone(8, 1000);
  }
  else
  {
    noTone(8);
  }
  delay(500);
}
