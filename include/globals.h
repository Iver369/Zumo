// globals.h
#pragma once
#include <Zumo32U4.h>

extern Zumo32U4Motors motors;
extern Zumo32U4LineSensors lineSensors;
extern Zumo32U4OLED display;
extern unsigned int sensorValues[5];
extern float battery_cap;
extern const float power;
extern uint16_t threshold;
extern int baseSpeed;
extern bool isCharging;
extern unsigned long chargeStartTime;