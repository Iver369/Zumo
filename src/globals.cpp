// globals.cpp
// Single definitions for globals declared as extern in headers.

#include <Zumo32U4.h>
#include "line_follow.h"
#include "display.h"

// Definitions
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
unsigned int sensorValues[5];
Zumo32U4LCD lcd;
