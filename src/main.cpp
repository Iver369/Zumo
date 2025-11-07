#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrate.h"

Zumo32U4Motors motors; // Create motors object
Zumo32U4LineSensors lineSensor; // Create line sensors object

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  lineSensor.initFiveSensors(); // Initialize all five line sensors
  calibrateLineSensors(lineSensor, motors, 5000); // Calibrate for 5 seconds
  Serial.println("Calibration complete."); // Indicate completion
}

void loop() {

}


