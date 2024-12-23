
/*
  DBH-12 H-Bridge Demo
  dbh-12-demo.ino
  Demonstrates operation of DBH-12 Dual H-Bridge Motor Driver
    
  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/
 
// Motor Connections (All must use PWM pins)
#define IN1A 5
#define IN1B 6
#define IN2A 3
#define IN2B 9
 
// Define a fixed speed - do not exceed 250
int fixedSpeed = 80;
 
void setup() {
 
  // Set motor & enable connections as outputs
  pinMode(IN1A, OUTPUT);
  pinMode(IN1B, OUTPUT);
  pinMode(IN2A, OUTPUT);
  pinMode(IN2B, OUTPUT);
 
  // Stop motors
  analogWrite(IN1A, 0);
  analogWrite(IN1B, 0);
  analogWrite(IN2A, 0);
  analogWrite(IN2B, 0);
}
 
void loop() {
 
  // Accelerate both forward
  digitalWrite(IN1A, LOW);
  digitalWrite(IN1B, LOW);
  for (int i = 0; i < 200; i++) {
    analogWrite(IN2A, i);
    analogWrite(IN2B, i);
    delay(20);
  }
 
  delay(500);
 
  // Decelerate both forward
  for (int i = 200; i >= 0; i--) {
    analogWrite(IN2A, i);
    analogWrite(IN2B, i);
    delay(20);
  }
 
  delay(500);
 
}