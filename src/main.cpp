#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrate.h"

Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensor;

void setup() {
  Serial.begin(9600);
  while(!Serial); // Wait for Serial to be ready
  lineSensor.initFiveSensors();
  calibrateLineSensors(lineSensor, motors, 5000); // Calibrate for 5 seconds
  Serial.println("Calibration complete.");


}

void loop() {
}


