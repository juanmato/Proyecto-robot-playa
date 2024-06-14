#include <HCSR04.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int potpin = 10; 

byte triggerPin = 13;
byte echoPin = 12;
int motord_pin1 = 3;
int motord_pin2 = 5;
int motori_pin1 = 6;
int motori_pin2 = 11;

void setup () {
  myservo.attach(potpin);  // attaches the servo on pin 9 to the servo object
  pinMode(motord_pin1, OUTPUT);
  pinMode(motord_pin2, OUTPUT); 
  pinMode(motori_pin1, OUTPUT); 
  pinMode(motori_pin2,OUTPUT); 
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
}

void loop () {
  double* distances = HCSR04.measureDistanceCm();
  
  Serial.print("1: ");
  Serial.print(distances[0]);
  Serial.println(" cm");
  
  Serial.println("---");
  delay(250);

  
  double stop = 30;
  if (distances[0] < stop){
    //para el robot
    analogWrite(motord_pin1, 0);
    analogWrite(motord_pin2, 0);
    analogWrite(motori_pin1, 0);
    analogWrite(motori_pin2, 0);
    delay(1000);
    //va para atrás
    analogWrite(motord_pin1, 110); 
    analogWrite(motord_pin2, 0); 
    analogWrite(motori_pin1, 110); 
    analogWrite(motori_pin2, 0); 
    delay(1000);
    //gira el robot
    analogWrite(motord_pin1, 110); 
    analogWrite(motord_pin2, 0); 
    analogWrite(motori_pin1, 0); 
    analogWrite(motori_pin2, 0); 
    delay(800); 
  }
  else{
    analogWrite(motord_pin1, 0); 
    analogWrite(motord_pin2, 110); 
    analogWrite(motori_pin1, 0); 
    analogWrite(motori_pin2, 110);
    
  }
  for (pos = 100; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 160; pos >= 100; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
