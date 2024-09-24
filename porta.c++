#include<Servo.h>
int trigger = 7;
int echo = 8;
int ledR = 12;
int dist = 0;
int ServoPin = 11;

Servo myServo;

void setup() 
{
  pinMode(ServoPin, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledR, OUTPUT);
  myServo.attach(ServoPin);

  Serial.begin(9600);
  
}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  dist = pulseIn(echo, HIGH);
  dist = dist /58;

  acenderLed(0, 30, ledR, dist);
  Serial.println(dist);
}

void acenderLed(int distMin, int distMax, int led, int dist)
{
  if(dist >= distMin && dist <= distMax)
  {
    digitalWrite(led, HIGH);
    myServo.write(90);
  }else{
    digitalWrite(led, LOW);
    myServo.write(0);
  }
}