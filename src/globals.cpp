// globals.cpp
// Single definitions for globals declared as extern in headers.

#include "line_follow.h"
#include "display.h"

// Definitions
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
unsigned int sensorValues[5];
Zumo32U4LCD lcd;
float battery_cap=100;
const float power=0.005; // kan justeres for hvor fort batteriet skal tømmes
uint16_t threshold = 700;
bool isCharging = false;
unsigned long chargeStartTime = 0;
int baseSpeed = 100;
