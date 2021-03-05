int timestosend=1;
int count=0;
char phone_no[]="8526646702"; //phone number
void setup()
{
  Serial.begin(9600);  //open serial connection at baud 9600
 
}
void loop()
{
 
     while(Serial.read()=='1');
     {
      Serial.print("CM Siva");
      delay(500);
      Serial.write(0x1A); // sends ctrl+z end of message
      Serial.write(0x0D); // carriage Return in Hex
      Serial.write(0x0A); // Line feed in Hex
      //The 0D0A PAIR OF characters is the signal for the end of a line
      delay(1000);
    }
  
}
      
      
  

