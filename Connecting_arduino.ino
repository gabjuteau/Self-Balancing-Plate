#include <Servo.h>

Servo servo;
Servo servo2;
byte val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 13
bool isLEDon = false;
 
void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo2.attach(10);
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(115200); // Start serial communication at 9600 bps
}

void loop() {
  // put your main code here, to run repeatedly:
     val = Serial.read();
     isLEDon = !isLEDon;
     
   if(val>=0 && val <=180)
   {
    servo.write(val);
  
    servo2.write(val);

    for(int i=0; i < 20; i++)
      servo.refresh(); 
   }
   if (isLEDon)
    digitalWrite(ledPin, HIGH);
   else
    digitalWrite(ledPin, LOW); // otherwise turn it off
   delay(1); // Wait 10 milliseconds for next reading
}
/*
void loop()
{
  servo.write((int)random(180));
  servo2.write((int)random(180));
  delay(200);
}
*/

