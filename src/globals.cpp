// globals.cpp
// Single definitions for globals declared as extern in headers.

#include "line_follow.h"
#include "display.h"

// Definitions
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
unsigned int sensorValues[5];
Zumo32U4LCD lcd;
int battery_cap=100;
const float power=0.5; // kan justeres for hvor fort batteriet skal tømmes
uint16_t threshold = 500;
int baseSpeed = 100;
