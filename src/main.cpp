#include <Arduino.h>
#include "eksempel.h"

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  eksempelfunksjon();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:

