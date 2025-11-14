#include "globals.h" 
#include "battery.h" 
#include "calibrate.h"
#include "display.h" 
#include "line_follow.h"
#include "obstacle.h"

int offset = 0;
// UltraSonicSensor sensor;

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  // sensor.init(12, 11, 20.0); // Example pins and threshold
  // Initialize shared line sensor object and motors (defined in globals.cpp)
  lineSensors.initFiveSensors(); // Initialize all five line sensors
  calibrateLineSensors(lineSensors, motors, 5000); // Calibrate for 5 secondss
  Serial.println("Calibration complete."); // Indicate completion
  displayStartup(); // Show startup messages
}

void loop() {
  displayStatus();
  static unsigned long lastUpdate = 0;
  unsigned long now = millis();
  if (now - lastUpdate >= 500) {
    float deltaTime = (now - lastUpdate) / 1000.0;
    lastUpdate = now;
    battery_calculator(deltaTime); 
    checkBatteryState(); 
  } 

  /*sensor.readDistance();
  sensor.averageDistance();
  sensor.printDebug();
  if (sensor.isObstacleNear()) {
    Serial.println("Obstacle detected! Stopping motors.");
    motors.setSpeeds(0, 0); // Stop motors if obstacle is near
  } else */

  linefollow();
  Serial.print("Offset: ");
  offset = lineSensors.readLine(sensorValues); // Read calibrated values
  Serial.print(offset);
  Serial.println(""); 
  for (int i = 0; i < 5; i++) { // Loop through each sensor
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(sensorValues[i]); // Print each sensor value
    Serial.print("   ");
  }
  Serial.println();
  displayStatus();
  }
