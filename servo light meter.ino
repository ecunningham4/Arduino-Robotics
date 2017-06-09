int sensorPin1 = A0;   //select input pin for LDR 1
int sensorPin2 = A1;   //select input pin for LDR 2
Servo myservo;     //create servo object to control a servo
int val1 = 0;          //variable to store the value coming from sensor 1 
int val2 = 0;          //variable to store the value coming from sensor 2 
int pos = 0;           //// variable to store the servo position

void setup() {
  
myservo.attach(9);     //attaches the servo on pin 9 to servo object
Serial.begin(9600);    //sets seial port for communiction
}

void loop() {

val1 = analogRead(sensorPin1);     // read value from sensorPin1 place value in val1

val2 = analogRead(sensorPin2);     // read value from sensorPin2 place value in val2

Serial.println(val1);              //prints the value of sensorPin1 on screen

Serial.println(val2);              //prints the value of sensorPin2 on screen

if (val1 > 50)  {
(pos = 0; pos <= 180; pos += 1)   //goes from 0 to 180 degrees in steps of 1 degrees
{myservo.write(pos);               //tells servo to go to position in variable
delay (15); }                       // waits 15 ms for the servo to reach the position

}

else
{
  (val1 < 50)  {
}
(pos = 180; pos >= 0; pos -= 1)   //goes from 0 to 180 degrees in steps of 1 degrees
{myservo.write(pos);              //tells servo to go to position in variable
delay (15); }                       // waits 15 ms for the servo to reach the position
  
}


delay(100);

}
