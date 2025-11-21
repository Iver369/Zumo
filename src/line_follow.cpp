#include "line_follow.h"
#include "battery.h"
#include "globals.h"

bool turning = false;
unsigned long crossStartTime = 0;
bool crossDetected = false;

int state = 0;

void linefollow(){
  int pos = lineSensors.readLine(sensorValues);

  int error = pos - 2000;

  float Kp = 0.2;          // Øk for skarpere svinger (0.2 - 0.4)
  float correction = error * Kp;

  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  -300, 300);
  rightSpeed = constrain(rightSpeed, -300, 300);

  motors.setSpeeds(leftSpeed, rightSpeed);
}


void crossroads(){
  lineSensors.read(sensorValues);

  if (turning) {
    linefollow();
    return;
  }

  bool leftOuter  = sensorValues[0] > threshold;
  bool rightOuter = sensorValues[4] > threshold;
  bool center = sensorValues[2] > threshold;

  bool leftCross = (leftOuter && center);
  bool rightCross = (rightOuter && center);


  if(state == 0) {
    if(battery_cap < 20) {
      state = 1;
    }

    if((leftCross || rightCross) && state == 0){
      motors.setSpeeds(baseSpeed, baseSpeed);
      delay(200);
      return;
      linefollow();
    }

    linefollow();
    return;
  }

  if(state == 1){
    if(leftCross) {
      motors.setSpeeds(0,0);
      delay(100);
      motors.setSpeeds(-50, 200);
      delay(700);
      state = 2;
      if(leftCross) {
        motors.setSpeeds(0,0);
        delay(100);
        motors.setSpeeds(-50, 200);
        delay(700);
        stopCarIfEmpty();
        state = 2;
        return;
      }
      else if(rightCross){
        motors.setSpeeds(0,0);
        delay(100);
        motors.setSpeeds(200, -50);
        delay(700);
        stopCarIfEmpty();
        state = 2;
        return;
      }
    }

    else if(rightCross){
      motors.setSpeeds(0,0);
      delay(100);
      motors.setSpeeds(200, -50);
      delay(700);
      state = 2;
      if(leftCross){
        motors.setSpeeds(0,0);
        delay(100);
        motors.setSpeeds(-50, 200);
        delay(700);
        stopCarIfEmpty();
        state = 2;
        return;
      }
      else if(rightCross){
        motors.setSpeeds(0,0);
        delay(100);
        motors.setSpeeds(200, -50);
        delay(700);
        stopCarIfEmpty();
        state = 2;
        return;
      }
    }
    linefollow();
    return;
  }

  if(state == 2) {
    motors.setSpeeds(0,0);
    chargeBattery();
    state = 3;
  }

  if(state == 3) {

    if(leftCross) {
      motors.setSpeeds(0,0);
      delay(100);
      motors.setSpeeds(-50, 200);
      delay(700);
      state = 0;
      return;
    }

    if(rightCross) {
      motors.setSpeeds(0,0);
      delay(100);
      motors.setSpeeds(200, -50);
      delay(700);
      state = 0;
      return;
    }
  }
}