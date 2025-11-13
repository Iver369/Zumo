#include "line_follow.h"
#include "globals.h"

void linefollow() {
  lineSensors.initFiveSensors();
  int pos = lineSensors.readLine(sensorValues);

  int error = pos - 2000;

  float Kp = 0.2;          // Øk for skarpere svinger (0.2 - 0.4)
  int correction = error * Kp;

  int baseSpeed = 100;
  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  -200, 200);
  rightSpeed = constrain(rightSpeed, -200, 200);

  motors.setSpeeds(leftSpeed, rightSpeed);


}