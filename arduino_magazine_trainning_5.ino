//This program allows the door openning with:
//(1) Manual activation 


#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo

int Lswitch = 2;
int statusSensor = 0; //variable to store if the switch was activated
int statusDoor = 0; // variable to store of the door is open or closed. open = 1 closed = 0
int count = 0; //variable to store how many times the door was activated

unsigned long previousMillis = 0;
int interval=12000;


void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  motor.attach(7); //attaches the servo on pin 7 to the servo object
  pinMode(Lswitch,INPUT_PULLUP);
}

void loop() {
  
   motor.detach();
  if (digitalRead(Lswitch) == 0){ //"0" means that the switch has been activated
    statusSensor = 1;
//    Serial.println(digitalRead(Lswitch));
  }

  if (statusSensor == 1 && statusDoor == 0)
  {        
    count = count+1;
    Serial.println(count);
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(0); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
    delay(600);  // motor will continue rotating for 0.6 seconds
    motor.detach(); // telling the motor to stop
    statusDoor = 1;
    statusSensor = 0;
    Serial.println("Door open");
  }

    if (statusSensor == 1 && statusDoor == 1)
  {        
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(180); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
    delay(800);  // motor will continue rotating for 0.8 seconds
    motor.detach(); // telling the motor to stop
    statusDoor = 0;
    statusSensor = 0;
    Serial.println("Door closed");
  }
    
}
