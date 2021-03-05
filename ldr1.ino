int  l1=A0;
int l2=A1;
int l3=A3;
int lr=0;
int lc=0;
int ll=0;

int enable1=2;
int enable2=4;
int m1p=7;
int m1n=8;
int m2p=12;
int m2n=13;

#include <Ultrasonic.h>

Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN)

void setup() {

Serial.begin(9600); 

  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode

pinMode(enable1,OUTPUT);
pinMode(m1p,OUTPUT);
pinMode(m1n,OUTPUT);
pinMode(enable2,OUTPUT);
pinMode(m2p,OUTPUT);
pinMode(m2n,OUTPUT);  
}

void loop() {
digitalWrite(enable1,HIGH);
digitalWrite(enable2,HIGH);
/*digitalWrite(m1p,HIGH);
digitalWrite(m1n,LOW);
digitalWrite(m2p,HIGH);
digitalWrite(m2n,LOW);*/
Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  
  lr =analogRead(A0);
  lc=analogRead(A1);
  ll=analogRead(A2);
  delay(50);

  if ((lr>lc)&&(lr>ll))
  {
   //; // CM or INC
    Serial.println(" right shade" );
    digitalWrite(m2p,LOW);
    digitalWrite(m2n,LOW);
    //digitalWrite(enable1,LOW);
  }
   
  else if( lc>ll)
  {
    
    Serial.println(" left shade " );
    digitalWrite(m1p,LOW);
    digitalWrite(m1n,LOW);
    //digitalWrite(enable2,LOW);
    
  }
  else
  {
    Serial.println(" centre shade " );
    digitalWrite(m1p,HIGH);
    digitalWrite(m1n,LOW);
    digitalWrite(m2p,HIGH);
    digitalWrite(m2n,LOW);

  }


  


  
}
