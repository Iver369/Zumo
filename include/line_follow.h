#ifndef LINE_FOLLOW_H
#define LINE_FOLLOW_H
#include <Zumo32U4.h>

// Declarations for globals used across source files.
// Definitions (one instance) must live in a single .cpp file.
extern Zumo32U4Motors motors;
extern Zumo32U4LineSensors lineSensors;

extern unsigned int sensorValues[5];

void linefollow();

#endif