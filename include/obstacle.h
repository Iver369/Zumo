#ifndef OBSTACLE_H
#define OBSTACLE_H

class UltraSonicSensor {
public:
    void init(int trigPin, int echoPin, float threshold);
    float readDistance();
    bool isObstacleNear();
    void averageDistance();
    void printDebug();

private:
    // Configuration Data
    int trigPin;
    int echoPin;
    float distance;
    // Constants
    float speedOfSound = 0.0343; // cm/µs
    static const int numReadings = 5;
    // Measurement Data
    float readings[numReadings];
    int readIndex;
    float total;
    float average;
    int threshold;
};

#endif
