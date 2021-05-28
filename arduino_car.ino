int rreverse = 3;
int rforward = 4;
int lreverse = 5;
int lforward = 2;
int btpower = 7;
char t;

bool direction = HIGH;
void setup() 
{
  pinMode(lforward, OUTPUT);
  pinMode(lreverse, OUTPUT);
  pinMode(rforward, OUTPUT);
  pinMode(rreverse, OUTPUT);
  pinMode(btpower, OUTPUT);
}
void forward()
{
  digitalWrite(lforward, HIGH);
  digitalWrite(rforward, HIGH);
  digitalWrite(lreverse, LOW);
  digitalWrite(rreverse, LOW);
}
void reverse()
{
  digitalWrite(lreverse, HIGH);
  digitalWrite(rreverse, HIGH);
  digitalWrite(rforward, LOW);
  digitalWrite(rforward, LOW);
}
void right()
{
  digitalWrite(lforward, HIGH);
  digitalWrite(rforward, LOW);
  digitalWrite(lreverse, LOW);
  digitalWrite(rreverse, HIGH);
}
void left()
{
  digitalWrite(lforward, LOW);
  digitalWrite(rforward, HIGH);
  digitalWrite(lreverse, HIGH);
  digitalWrite(rreverse, LOW);
}
void loop() 
{
  Serial.begin(9600);
  digitalWrite(btpower, HIGH);
  if(Serial.available()>0){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){           
  forward();
}
 
else if(t == 'B'){      
  reverse();
}
 
else if(t == 'L'){      
  left();
}
 
else if(t == 'R'){      
  right();
} 
else if(t == 'S'){      
  digitalWrite(lreverse,LOW);
  digitalWrite(rreverse,LOW);
  digitalWrite(lforward,LOW);
  digitalWrite(rforward,LOW);
}
delay(100);
}
