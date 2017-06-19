/*
HC-SR04 
 
Circuit:
  VCC to arduino 5v 
  GND to arduino GND
  Echo to Arduino pin 9      //echo 11 trig 12  when not lilypd
  Trig to Arduino pin 10
 
Based on code from
http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/step3/Upload-the-sketch/
*/

const int trigPin = 10;

const int echoPin = 9;

#include <Servo.h>

Servo servo1; // Create a servo object

Servo servo2; // Create a servo object


 
void setup() {
 
  servo1.attach(5); // Attaches the servo on Pin 5 to the servo object

  servo2.attach(6); // Attaches the servo on Pin 5 to the servo object

  Serial.begin (9600);
 
  pinMode(trigPin, OUTPUT);    //sets up pin 10 for output   //
  
  pinMode(echoPin, INPUT);    //sets up 9 as input

}

 

void loop() {

//  servo1.write(10); // Rotate the servo 5
//
//  servo2.write(10); // Rotate the servo 6
//
//  delay(1000);
//
//   servo1.write(90); // Rotate the servo 5
//
//  servo2.write(90); // Rotate the servo 6
//  
//
//  delay(1000);


long duration, distance;
 
  // Drive trigger pin LOW, HIGH, LOW to send the pulse
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);

  // the pulseIn command waits for a given pin to go HIGH, and then 
  // reports how long it waited until that happened
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo

  // Convert to centimeters
  distance = (duration/2) / 29.1;  // calculate the distance in cm

  // Discard readings that are too large or too small to be reasonable
  // It's pretty common for some sensors to give occasional bad readings
  // and a good program must take that into account
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range; reading invalid");
  } else {
    // anything left should be a valid distance
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(200);    // wait before doing it again


}
