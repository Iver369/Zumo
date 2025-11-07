#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrate.h"
#include "line_follow.h"
#include "battery.h"
#include "display.h"
#include "obstacle.h"

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  // Initialize shared line sensor object and motors (defined in globals.cpp)
  lineSensors.initFiveSensors(); // Initialize all five line sensors
  calibrateLineSensors(lineSensors, motors, 5000); // Calibrate for 5 seconds
  Serial.println("Calibration complete."); // Indicate completion
  display();



  }


void loop() {
  Serial.println("----------");
  lineSensors.readCalibrated(sensorValues); // Read calibrated values
    for (int i = 0; i < 5; i++) { // Loop through each sensor
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print (sensorValues[i]); // Print each sensor value
    Serial.print ("   ");
}}


