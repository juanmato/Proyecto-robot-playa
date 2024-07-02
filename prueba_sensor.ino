#include <HCSR04.h> 
// Define los pines del sensor ultrasónico 
byte triggerPin = 13; 
byte echoPin = 12; 
// Define los pines del motor 
int motord_pin1 = 3; 
int motord_pin2 = 5; 
int motori_pin1 = 6; 
int motori_pin2 = 11; 
// Inicializa el sensor ultrasónico 
void setup() { 
  // Configura los pines de los motores como salida 
  pinMode(motord_pin1, OUTPUT); 
  pinMode(motord_pin2, OUTPUT);  
  pinMode(motori_pin1, OUTPUT);  
  pinMode(motori_pin2, OUTPUT);  
  Serial.begin(9600); 
  HCSR04.begin(triggerPin, echoPin); 
} 
void loop() { 
  // Mide la distancia 
  double* distances = HCSR04.measureDistanceCm(); 
  // Imprime la distancia medida 
  Serial.print("1: "); 
  Serial.print(distances[0]); 
  Serial.println(" cm"); 
  Serial.println("---"); 
  delay(250); 
  double stop = 40; 
  // Comprueba si la distancia es menor que el valor de parada 
  if (distances[0] < stop and distances[0] > 2) { 
    // Para el robot 
    analogWrite(motord_pin1, 0); 
    analogWrite(motord_pin2, 0); 
    analogWrite(motori_pin1, 0); 
    analogWrite(motori_pin2, 0); 
    delay(1000); 
    // Va hacia atrás 
    analogWrite(motord_pin1, 200);  
    analogWrite(motord_pin2, 0);  
    analogWrite(motori_pin1, 200);  
    analogWrite(motori_pin2, 0);  
    delay(1000); 
    // Gira el robot 
    analogWrite(motord_pin1, 200);  
    analogWrite(motord_pin2, 0);  
    analogWrite(motori_pin1, 0);  
    analogWrite(motori_pin2, 0);  
    delay(800);  
  } 
  else { 
    // Sigue avanzando 
    analogWrite(motord_pin1, 0);  
    analogWrite(motord_pin2, 200);  
    analogWrite(motori_pin1, 0);  
    analogWrite(motori_pin2, 200); 
  } 
} 
