#include <Arduino.h>
#include "eksempel.h"

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  eksempelfunksjon();

  while (millis() - startTime < waitTime) {
    motors.setSpeeds(200, -200)
    linesensor.calibrate();
}
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:

