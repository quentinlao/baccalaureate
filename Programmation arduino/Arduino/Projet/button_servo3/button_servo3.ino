#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(2,INPUT);
  pinMode(3,INPUT);
} 
 int appuie = 0;
 int appuie2 = 0; 
 int temp = 0;
 
void loop() 
{ 
  appuie = digitalRead(2);
  appuie2 = digitalRead(3);

  if(appuie == HIGH)
  {
     if(pos < 179)
       {
             pos = pos + 1;
             myservo.write(pos);              
             delay(15);                                
       }

  }

  if(appuie2 == HIGH)
  {
        if(pos > 1)
       {
             pos = pos - 1;
             myservo.write(pos);              
             delay(15);                                
       }                                  
  }
   
    
  
}
