#include "line_follow.h"


void linefollow() {
  lineSensors.initFiveSensors();
  int pos = lineSensors.readLine(sensorValues);

  int error = pos - 2000;

  float Kp = 0.15;          // Øk for skarpere svinger (0.2 - 0.4)
  int correction = error * Kp;

  int baseSpeed = 50;
  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  -100, 100);
  rightSpeed = constrain(rightSpeed, -100, 100);

  motors.setSpeeds(leftSpeed, rightSpeed);


}