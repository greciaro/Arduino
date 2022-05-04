
//This program allows the door openning with:
//(1) Infrared sensor

#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo

int IRSensor = 2; // connect ir sensor to arduino pin 2 
int count = 0; //variable to store how many times the door was activated
int sensoractive = 0;//variable to store if the switch was activated
int number1 = 0; //intital state of the sensor
int number2 = 0; //following state of the sensor
int state = 0;

void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  motor.attach(7); //attaches the servo on pin 7 to the servo object
  pinMode(IRSensor, INPUT);
}

void loop() {
  motor.detach();
  number1 = digitalRead (IRSensor);
  delay(100);
  number2 = digitalRead (IRSensor);
  
  if ((number1 - number2) == 1){
    state = 1;
  }
  
  if (state == 1){
    sensoractive++;
    Serial.print("sensor activation: ");  
    Serial.println(sensoractive);
    state = 0;
    number1 = 0;
    number1 = 0;
  }

  if (sensoractive == 7)
  {
    count++;
    Serial.print("openning #: ");
    Serial.println(count);
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(0); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
    delay(500);  // motor will continue rotating for 0.5 seconds
    motor.detach(); // telling the motor to stop
    delay(7000);  // motor will remained stopped for 7 seconds
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(180); // telling the motor to rotate continously
    delay(500);  // motor will continue rotating for 0.5 seconds
    motor.detach(); // telling the motor to stop
    sensoractive = 0;
  } 
}
