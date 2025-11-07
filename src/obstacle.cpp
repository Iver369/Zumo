#include "obstacle.h"
#include <Arduino.h>  // for pinMode, digitalWrite, pulseIn, Serial

void UltraSonicSensor::init(int trigPin, int echoPin, float threshold) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->threshold = threshold;
    // In main.cpp write with actual values for the parameters sensor.init(trigPin, echoPin, threshold); after UltraSonicSensor sensor;
    Serial.println("Ultrasonic sensor initialized.");
}

float UltraSonicSensor::readDistance() {
    // Pulse Trigger Pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Read Echo Pin
    long pulsetime = pulseIn(echoPin, HIGH);
    // Calculate Distance
    distance = (pulsetime * speedOfSound) / 2; // in cm
    return distance;
}

void UltraSonicSensor::averageDistance() {
    total = 0;
    readings[readIndex] = distance;
    readIndex = (readIndex + 1) % numReadings;
    for (int i = 0; i < numReadings; i++) {
        total = readings[i] + total;
    }
    average = total / numReadings;
}

void UltraSonicSensor::printDebug() {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
}

bool UltraSonicSensor::isObstacleNear() {
    if (distance <= threshold) {
        return true;
    }
    else {
        return false;
    }
}