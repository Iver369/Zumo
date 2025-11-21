#include "globals.h" 
#include "battery.h" 
#include "calibrate.h"
#include "display.h" 
#include "line_follow.h"
#include "obstacle.h"

int offset = 0;
UltraSonicSensor sensor;

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  displayStartup();
  pinMode(13, OUTPUT);
  sensor.init(5, 6, 10.0); // pins and threshold
  // Initialize shared line sensor object and motors (defined in globals.cpp)
  lineSensors.initFiveSensors(); // Initialize all five line sensors
  calibrateLineSensors(lineSensors, motors, 5000); // Calibrate for 5 secondss
  Serial.println("Calibration complete."); // Indicate completion
}

void loop() {
  displayStatus();
  static unsigned long lastUpdate = 0;
  unsigned long now = millis();
  static unsigned long Sensortime = 0;
  chargeBattery();

      if (now - Sensortime > 50) {
        Sensortime = now; 
        digitalWrite(13, HIGH);
        sensor.readDistance();
        sensor.averageDistance();
        sensor.printDebug();
        digitalWrite(13, LOW);
  } 
  if (sensor.isObstacleNear()) {
      Serial.println("Obstacle detected! Stopping motors.");
      motors.setSpeeds(0, 0); 
      return;
}
    if (now - lastUpdate >= 500) {
      float deltaTime = (now - lastUpdate) / 1000.0;
      lastUpdate = now;

      if (!isCharging) {
        battery_calculator(deltaTime);
      }
      checkBatteryState(); 
    } 

    if (!isCharging) {
      linefollow(); 
      crossroads();
      Serial.print("Offset: ");
      offset = lineSensors.readLine(sensorValues);
      Serial.print(offset);
      Serial.println(""); 

      for (int i = 0; i < 5; i++) {
        Serial.print("Sensor ");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(sensorValues[i]);
        Serial.print("   ");
      }
      Serial.println();
    }
      displayStatus();
} 
