//This program allows the door openning with both:
//(1) The infrared sensor and,
//(2) Maual activation 


#include <Servo.h> //library to operate servo motors
Servo motor; //create servo object to control a servo

int IRSensor = 2; // connect ir sensor to arduino pin 2  //Lswitch = 2;
int active = 0; //variable to store if the switch was activated
int count = 0; //variable to store how many times the sensor was activated

unsigned long previousMillis = 0;
int interval=12000;


void setup() {
  Serial.begin(9600);  //This value of bits per second is by default
  motor.attach(7); //attaches the servo on pin 7 to the servo object

  pinMode(IRSensor, INPUT);// sensor pin INPUT  //INPUT_PULLUP
  //pinMode(motor,OUTPUT);
}

void loop() {
  int statusSensor = digitalRead (IRSensor);
  unsigned long currentMillis = millis();
  
  //motor.detach();
  //delay(1000);

//  if (digitalRead(Lswitch) == LOW){ //"LOW" means that the switch has been activated
//    statusSensor = 1;
//  }

  if (statusSensor == 1)
  {        
    count = count+1;
    Serial.println(count);
    //Serial.print("\t");
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(0); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
    delay(600);  // motor will continue rotating for 0.6 seconds
    motor.detach(); // telling the motor to stop
    delay(20000);  // motor will remained stopped for 20 seconds
    Serial.println('*');
    motor.attach(7);  //re-attach the servo to pin #7
    motor.write(180); // telling the motor to rotate continously
    delay(600);  // motor will continue rotating for 0.6 seconds
    statusSensor = 0;
    //myTime = restart;
  } else {
    //active = 0;
    motor.detach();
    //delay(1000);
  }


// if ((currentMillis - previousMillis) == interval) {
//      // It's time to do something!
//    previousMillis = currentMillis; // Use the snapshot to set track time until next event    
//    Serial.println(previousMillis);
//    count = count+1;
//    Serial.println(count);
//    //Serial.print("\t");
//    motor.attach(7);  //re-attach the servo to pin #7
//    motor.write(0); // telling the motor to rotate continously (180 is full velocity in one direction, 0 full velocity in the other direction, 90 no movement)
//    delay(600);  // motor will continue rotating for 0.6 seconds
//    motor.detach(); // telling the motor to stop
//    delay(50000);  // motor will remained stopped for 50 second
//    motor.attach(7);  //re-attach the servo to pin #7
//    motor.write(180); // telling the motor to rotate continously
//    delay(600);  // motor will continue rotating for 0.6 seconds
//     
//   }
}
