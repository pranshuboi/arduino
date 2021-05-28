#include <LiquidCrystal.h>
#define trigPin 13
#define echoPin 7
#define redPin 6
#define greenPin 9
#define bluePin 10
#define buzzer 8
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() 
{
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
void loop() 
{
  String outputs[9]={
    "Currently Safe  ",
    "No Nearby Object",
    "Object Sensed   ",
    "Coming Closer   ",
    "Still Coming    ",
    "Dont Come Closer",
    "Alarm Will Ring ",
    "One Last Warning",
    "DANGER!!!       "};
  long duration,distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  if (distance>=200 || distance<=0)
  {
    lcd.clear();
    lcd.print(outputs[0]);
    lcd.setCursor(0,1);
    lcd.print(outputs[1]);
    noTone(buzzer);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  else if (distance>=170 && distance<200)
  {
    lcd.clear();
    lcd.print(outputs[2]);
    lcd.setCursor(0,1);
    lcd.print("Distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    noTone(buzzer); 
  }
  else if (distance>=140 && distance<170)
  {
    lcd.clear();
    lcd.print(outputs[3]);
    lcd.setCursor(0,1);
    lcd.print("Distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    noTone(buzzer); 
  }
  else if (distance>=120 && distance<140)
  {
    lcd.clear();
    lcd.print(outputs[4]);
    lcd.setCursor(0,1);
    lcd.print("distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    noTone(buzzer); 
  }
   else if (distance>=80 && distance<120)
  {
    lcd.clear();
    lcd.print(outputs[5]);
    lcd.setCursor(0,1);
    lcd.print("distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    noTone(buzzer); 
  }
   else if (distance>=50 && distance<80)
  {
    lcd.clear();
    lcd.print(outputs[6]);
    lcd.setCursor(0,1);
    lcd.print("distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    noTone(buzzer); 
  }
   else if (distance>=20 && distance<50)
  {
    lcd.clear();
    lcd.print(outputs[7]);
    lcd.setCursor(0,1);
    lcd.print("distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 0);
    analogWrite(greenPin, 170);
    analogWrite(bluePin, 255);
    noTone(buzzer); 
  }
   else
  {
    lcd.clear();
    lcd.print(outputs[8]);
    lcd.setCursor(0,1);
    lcd.print("distance = ");
    lcd.print(distance);
    lcd.print("cms");
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    tone(buzzer, 1000); 
  }
  delay(500);
}
