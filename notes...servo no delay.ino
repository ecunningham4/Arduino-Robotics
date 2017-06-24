#include <Servo.h>


Servo servo1; // Create a servo object

Servo servo2; // Create a servo object
 

long elapsed_time = 0;
long previousMillis = 0;
long previousMillis2 = 0;
long servointerval = 15;
long interval = 1000;
int pos = 0;


void setup() {
   
  servo1.attach(5); // Attaches the servo on Pin 5 to the servo object

  servo2.attach(6); // Attaches the servo on Pin 5 to the servo object
}

void loop() { 
  
  for(pos = 0; pos < 60; pos+=60) {      //opens the arm 60 degrees
       unsigned long servoMillis = millis();
      if(servoMillis - previousMillis > servointerval)  //created to delay 15 milliseconds before next pulse
        {
         previousMillis = servoMillis;
         servo1.write(pos);      //moves 5 degrees every 15 milliseconds
        }
     
     }
       
      unsigned long Starttimer=millis();      //starts one second delay timer?
         do {
            unsigned long current_time = millis();
            elapsed_time = current_time - Starttimer;
            }
            while(elapsed_time < interval);      //leaves loop when 1 second has passed
      
      
      for(pos = 60; pos >=60; pos-=60) {    //closes the arm back to 0 degrees
        unsigned long servoMillis2 = millis();
        if(servoMillis2 - previousMillis2 > servointerval)
        {
        previousMillis2 = servoMillis2;
        servo1.write(pos);
        }
       
    }
       
      }
      
      
      
      
      ///////////////////////////////////////
      
      
      
      
      
      #include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#include <Servo.h>

Servo servo1; // Create a servo object

Servo servo2; // Create a servo object



void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 

   servo1.attach(5); // Attaches the servo on Pin 5 to the servo object

  servo2.attach(6); // Attaches the servo on Pin 5 to the servo object

}









void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);


  servo1.write(10); // Rotate the servo 5

  servo2.write(180); // Rotate the servo 6

  delay(300);

   servo1.write(180); // Rotate the servo 5

  servo2.write(10); // Rotate the servo 6

  delay(300);


   if(measure.RangeStatus <=20)        // if ultrasonic sensor detects an obstacle less than 20cm in 90 degree angle.
 
  {servo1.write(10); // Rotate the servo 5
  
  delay(2000);

  servo1.write(180); // Rotate the servo 5
        //servo rotates at full speed to the right
 
   delay(2000);
   
  }
  
  else{servo1.write(10); // Rotate the servo 5
  
  delay(300);

  servo1.write(180); // Rotate the servo 5
        //servo rotates at full speed to the right
 
   delay(300);
   }

  
}
