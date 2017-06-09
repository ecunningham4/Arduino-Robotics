void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
int a = 5;
int b = 10;
int c = 34;
int d;

d = averagefunction (a,b,c); 
Serial.println(d);
delay(500);
}

int averagefunction (int a, int b, int c) {
  int result; 
  result = (a + b + c) / 3;
  return result;
 }
