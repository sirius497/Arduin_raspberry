

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
  Serial.begin(9600);
  delay(5000); // give time to log on to network.
  Serial.print("AT+CMGF=1\r"); // set SMS mode to text
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  Serial.println("AT+CMGD=1,4");
}

void loop()
{

  //  analogSensor = analogRead(A0);
  analogSensor = 10;
  Flag1=1;
  if (analogSensor > sensorThres && Flag1 == 0)
  {
    digitalWrite(buzzer, HIGH);
    Serial.println("AT");
    delay(2000);
    Serial.println("AT");
    delay(2000);
    Serial.println("AT+CMGF=1");
    delay(1000);
    Serial.println("AT+CMGS=\"09123576919\"");
    delay(1000);
    Serial.println("Gas has been detected in the house. Buzzer has been turned on.");
    delay(1000);
    Serial.write(26);
    Flag1 = 1;        // set flag1 ON to stop any further sms while this alarm condition remains High
  }

  if (analogSensor < sensorThres && Flag1 == 1 )
  {
    digitalWrite(buzzer, LOW);
    Flag1 = 0;       //  alarm condition now gone low, so tuurn off buzzer and clear Flag1 to allow new alarm condition.
    Serial.println(" ");
    Serial.println("No Gas Alarm,  Buzzer has been turned OFF.");
    Serial.println(" ");
    delay(1000);
  }

} 
