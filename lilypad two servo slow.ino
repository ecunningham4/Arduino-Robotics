#include <Servo.h>

Servo servo1; // Create a servo object

Servo servo2; // Create a servo object
 
void setup() {
 
  servo1.attach(5); // Attaches the servo on Pin 5 to the servo object

  servo2.attach(6); // Attaches the servo on Pin 5 to the servo object

}

 

void loop() {

  servo1.write(10); // Rotate the servo 5

  servo2.write(10); // Rotate the servo 6

  delay(1000);

   servo1.write(90); // Rotate the servo 5

  servo2.write(90); // Rotate the servo 6
  

  delay(1000);


}
