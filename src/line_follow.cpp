#include "line_follow.h"

void crossroads() {
  lineSensors.read(sensorValues);

  uint16_t leftOuter  = sensorValues[0];
  uint16_t leftInner  = sensorValues[1];
  uint16_t rightInner = sensorValues[3];
  uint16_t rightOuter = sensorValues[4];

  bool leftSeen = leftOuter > threshold;
  bool rightSeen = rightOuter > threshold;
  bool centerSeen = sensorValues[2] > threshold;


  if(leftSeen && rightSeen && centerSeen){
    turnRight();
  }
  else if (leftSeen && !rightSeen) {
    turnLeft();
  }
  else{ 
    linefollow();
  }
} 

void linefollow(){
  int pos = lineSensors.readLine(sensorValues);

  int error = pos - 2000;

  float Kp = 0.2;          // Øk for skarpere svinger (0.2 - 0.4)
  float correction = error * Kp;

  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  -200, 200);
  rightSpeed = constrain(rightSpeed, -200, 200);

  motors.setSpeeds(leftSpeed, rightSpeed);
}

void turnRight() {
  motors.setSpeeds(0, 0);
  delay(100);

  motors.setSpeeds(100, -100);
  delay(300);

  int pos = lineSensors.readLine(sensorValues);
  while (pos < 1800 || pos > 2200) {
    motors.setSpeeds(100, -100);
    pos = lineSensors.readLine(sensorValues);
  }

  motors.setSpeeds(baseSpeed, baseSpeed);
  delay(200);
}

void turnLeft() {
  motors.setSpeeds(0, 0);
  delay(100);

  motors.setSpeeds(-100, 100);
  delay(300);

  int pos = lineSensors.readLine(sensorValues);
  while (pos < 1800 || pos > 2200) {
    motors.setSpeeds(-100, 100);
    pos = lineSensors.readLine(sensorValues);
  }

  motors.setSpeeds(baseSpeed, baseSpeed);
  delay(200);
}