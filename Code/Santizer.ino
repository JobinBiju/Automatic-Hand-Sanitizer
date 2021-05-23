#include <Servo.h>

Servo servo1;
Servo servo2;
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
servo1.attach(5);
servo2.attach(11);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

servo1.write(90);
servo2.write(90);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

 if(distance<9){
  servo1.write(0);
  servo2.write(180);
  delay(500);}
 else{
  delay(100);
  servo1.write(90);
  servo2.write(90);}
  
  
}
