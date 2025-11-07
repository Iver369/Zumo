#ifndef OBSTACLE_H
#define OBSTACLE_H

class UltraSonicSensor {
public:
    void init(int trigPin, int echoPin, float threshold);
    void readDistance();
    bool isObstacleNear();
    void averageDistance();
    void printDebug();
private:
    long time();
    // Constants
    const float speedOfSound = 0.0343; // cm/µs
    static const int numReadings = 5;
    // Configuration Data
    int trigPin;
    int echoPin;
    int threshold;
    // Measurement Data
    float distance;
    float readings[numReadings];
    int readIndex;
    int total;
    float average;
};
#endif
