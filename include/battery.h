#ifndef BATTERY_H
#define BATTERY_H
#include <Arduino.h>

int battery_calculator(float deltaTime);
float remaining_distance();
void checkBatteryState();
void chargeBattery();
void stopCarIfEmpty();

#endif