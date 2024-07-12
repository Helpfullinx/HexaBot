#include "main.h"

void setup() {
    Serial.begin(115200);
    while(!Serial.available());

    Serial.println("Initializing servos...");

    servoSetup();

}

void loop() {
    Point bodyPos = {0, 0, 0};
    EulerRotation bodyOrientation = {0, 0, 0};

    Point startPositions[LEG_COUNT] = {
            {100, 100, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    Point endPositions[LEG_COUNT] = {
            {150, 150, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    Transformation t = {
            bodyPos,
            bodyOrientation,
            startPositions,
            endPositions
    };

    moveLegs(t, 2000, 50);

}