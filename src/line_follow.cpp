#include "line_follow.h"
#include "battery.h"
#include "globals.h"

int state = 0;

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


void crossroads(){
  lineSensors.read(sensorValues);

  bool leftOuter  = sensorValues[0] > threshold;
  bool rightOuter = sensorValues[4] > threshold;
  bool center = sensorValues[2] > threshold;

  bool leftCross = (leftOuter && center);
  bool rightCross = (rightOuter && center);


  if(state == 0) {
    if(leftCross || rightCross){
      motors.setSpeeds(baseSpeed, baseSpeed);
    }
    if(battery_cap < 15) {
      state = 1;
    }

      if(state == 1 && leftCross) {
        turnLeft();         
        motors.setSpeeds(0,0);
        delay(300);
        state = 2;       
        return;
      }

      if(state == 1 && rightCross) {
        turnRight();        
        motors.setSpeeds(0,0);
        delay(300);
        state = 2;     
        return;
      }
    linefollow();
    return;
  }

  if(state == 2) {
    motors.setSpeeds(0,0);
    chargeBattery();

  if(state == 3) {

    if(leftCross) {
      turnLeft();
      motors.setSpeeds(baseSpeed, baseSpeed);
      delay(200);
      state = 0;
      return;
    }

    if(rightCross) {
      turnRight();       
      motors.setSpeeds(baseSpeed, baseSpeed);
      delay(200);
      state = 0;          
      return;
    }

    linefollow();
    return;
  }
}
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