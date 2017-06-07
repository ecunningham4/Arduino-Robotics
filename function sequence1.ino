void setup() 
{
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);

}

void loop()
{
  digitalWrite(2 , HIGH);  //forwrd
  digitalWrite(3 , LOW);
  digitalWrite(4 , HIGH);
  digitalWrite(5 , LOW);
  delay(1000);
  digitalWrite(2 , LOW);   //bckwrd
  digitalWrite(3 , HIGH);
  digitalWrite(4 , LOW);
  digitalWrite(5 , HIGH);
 delay(1000);
 
turn1();

turn2();

 circle1();
 
circle2();
}




void turn1() {
  digitalWrite(2 , LOW);
  digitalWrite(3 , HIGH);     //right or left
  digitalWrite(4 , HIGH);
  digitalWrite(5 , LOW);
 delay(1000);
}

void turn2() {
   digitalWrite(2 , HIGH);
  digitalWrite(3 , LOW);
  digitalWrite(4 , LOW);        //right or left
  digitalWrite(5 , HIGH);
 delay(1000);
}

void circle1() {
  digitalWrite(2 , LOW);
  digitalWrite(3 , HIGH);
  digitalWrite(4 , HIGH);        //circle?
  digitalWrite(5 , LOW);
 delay(1000);
 digitalWrite(2 , LOW);
  digitalWrite(3 , HIGH);
  digitalWrite(4 , HIGH);
  digitalWrite(5 , LOW);          
 delay(1000);
 digitalWrite(2 , LOW);
  digitalWrite(3 , HIGH);
  digitalWrite(4 , HIGH);
  digitalWrite(5 , LOW);
 delay(1000);
 digitalWrite(2 , LOW);
  digitalWrite(3 , HIGH);
  digitalWrite(4 , HIGH);
  digitalWrite(5 , LOW);
 delay(1000);
}

void circle2() {
   digitalWrite(2 , HIGH);
  digitalWrite(3 , LOW);
  digitalWrite(4 , LOW);        //circle opposite direction
  digitalWrite(5 , HIGH);
 delay(1000);
 digitalWrite(2 , HIGH);
  digitalWrite(3 , LOW);
  digitalWrite(4 , LOW);       
  digitalWrite(5 , HIGH);
 delay(1000);
 digitalWrite(2 , HIGH);
  digitalWrite(3 , LOW);
  digitalWrite(4 , LOW);       
  digitalWrite(5 , HIGH);
 delay(1000);
 digitalWrite(2 , HIGH);
  digitalWrite(3 , LOW);
  digitalWrite(4 , LOW);        
  digitalWrite(5 , HIGH);
 delay(1000);
}
