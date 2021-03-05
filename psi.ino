
#include <GSM.h>
int timestosend=10;
int count=0;
char phone_no[]="8526646702"; //phone number
void setup()
{
  Serial.begin(9600);  //open serial connection at baud 9600
  delay(2000);
  Serial.println("AT+CMGF=1"); //set GSM to text mode
  delay(200);
}
void loop()
{
  
float sensorvoltage = analogRead(A0);
int psi = (sensorvoltage/1024*50);
int Force = ((psi*6.834)*0.454);
Serial.println(Force);

  while(count<timestosend){
    delay(1500);
    Serial.print("AT+CMGS=\"");
    Serial.print(phone_no);
    Serial.println("\"");
     while(Serial.read()!='>');
     {
      Serial.print("Force");
      delay(500);
      Serial.write(0x1A); // sends ctrl+z end of message
      Serial.write(0x0D); // carriage Return in Hex
      Serial.write(0x0A); // Line feed in Hex
      //The 0D0A PAIR OF characters is the signal for the end of a line
      delay(5000);
    }
      count++;
      }
      delay(100);
      }
    
 
   
      
  

