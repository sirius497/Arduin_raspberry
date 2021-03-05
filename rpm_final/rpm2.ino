int wheelPin = 11; // I/O pin for encoder
int count = 0; // number of encoder ticks 
bool rising = false; // bool for rising edge of encoder signal
double dt; // time between rising edges
long dtStore[2]; // FIFO array holding current and previous rising edge times
float rpm;

void setup(){
  Serial.begin(57600);
}

void loop() {
  int wheelVal = analogRead(wheelPin); // get encoder val

/* check to see if we are at a low spot in the wave.  Set rising (bool) so we know to expect a rising edge */

if (wheelVal < 200) {
  rising = true;
}

/* Check for a rising edge.  Rising is true and a wheelVal above 200 (determined experimentally)*/

if (rising && wheelVal > 200) {
   dtStore[0]=dtStore[1]; // move the current time to the previous time spot
   count++;
   dtStore[1] = millis(); // record the current time of the rising edge
   dt = dtStore[1]-dtStore[0]; // calculate dt between the last and current rising edge time
   rpm = (0.0625)/dt*1000*60; // RPM calculation
   rising = false; // reset flag
 } 
Serial.println(rpm);
}
