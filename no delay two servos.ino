#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();


//QUADSweep
//edited from the original code by BARRAGAN

#include "Servo.h"

Servo myservo;  // create servo object to control a servo, a maximum of eight servo objects can be created
Servo mysecondservo;              // servo 2


int pos = 0;    // variable to store the servo position













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


myservo.attach(5);  // attaches the servo on pin 9 to the servo object
mysecondservo.attach(6); // attaches the servo on pin 10 to the servo object
  
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






unsigned long start = millis();
int sweepsNotFinished;

do
    {
    unsigned long now = millis() - start;
    sweepsNotFinished = 0;
    sweepsNotFinished += sweep(now, 0, 1000, 0, 180, myservo); // 1/2 second delay then 1 second sweep from 90 to 0
    sweepsNotFinished += sweep(now, 0, 1000, 0, 180, mysecondservo); // no delay and 2 second sweep from 180 to 75
    
   } while (sweepsNotFinished > 0);
  }

  int  sweep(unsigned long currentTime, unsigned long startTime, unsigned long endTime, int startPosition, int endPosition, Servo &servo)
  {
  if (currentTime < startTime)
    return 1;
  if (currentTime > endTime)
    return 0;
  servo.write( startPosition + (endPosition-startPosition) * (currentTime-startTime) / (endTime-startTime));
  return 1;

 
}
