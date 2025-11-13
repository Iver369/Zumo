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
  sensor.init(12, 11, 20.0); // Example pins and threshold
  displayStartup();
  // Initialize shared line sensor object and motors (defined in globals.cpp)
  lineSensors.initFiveSensors(); // Initialize all five line sensors
  calibrateLineSensors(lineSensors, motors, 5000); // Calibrate for 5 seconds
  lineSensors.readCalibrated(sensorValues); // Read calibrated values once
  Serial.println("Calibrated sensor values:");
  Serial.println(sensorValues[2]); // Print center sensor value
  Serial.println("Calibration complete."); // Indicate completion
}

void loop() {
  // displayStatus();
  static unsigned long lastUpdate = 0;
  unsigned long now = millis();
  float deltaTime = (now - lastUpdate) / 1000.0; // seconds
  lastUpdate = now;
  battery_calculator(deltaTime); 
  checkBatteryState();

  sensor.readDistance();
  sensor.averageDistance();
  sensor.printDebug();
  /*if (sensor.isObstacleNear()) {
    Serial.println("Obstacle detected! Stopping motors.");
    motors.setSpeeds(0, 0); // Stop motors if obstacle is near
  } else {*/

  linefollow();
  crossroads();
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
  }
