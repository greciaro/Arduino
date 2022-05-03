
//This program allows the door openning with:
//(1) Infrared sensor

#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo

int IRSensor = 2; // connect ir sensor to arduino pin 2 
int count = 0; //variable to store how many times the door was activated
int active = 0; //variable to store if the switch was activated
int sensoractive = 0;
int statusSensor = 0;
int IR_out = LOW;

boolean state = false;

void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  motor.attach(7); //attaches the servo on pin 7 to the servo object
  pinMode(IRSensor, INPUT);
}

void loop() {
  motor.detach();

//  void loop() {
//  IR1_out = digitalRead(IR1);
//  IR2_out = digitalRead(IR2);
//  if(IR1_out == LOW) {
//    increaseAndDisplay();
//    delay(500);
//  }
//  if(IR2_out == LOW) {
//    decreaseAndDisplay();
//    delay(500);
//  } 
//  delay(100);
//}

  
  Serial.println(digitalRead(IRSensor)); 
  
//  if (IR_out == HIGH);
//  {
//    count++;
//    state = false;
//    Serial.print("Count: ");  
//    Serial.println(count);  
//    delay(100);
//  }

  if (digitalRead (IRSensor))
  {
    state = true;
    delay(100);
  }
  
  if (sensoractive == 1)
  {
    sensoractive = 0;
    delay(200);
    active = active + 1;
    delay(200);
    Serial.println(active);
    statusSensor = 0;
  }

  if (active == 3)
  {
    count = count+1;
    Serial.print("openning #: ");
    Serial.println(count);
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(0); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
    delay(500);  // motor will continue rotating for 0.5 seconds
    motor.detach(); // telling the motor to stop
    delay(7000);  // motor will remained stopped for 7 seconds
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(180); // telling the motor to rotate continously
    delay(505);  // motor will continue rotating for 0.505 seconds
    motor.detach(); // telling the motor to stop
    statusSensor = 0;
    active = 0;
  } 
}
