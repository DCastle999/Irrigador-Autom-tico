#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SensorPin A0
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);

int servoPin = 3; 
float sensorValue = 0;
Servo Servo1;
 
void setup() {
 sensors.begin(); 
 Serial.begin(9600);
 Servo1.attach(servoPin);  
} 
void loop() {
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0;

 if (sensorValue >= 700)
 {
  Servo1.write(0);
 } else if (sensorValue >= 600)
 {
   Servo1.write(15); 
 } else if (sensorValue >= 500)
 {
  Servo1.write(30); 
 } else if (sensorValue >= 425)
 {
  Servo1.write(45); 
 } else if (sensorValue >= 375)
 {
  Servo1.write(60); 
 } else if (sensorValue >= 290)
 {
  Servo1.write(75); 
 } else 
 {
  Servo1.write(90); 
 }
 
 Serial.println(sensorValue); 
 delay(1000);
} 
