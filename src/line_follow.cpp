void setup() {
  lineSensors.initFiveSensors();
  delay(1000);
}

void loop() {
  int pos = lineSensors.readLine(sensorValues);

  int error = pos - 2000;

  float Kp = 0.15;          // Øk for skarpere svinger (0.2 - 0.4)
  int correction = error * Kp;

  int baseSpeed = 200;
  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  -400, 400);
  rightSpeed = constrain(rightSpeed, -400, 400);

  if (buttonA.isPressed()) {
    motors.setSpeeds(leftSpeed, rightSpeed);
  }
}