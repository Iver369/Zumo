#include "line_follow.h"
#include "globals.h"

void linefollow() {

  uint16_t leftOuter  = lineSensorValues[0];
  uint16_t leftInner  = lineSensorValues[1];
  uint16_t rightInner = lineSensorValues[3];
  uint16_t rightOuter = lineSensorValues[4];

  bool leftSeen = leftOuter > threshold || leftInner > threshold;
  bool rightSeen = rightOuter > threshold || rightInner > threshold;

  if(leftSeen && rightSeen){
    turnRight()
  }
  else{ 

  lineSensors.initFiveSensors();
  int pos = lineSensors.readLine(sensorValues);

  int error = pos - 2000;

  float Kp = 0.2;          // Øk for skarpere svinger (0.2 - 0.4)
  int correction = error * Kp;

  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  -200, 200);
  rightSpeed = constrain(rightSpeed, -200, 200);

  motors.setSpeeds(leftSpeed, rightSpeed);
  }
}

void turnRight() {
  motors.setSpeeds(0, 0);
  delay(100);

  motors.setSpeeds(150, -150);
  delay(400);

  motors.setSpeeds(baseSpeed, baseSpeed);
  delay(200);
}