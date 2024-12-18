#include "main.h"

uint8_t servonum = 1;

void setup() {
    Serial.begin(115200);
    while(!Serial.available());

    Serial.println("Initializing servos...");

    servoSetup();

    delay(1000);
}

void loop() {
    Point startPositions[LEG_COUNT] = {
            {200, 250, 150},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    Point endPositions[LEG_COUNT] = {
            {80, 250, 150},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    Point bodyPos = {0, 0, 0};
    EulerRotation bodyOrientation = {0, 0, 0};

    Transformation t = {
            bodyPos,
            bodyOrientation,
            startPositions,
            endPositions
    };

    int moveDuration = 100;

    moveLegs(t, moveDuration, 100);

    t.startPosition[0] = {80, 250, 150};
    t.endPosition[0] = {165, 250, 60};

    moveLegs(t, moveDuration, 100);

    t.startPosition[0] = {165, 250, 60};
    t.endPosition[0] = {200, 250, 150};

    moveLegs(t, moveDuration, 100);
}