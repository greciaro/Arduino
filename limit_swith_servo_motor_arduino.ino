
#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo



//int Lswitch = 2;
//int pos = 0; //variable to store the motor position



void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  //pinMode(Lswitch,INPUT);
  motor.attach(7); //attaches the servo on pin 9 to the servo object
  //pinMode(motor,OUTPUT);
}

void loop() {

  servo.detach(); // This indicates the motor to stop
  delay(2000);  // The motor will remained stopped for 2 seconds 
  servo.attach(7);  //This re-attach the servo to pin #7
  

  //if (digitalRead(Lswitch)== LOW){
    //Serial.println("door is innactive");
  //}

 // if (digitalRead(Lswitch)== HIGH){
  //  Serial.println("door is active");
  
  //  for (pos = 0; pos <= 180; pos += 1){ //goes from 0 degrees to 350 degrees
      //in steps of 1 degree
   //   motor.write(pos); //tells servo to go to position in variable 'pos'
   //   delay(15);  //waits 15ms for the servo to reach the position
   // }

    //delay(15000); //15000 = 15 seconds
    
 //   for (pos = 180; pos >= 0; pos += 1){ //goes from 0 degrees to 350 degrees
   //   motor.write(pos); //tells servo to go to position in variable 'pos'
   //   delay(15);  //waits 15ms for the servo to reach the position    
   // }

 // }

}
