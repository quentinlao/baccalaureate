#include"Ultrasonic.h"
#define trigPin 12
#define echoPin 11

void setup()
{
  for(int i =1;i<=9;i++)
  {
    pinMode(i, OUTPUT);
  }  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  int duration, distance, lumiere; 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance >= 18 || distance <= 0)
    {
      for(int i=1;i<=9;i++)
        {
          digitalWrite(i, LOW);
        }
    }
  else
  {  
    lumiere = distance/2 +1;
    for(int i =lumiere;i<=9;i++)
      {
        digitalWrite(i, HIGH);
      }
    for(int i=1;i<lumiere;i++)
      {
        digitalWrite(i, LOW);
      }
  }
}
