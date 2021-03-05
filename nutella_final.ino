ṁṁ//Arduino code to read RFID tag and send text message 1234 or 4321 to the mobile number 91235767919 
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

#include <SoftwareSerial.h>
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];
byte knownTac[4] = {9,111,156,26};//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
boolean KNOW = true;  
const int buzzer = 53;
const int sensor = 4;
int flag = 0;
int state; // 0 close - 1 open wwitch
int sensorThres = 128;
int analogSensor = 0;
byte Flag1 = 0;
void setup()
{
  pinMode(sensor, INPUT_PULLUP);
  pinMode(buzzer, HIGH);
  Serial.begin(9600);SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  delay(5000); // time to log on to network.
  Serial.print("AT+CMGF=1\r"); //SMS mode to text
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  Serial.println("AT+CMGD=1,4");
}

void loop()
{


 // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
 

for(int i = 0; i < 4; i++){                     //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  if (knownTac[i] != nuidPICC[i]){
    KNOW = false;
   // Serial.println("ready to go :)");
  }else{
 // Serial.println("Please wait until next bus arrives");
  KNOW = true;
  }
}
         
  }
  else Serial.println(F("Card read previously."));

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();

  
  if (KNOW==true && Flag1 == 0)
  {
    
    Serial.println("AT");
    delay(2000);
    Serial.println("AT");
    delay(2000);
    Serial.println("AT+CMGF=1");
    delay(1000);
    Serial.println("AT+CMGS=\"09123576919\"");//"AT+CMGS=\"08489314701\"");//("AT+CMGS=\"07373736772\"");
    Serial.println("1234");
    
    delay(1000);
    Serial.write(26);
    Flag1 = 0;        // set flag1 OFF to allow another new card read while this read condition remains High
  }

  if (KNOW!=true && Flag1 == 0 )
  {
    
    
    Serial.println("AT"); 
    delay(2000);
    Serial.println("AT");
    delay(2000);
    Serial.println("AT+CMGF=1");
    delay(1000);
    Serial.println("AT+CMGS=\"09123576919\"");//("AT+CMGS=\"09790272234\"");
    delay(1000);
    Serial.println("4321");
    delay(1000);
    Serial.write(26);
    Flag1 = 0;       // clear Flag1 to allow new read condition.
  } 
} 
