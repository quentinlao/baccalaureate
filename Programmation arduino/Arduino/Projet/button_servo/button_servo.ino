#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(2,INPUT);
} 
 int appuie = 0;
 int temp = 0;
 
void loop() 
{ 
  appuie = digitalRead(2);
  if(appuie == HIGH)
  {
    temp = temp + 1;
    
            if(temp % 2 == 0)
                {
                     for(pos = 0; pos < 180; pos += 1)  
                    {                                  
                    myservo.write(pos);              
                    delay(15);                       
                    } 
                  
                }
        
         if(temp % 2 != 0)
                {
                    for(pos = 180; pos>=1; pos -= 1)  
                    {                                  
                    myservo.write(pos);              
                    delay(15);                       
                    } 
                  }

    
  }
   if(appuie == LOW)
  {
                                     
                    
                    
  }


   
    
  
}
