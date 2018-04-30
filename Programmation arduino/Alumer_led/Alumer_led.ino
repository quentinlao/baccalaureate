int ledpin=13;
int bouton=2;
int etat=0;
int prev_etat=0;

void setup(){
 pinMode(ledpin,OUTPUT);
 pinMode(bouton,INPUT);
}

void loop(){
 int val=digitalRead(bouton);
 
 if((val==HIGH) && (prev_etat==LOW)){
   etat= 1 - etat;
   delay(10);
 }
 
 prev_etat=val;
 
 if(etat==0){
   digitalWrite(ledpin,HIGH); 
 } else {
   digitalWrite(ledpin,LOW); 
 }
}
