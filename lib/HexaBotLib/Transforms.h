#ifndef HEXAPOGBOT_TRANSFORMS_H
#define HEXAPOGBOT_TRANSFORMS_H

#include "Adafruit_PWMServoDriver.h"
#include "Parameters.h"
#include "InverseKinematics.h"

using namespace BLA;

// Two PWM chips on the board. pwm1 will be 1-16, pwm2 will be 17-32.
// May need I2C initialization with custom pins??
extern Adafruit_PWMServoDriver pwm1;
extern Adafruit_PWMServoDriver pwm2;

/// Defines a movement
struct Transformation {
    Point bodyPosition;
    EulerRotation bodyOrientation;
    Point *startPosition;
    Point *endPosition;
};

void servoSetup();
void setServoAngle(uint8_t servoNum, float angle);
void moveLegs(const Transformation &ts, const int &duration, const int &steps);

#endif //HEXAPOGBOT_TRANSFORMS_H
