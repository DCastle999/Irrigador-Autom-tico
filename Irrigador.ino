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
 sensors.requestTemperatures();  
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0;
 if (sensorValue >= 1000){
  Servo1.write(90); 
 }
 else
 Servo1.write(0);
 Serial.println(sensorValue); 
 delay(1000);
 
 Serial.print("Temperature: ");
 Serial.print(sensors.getTempCByIndex(0));
 Serial.print((char)176);//shows degrees character
 Serial.print("C  |  ");
 delay(500); 
} 
