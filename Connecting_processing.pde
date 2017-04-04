import processing.serial.*;

Serial myPort;  // Create object from Serial class
boolean b;
void setup() 
{
  size(200,200); //make our canvas 200 x 200 pixels big
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 115200);
}

void draw()
{
  //byte r = (byte)random(180);
  b = !b;
  if (b)
   myPort.write(0);
   else
   myPort.write(20);
}