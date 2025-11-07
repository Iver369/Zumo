#include "calibrate.h"

void calibrateLineSensors(Zumo32U4LineSensors &lineSensors, Zumo32U4Motors &motors, unsigned long waitTime) {
  unsigned long startTime = millis(); // Get the start time
  while (millis() - startTime < waitTime) {
    motors.setSpeeds(200, -200); // Rotate in place
    lineSensors.calibrate(); // Calibrate the line sensors
  }
  motors.setSpeeds(0, 0); // Stop the motors after calibration
}