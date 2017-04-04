import processing.serial.*;

Serial myPort;  //Create object from Serial class

void setup()
{
  size(200,200);
  String portName = Serial.list()[2];
  
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if(mousePressed == true)  // if we clicked in the window
  {
    myPort.write(180);
    println("180");
  }
  
  else
  {
    myPort.write('0');
  }
}