#include <Servo.h>

bool pressed1 = false; // Used to detect if Button 1 was already pressed
bool pressed2 = false; // Used to detect if Button 2 was already pressed
int servoPin = 9; // Used to initialise the pin the servo is connected to.
int pwr1 = 0; // Used to power button 1
int pwr2 = 0; // Used to power button 2
Servo servo; // Declaring servo unit
int turnSpeed = 90;// sets angle of the motor
bool lockState = false; // Buttons are unlocked.

void setup()
{
  // put your setup code here, to run once:
  pinMode(4,INPUT); // Initialise pin 4 for Button 1
  pinMode(5,INPUT); // Initialise pin 5 for button 2
  pinMode(servoPin,OUTPUT); // Initialise servo pin
  digitalWrite(4,HIGH); // Initialise button1 press
  digitalWrite(5,HIGH); // Initialise button2 press
  servo.attach(9);
  servo.write(turnSpeed);
}

void loop()
{
  // put your main code here, to run repeatedly:
  pwr1 = digitalRead(4); // Assigning values to button 1
  pwr2 = digitalRead(5);// Assigning values to button 2
  
  // This section is used to handle inputs from the buttons
  if(pwr1==LOW && pressed1==false) // If button 1 is pressed once and is not locked
  {
    pressed1 = true; // Lock Button 1 to prevent spam
    pressed2 = true; // Lock Button 2 to prevent spam
    lockState = true; // Buttons are locked
    turnSpeed = turnSpeed - 10;// increase turn speed by lowering delay 
    servo.write(turnSpeed); // turn to new position
  }else if(lockState==true) // If button 1 and 2 is let go and buttons are still locked
  {
    Unlock();
  }
  
  if(pwr2==LOW && pressed2==false) // If button 2 is pressed and is not locked
  {
    pressed1 = true; // Lock Button 1 to prevent spam
    pressed2 = true; // Lock Button 2 to prevent spam
    lockState = true; // Buttons are locked
    turnSpeed = turnSpeed + 10; // decrease turn speed by increasing delay
    servo.write(turnSpeed); // turn to new posiiton
  }else if(lockState==true) // If button 1 and 2 is let go and buttons are still locked
  {
    Unlock();
  }
}

void Unlock()
{
  pressed1 = false; // Unlock Button 1
  pressed2 = false; // Unlock Button 2
  lockState = false;
}
