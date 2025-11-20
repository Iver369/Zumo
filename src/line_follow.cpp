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
    if((leftCross || rightCross) && state == 0){
      motors.setSpeeds(baseSpeed, baseSpeed);
      delay(200);
      return;
      linefollow();
    }
    if(battery_cap < 20) {
      state = 1;
    }

    if(leftCross) {
      turnLeft();         
      motors.setSpeeds(0,0);
      delay(300);
      state = 2;       
      return;
    }

    if(rightCross) {
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

  motors.setSpeeds(120, -120);
  delay(320);

  motors.setSpeeds(100, 100);
  delay(150);

  int pos = lineSensors.readLine(sensorValues);
  while(pos > 2500 || pos < 1500) {
    motors.setSpeeds(80, 80);
    pos = lineSensors.readLine(sensorValues);
  }

  motors.setSpeeds(0,0);
  delay(100);
}

void turnLeft() {
  motors.setSpeeds(0, 0);
  delay(100);

  motors.setSpeeds(-120, 120);
  delay(320);

  motors.setSpeeds(100, 100);
  delay(150);

  int pos = lineSensors.readLine(sensorValues);
  while(pos > 2500 || pos < 1500) {
    motors.setSpeeds(80, 80);
    pos = lineSensors.readLine(sensorValues);
  }

  motors.setSpeeds(0,0);
  delay(100);
}