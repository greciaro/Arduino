
#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo

int Lswitch = 2;
int active = 0; //variable to store if the switch was activated
int pos = 0; //variable to store the position of the motor

void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  motor.attach(7); //attaches the servo on pin 7 to the servo object

  pinMode(Lswitch,INPUT_PULLUP);
  //pinMode(motor,OUTPUT);
}

void loop() {
  
  //motor.detach();
  //delay(1000);
  
  if(digitalRead(Lswitch) == LOW){ //"LOW" means that the switch has been activated
    active = 1;
  }

  if(active == 1){
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(180); // telling the motor to rotate continously
    delay(1000);  // motor will continue rotating for 2 seconds  
    motor.detach(); // telling the motor to stop
    delay(15000);  // motor will remained stopped for 7 seconds 
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(0); // telling the motor to rotate continously
    delay(1000);  // motor will continue rotating for 2 seconds    
    active = 0;
    
  }else{
    active = 0;
    motor.detach();
    //delay(1000);
  }
}
  
