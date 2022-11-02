
//This program allows the door openning with:
//(1) Infrared sensor

#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo

int IRSensor = 2; // connect ir sensor to arduino pin 2 
int count = 0; //variable to store how many times the door was activated
int active = 0; //variable to store if the switch was activated
unsigned long time;

void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  motor.attach(7); //attaches the servo on pin 7 to the servo object
  pinMode(IRSensor, INPUT_PULLUP);
}

void loop() {
  motor.detach();
  int statusSensor = digitalRead (IRSensor);

  if (statusSensor == 1)
  {
    count = count+1;
    Serial.println(count);
    Serial.print("Time passed (s):");
    time = millis();
    Serial.println(time/1000);
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(0); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
    delay(600);  // motor will continue rotating for 0.6 seconds
    motor.detach(); // telling the motor to stop
    delay(3000);  // motor will remained stopped for 3 seconds
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(180); // telling the motor to rotate continously
    delay(900);  // motor will continue rotating for 0.65 seconds
    motor.detach(); // telling the motor to stop
    statusSensor = 0;
  } 
}
