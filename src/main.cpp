#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrate.h"
#include "line_follow.h"
#include "battery.h"
#include "display.h"
#include "obstacle.h"

Zumo32U4Motors motors; // Create motors object
Zumo32U4LineSensors lineSensor; // Create line sensors object

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  lineSensor.initFiveSensors(); // Initialize all five line sensors
  calibrateLineSensors(lineSensor, motors, 5000); // Calibrate for 5 seconds
  Serial.println("Calibration complete."); // Indicate completion
  lineSensor.readCalibrated(sensorValues); // Read calibrated values

  for (int i = 0; i < 5; i++) {
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(sensorValues[i]); // Print each sensor value
  }
}

void loop() {

}


