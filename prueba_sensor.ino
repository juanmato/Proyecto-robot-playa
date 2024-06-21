#include <HCSR04.h>

byte triggerPin = 13;
byte echoPin = 12;
int motord_pin1 = 3;
int motord_pin2 = 5;
int motori_pin1 = 6;
int motori_pin2 = 11;

void setup () {
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
    analogWrite(motord_pin1, 0); 
    analogWrite(motord_pin2, 170); 
    analogWrite(motori_pin1, 0); 
    analogWrite(motori_pin2, 170);
    //para el robot
    Serial.print("stop");
    
    analogWrite(motord_pin1, 0);
    analogWrite(motord_pin2, 0);
    analogWrite(motori_pin1, 0);
    analogWrite(motori_pin2, 0);
    delay(1000);
    //va para atrás
    Serial.print("atras");
    analogWrite(motord_pin1, 170); 
    analogWrite(motord_pin2, 0); 
    analogWrite(motori_pin1, 170); 
    analogWrite(motori_pin2, 0); 
    delay(1000);
    Serial.print("giro");
    //gira el robot
    analogWrite(motord_pin1, 170); 
    analogWrite(motord_pin2, 0); 
    analogWrite(motori_pin1, 0); 
    analogWrite(motori_pin2, 0); 
    delay(800); 
  }
  else{
    analogWrite(motord_pin1, 0); 
    analogWrite(motord_pin2, 170); 
    analogWrite(motori_pin1, 0); 
    analogWrite(motori_pin2, 170);
  }
}
