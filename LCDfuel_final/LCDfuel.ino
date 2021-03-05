// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at www.ardublog.com

#include <Ultrasonic.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD arduino library

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
int lev=0;
int cap=0;

void setup() {
lcd.begin(16, 2);
Serial.begin(9600);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("hai");
  delay(200);
  lcd.clear();
    lcd.setCursor(0, 7);
    lcd.print("nutella");
 /* lev=(ultrasonic.Ranging(CM)); // CM or INC
  cap=lev*10*10;
  Serial.print(cap);
  Serial.println("millilitres");
  lcd.print(cap);
  lcd.setCursor(0,9);
  lcd.print("ml");
    //Serial.print()); // CM or INC
 level=ultrasonic.Ranging(CM);
 cap=level*10*10;
 
  Serial.print(cap);
    Serial.println("litres");

  */
  delay(1000);
  

  /*lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("nutella");
  lcd.blink();
  delay(3000);*/
}+
