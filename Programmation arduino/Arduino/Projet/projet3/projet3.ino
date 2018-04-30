const int sensorPin = A0;
const float baseLineTemp = 20.0; //float values can store decimals.
 
void setup() {
  Serial.begin(9600); //open a serial port
  for(int pinNumber = 2; pinNumber<6; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}
 
void loop() {
  int sensorVal = analogRead(sensorPin);
 
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
 
  //convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
 
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C:");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
 
  if(temperature < baseLineTemp){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
 
  }else if(temperature >= baseLineTemp+2 && temperature <baseLineTemp+4){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    
   
  }else if(temperature >= baseLineTemp+4 && temperature < baseLineTemp+8){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    
   
  }else if(temperature >= baseLineTemp+8){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    
  }
  delay(100);
}

